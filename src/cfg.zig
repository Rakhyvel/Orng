const std = @import("std");
const ast_ = @import("ast.zig");
const basic_block_ = @import("basic-block.zig");
const errs = @import("errors.zig");
const ir_ = @import("ir.zig");
const lval_ = @import("lval.zig");
const module_ = @import("module.zig");
const primitives_ = @import("primitives.zig");
const span_ = @import("span.zig");
const String = @import("zig-string/zig-string.zig").String;
const symbol_ = @import("symbol.zig");
const validate_ = @import("validate.zig");

pub const CFG = struct {
    /// Temporary, flat instruction list before the BBs are created
    ir_head: ?*ir_.IR,
    ir_tail: ?*ir_.IR,

    /// Initial basic block in the basic block graph
    block_graph_head: ?*basic_block_.Basic_Block,

    /// Flat list of all basic blocks
    basic_blocks: std.ArrayList(*basic_block_.Basic_Block),

    /// All other functions called by this function
    children: std.ArrayList(*CFG),

    /// All symbol versions that are parameters to the function this CFG defines
    parameters: std.ArrayList(*lval_.Symbol_Version),

    /// All symbol versions that are used. Should be filled in after optimizations.
    symbvers: std.ArrayList(*lval_.Symbol_Version),

    /// The function that this CFG represents
    symbol: *symbol_.Symbol,

    number_temps: usize,

    return_symbol: *symbol_.Symbol,

    /// Non-owning pointer to set of interned string literals
    /// Provided by main, global to all CFGs.
    interned_strings: *std.ArrayList([]const u8),

    /// Whether or not this CFG is visited
    visited: bool,

    /// Address in the first instruction of this CFG
    /// Used for IR interpretation
    offset: ?i64,
    /// Number of bytes required in order to store the local variables of the function
    locals_size: ?i64,

    allocator: std.mem.Allocator,

    // BIG TODO: Dependency-inject errors and allocator, so that method calls don't need that explicit passed in (they do not change from method call to method call)
    pub fn create(symbol: *symbol_.Symbol, caller: ?*CFG, interned_strings: *std.ArrayList([]const u8), errors: *errs.Errors, allocator: std.mem.Allocator) !*CFG {
        if (symbol.cfg) |cfg| {
            return cfg;
        }
        var retval = try allocator.create(CFG);
        retval.ir_head = null;
        retval.ir_tail = null;
        retval.block_graph_head = null;
        retval.basic_blocks = std.ArrayList(*basic_block_.Basic_Block).init(allocator);
        retval.children = std.ArrayList(*CFG).init(allocator);
        retval.symbvers = std.ArrayList(*lval_.Symbol_Version).init(allocator);
        retval.parameters = std.ArrayList(*lval_.Symbol_Version).init(allocator);
        retval.symbol = symbol;
        retval.number_temps = 0;
        retval.return_symbol = try symbol_.Symbol.create(symbol.scope, "$retval", span_.Span{ .filename = "", .line_text = "", .col = 0, .line = 0 }, symbol._type.function.rhs, ast_.poisoned, null, .mut, allocator);
        retval.return_symbol.expanded_type = try retval.return_symbol._type.expand_type(symbol.scope, errors, allocator);
        retval.visited = false;
        retval.interned_strings = interned_strings;
        retval.offset = null;
        retval.locals_size = null;
        retval.allocator = allocator;
        symbol.cfg = retval;

        if (caller) |caller_node| {
            try caller_node.children.append(retval);
        }

        const eval: ?*lval_.L_Value = try retval.flattenAST(symbol.scope, symbol.init, null, null, null, null, errors, allocator);
        if (retval.symbol.decl.?.* == .fnDecl) {
            // `_comptime` symbols don't have parameters anyway
            for (retval.symbol.decl.?.fnDecl.param_symbols.items) |param| {
                try retval.parameters.append(try lval_.Symbol_Version.createUnversioned(param, allocator));
            }
        }
        const return_version = try lval_.L_Value.create_unversioned_symbver(retval.return_symbol, allocator);
        if (eval != null) {
            retval.appendInstruction(try ir_.IR.create_simple_copy(return_version, eval.?, symbol.span, allocator));
        }
        retval.appendInstruction(try ir_.IR.createJump(null, symbol.span, allocator));

        retval.block_graph_head = try retval.basicBlockFromIR(retval.ir_head, allocator);
        retval.removeBasicBlockLastInstruction();

        // for (retval.basic_blocks.items) |bb| {
        //     bb.pprint();
        // }
        // retval.clearVisitedBBs();

        try retval.calculatePhiParamsAndArgs(allocator);

        return retval;
    }

    pub fn deinit(self: *CFG) void {
        for (self.basic_blocks.items) |bb| {
            bb.deinit();
        }
        self.basic_blocks.deinit();

        self.symbvers.deinit();

        for (self.parameters.items) |param| {
            param.deinit();
        }
        self.parameters.deinit();

        self.allocator.destroy(self);
    }

    // BBs aren't trees, so `defer self.visited = false` won't work
    // Use this function instead
    pub fn clearVisitedBBs(self: *CFG) void {
        for (self.basic_blocks.items) |bb| {
            bb.visited = false;
        }
    }

    pub fn clearVisited(self: *CFG) void {
        self.visited = false;
        for (self.children.items) |child| {
            if (child.visited) {
                child.clearVisited();
            }
        }
    }

    // Fills in a passed in list with symbol versions which are used in the CFG
    pub fn collect_generated_symbvers(self: *CFG) !void {
        for (self.basic_blocks.items) |bb| {
            var maybe_ir = bb.ir_head;
            while (maybe_ir) |ir| : (maybe_ir = ir.next) {
                if (ir.dest != null and
                    ir.dest.?.* == .symbver and
                    ir.dest.?.symbver.findSymbolVersionSet(&self.parameters) == null)
                {
                    _ = try ir.dest.?.symbver.putSymbolVersionSet(&self.symbvers);
                }
            }
        }
    }

    fn createTempSymbol(self: *CFG, _type: *ast_.AST, errors: *errs.Errors, allocator: std.mem.Allocator) !*symbol_.Symbol {
        var buf = try String.init_with_contents(allocator, "t");
        try buf.writer().print("{}", .{self.number_temps});
        self.number_temps += 1;
        var temp_symbol = try symbol_.Symbol.create(self.symbol.scope, (try buf.toOwned()).?, span_.Span{ .filename = "", .line_text = "", .line = 0, .col = 0 }, _type, ast_.poisoned, null, .mut, allocator);
        temp_symbol.expanded_type = try _type.expand_type(self.symbol.scope, errors, allocator);
        temp_symbol.is_temp = true;
        return temp_symbol;
    }

    fn createTempSymbolVersion(self: *CFG, _type: *ast_.AST, errors: *errs.Errors, allocator: std.mem.Allocator) !*lval_.Symbol_Version {
        const temp_symbol = try self.createTempSymbol(_type, errors, allocator);
        const retval = try lval_.Symbol_Version.createUnversioned(temp_symbol, _type, allocator);
        return retval;
    }

    fn create_temp_lvalue(self: *CFG, _type: *ast_.AST, errors: *errs.Errors, allocator: std.mem.Allocator) !*lval_.L_Value {
        const temp_symbol = try self.createTempSymbol(_type, errors, allocator);
        const retval = try lval_.L_Value.create_unversioned_symbver(temp_symbol, allocator);
        return retval;
    }

    fn appendInstruction(self: *CFG, ir: *ir_.IR) void {
        if (self.ir_head == null) {
            self.ir_head = ir;
        } else if (self.ir_tail == null) {
            self.ir_head.?.next = ir;
            self.ir_tail = ir;
            self.ir_tail.?.prev = self.ir_head;
        } else {
            self.ir_tail.?.next = ir;
            ir.prev = self.ir_tail;
            self.ir_tail = ir;
        }
    }

    const FlattenASTError = error{
        typeError,
        OutOfMemory,
        NotAnLValue,
        Unimplemented,
        InvalidRange,
        interpreter_panic,
        // Utf8ExpectedContinuation,
        // Utf8OverlongEncoding,
        // Utf8EncodesSurrogateHalf,
        // Utf8CodepointTooLarge,
    };

    fn flattenAST(
        self: *CFG,
        scope: *symbol_.Scope,
        ast: *ast_.AST,
        return_label: ?*ir_.IR,
        break_label: ?*ir_.IR,
        continue_label: ?*ir_.IR,
        error_label: ?*ir_.IR,
        errors: *errs.Errors,
        allocator: std.mem.Allocator,
    ) FlattenASTError!?*lval_.L_Value {
        switch (ast.*) {
            // Literals
            .unit_type => {
                const lval = try self.create_temp_lvalue(ast, errors, allocator);
                self.appendInstruction(try ir_.IR.create_ast(lval, ast, ast.getToken().span, allocator));
                return lval;
            },
            .unit_value => {
                const lval = try self.create_temp_lvalue(primitives_.unit_type, errors, allocator);
                self.appendInstruction(try ir_.IR.create(.loadUnit, lval, null, null, ast.getToken().span, allocator));
                return lval;
            },
            .int => {
                const temp = try self.create_temp_lvalue(try ast.typeof(scope, errors, allocator), errors, allocator);
                const ir = try ir_.IR.createInt(temp, ast.int.data, ast.getToken().span, allocator);
                // temp.def = ir;
                self.appendInstruction(ir);
                return temp;
            },
            .char => {
                const temp = try self.create_temp_lvalue(try ast.typeof(scope, errors, allocator), errors, allocator);
                // Convert the character inside to a codepoint
                var codepoint: u21 = undefined;
                switch (ast.getToken().data[1]) {
                    '\\' => switch (ast.getToken().data[2]) {
                        'n' => codepoint = 0x0A,
                        'r' => codepoint = 0x0D,
                        't' => codepoint = 0x09,
                        '\\' => codepoint = 0x5C,
                        '\'' => codepoint = 0x27,
                        '"' => codepoint = 0x22,
                        else => unreachable,
                    },
                    else => {
                        const num_bytes = std.unicode.utf8ByteSequenceLength(ast.getToken().data[1]) catch return error.typeError;
                        codepoint = std.unicode.utf8Decode(ast.getToken().data[1 .. num_bytes + 1]) catch return error.typeError; // TODO: Add actual error diagnostics here
                    },
                }
                const ir = try ir_.IR.createInt(temp, codepoint, ast.getToken().span, allocator);
                self.appendInstruction(ir);
                return temp;
            },
            .float => {
                const temp = try self.create_temp_lvalue(try ast.typeof(scope, errors, allocator), errors, allocator);
                const ir = try ir_.IR.createFloat(temp, ast.float.data, ast.getToken().span, allocator);
                self.appendInstruction(ir);
                return temp;
            },
            .string => {
                try module_.interned_string_set_add(ast.string.data, self.interned_strings);
                const temp = try self.create_temp_lvalue(try ast.typeof(scope, errors, allocator), errors, allocator);
                const ir = try ir_.IR.createString(temp, self.interned_strings.items.len - 1, ast.getToken().span, allocator);
                self.appendInstruction(ir);
                return temp;
            },
            .identifier => {
                const res = scope.lookup(ast.getToken().data, false);
                const symbol = switch (res) {
                    .found => res.found,
                    .not_found => {
                        errors.addError(errs.Error{ .undeclaredIdentifier = .{ .identifier = ast.getToken(), .scope = scope, .expected = null } });
                        return error.typeError;
                    },
                    .found_but_rt => {
                        errors.addError(errs.Error{ .comptime_access_runtime = .{ .identifier = ast.getToken() } });
                        return error.typeError;
                    },
                    .found_but_fn => {
                        errors.addError(errs.Error{ .inner_fn_access_runtime = .{ .identifier = ast.getToken() } });
                        return error.typeError;
                    },
                };
                if (symbol.kind == ._fn) {
                    _ = try symbol.get_cfg(self, self.interned_strings, errors, allocator);
                    const lval = try self.create_temp_lvalue(symbol._type, errors, allocator);
                    var ir = try ir_.IR.create(.loadSymbol, lval, null, null, ast.getToken().span, allocator);
                    ir.data = ir_.Data{ .symbol = symbol };
                    self.appendInstruction(ir);
                    return lval;
                } else if (try symbol.expanded_type.?.typesMatch(primitives_.type_type, scope, errors, allocator)) {
                    const lval = try self.create_temp_lvalue(symbol._type, errors, allocator);
                    self.appendInstruction(try ir_.IR.create_ast(lval, ast, ast.getToken().span, allocator));
                    return lval;
                } else if (symbol.kind == ._const) {
                    return try self.flattenAST(scope, symbol.init, return_label, break_label, continue_label, error_label, errors, allocator);
                } else {
                    const src = try lval_.L_Value.create_unversioned_symbver(symbol, allocator);
                    return src;
                }
            },
            .symbol => {
                const symbol = ast.symbol.symbol;
                std.debug.assert(symbol.kind == ._fn); // For returning functions at compile-time!
                _ = try symbol.get_cfg(self, self.interned_strings, errors, allocator);
                const lval = try self.create_temp_lvalue(symbol._type, errors, allocator);
                var ir = try ir_.IR.create(.loadSymbol, lval, null, null, ast.getToken().span, allocator);
                ir.data = ir_.Data{ .symbol = symbol };
                self.appendInstruction(ir);
                return lval;
            },
            ._true => {
                const temp = try self.create_temp_lvalue(try ast.typeof(scope, errors, allocator), errors, allocator);
                const ir = try ir_.IR.createInt(temp, 1, ast.getToken().span, allocator);
                self.appendInstruction(ir);
                return temp;
            },
            ._false => {
                const temp = try self.create_temp_lvalue(try ast.typeof(scope, errors, allocator), errors, allocator);
                const ir = try ir_.IR.createInt(temp, 0, ast.getToken().span, allocator);
                self.appendInstruction(ir);
                return temp;
            },

            // Unary operators
            .not => {
                const expr = try self.flattenAST(scope, ast.not.expr, return_label, break_label, continue_label, error_label, errors, allocator);
                if (expr == null) {
                    return null;
                }
                const temp = try self.create_temp_lvalue(try ast.typeof(scope, errors, allocator), errors, allocator);

                const ir = try ir_.IR.create(.not, temp, expr, null, ast.getToken().span, allocator);
                self.appendInstruction(ir);
                return temp;
            },
            .negate => {
                const expr = try self.flattenAST(scope, ast.negate.expr, return_label, break_label, continue_label, error_label, errors, allocator);
                if (expr == null) {
                    return null;
                }
                var temp = try self.create_temp_lvalue(try ast.typeof(scope, errors, allocator), errors, allocator);

                const ir = try ir_.IR.create(if (try temp.get_type().can_represent_float(scope, errors, allocator)) .negate_float else .negate_int, temp, expr, null, ast.getToken().span, allocator);
                self.appendInstruction(ir);
                return temp;
            },
            .dereference => {
                const expr = try self.flattenAST(scope, ast.dereference.expr, return_label, break_label, continue_label, error_label, errors, allocator);
                if (expr == null) {
                    return null;
                }
                const _type = try ast.typeof(scope, errors, allocator);
                const size = (try _type.expand_type(scope, errors, allocator)).sizeof();
                const temp = try lval_.L_Value.create_dereference(expr.?, size, _type, try _type.expand_type(scope, errors, allocator), allocator);
                return temp;
            },
            ._try => {
                var expr = (try self.flattenAST(scope, ast._try.expr, return_label, break_label, continue_label, error_label, errors, allocator)) orelse return null;

                const end = try ir_.IR.createLabel(self, ast.getToken().span, allocator);
                const err = try ir_.IR.createLabel(self, ast.getToken().span, allocator);

                var expanded_expr_type = try expr.get_type().expand_type(scope, errors, allocator);
                // Trying error sum, runtime check if error, branch to error path
                const condition = try create_temp_lvalue(self, primitives_.word64_type, errors, allocator);
                self.appendInstruction(try ir_.IR.createGetTag(condition, expr, ast.getToken().span, allocator)); // Assumes `ok` tag is zero, `err` tag is nonzero
                self.appendInstruction(try ir_.IR.createBranch(condition, err, ast.getToken().span, allocator));

                // Unwrap the `.ok` value
                const retval_lval = try lval_.L_Value.create_unversioned_symbver(self.return_symbol, allocator);
                self.appendInstruction(try ir_.IR.create_simple_copy(retval_lval, expr, ast.getToken().span, allocator));
                self.appendInstruction(try ir_.IR.createJump(error_label, ast.getToken().span, allocator));

                // Else, store the error in retval, return through error
                self.appendInstruction(err);

                const ok_lval = try lval_.L_Value.create_select(expr, 0, 0, expanded_expr_type.get_ok_type().sizeof(), expanded_expr_type.get_ok_type(), try expanded_expr_type.get_ok_type().expand_type(scope, errors, allocator), null, allocator);
                self.appendInstruction(try ir_.IR.createJump(end, ast.getToken().span, allocator));
                self.appendInstruction(end);

                return ok_lval;
            },
            .discard => {
                var expr = try self.flattenAST(scope, ast.discard.expr, return_label, break_label, continue_label, error_label, errors, allocator);
                if (expr == null) {
                    return null;
                }
                expr.?.extract_symbver().symbol.discard_span = ast.getToken().span;
                const temp = try self.create_temp_lvalue(try ast.typeof(scope, errors, allocator), errors, allocator);

                const ir = try ir_.IR.createDiscard(expr.?, ast.getToken().span, allocator);
                self.appendInstruction(ir);
                return temp;
            },

            // Binary operators
            .assign => {
                const rhs = try self.flattenAST(scope, ast.assign.rhs, return_label, break_label, continue_label, error_label, errors, allocator);
                if (rhs == null) {
                    return null;
                }
                // If product, recursively generate a series of assignments
                // Else, create a *single* copy IR with an L_Value tree
                return try self.generate_assign(scope, ast.assign.lhs, rhs.?, return_label, break_label, continue_label, error_label, errors, allocator);
            },
            ._or => {
                // Create the result symbol and IR
                const symbol = try self.createTempSymbol(try ast.typeof(scope, errors, allocator), errors, allocator);
                const temp = try lval_.L_Value.create_unversioned_symbver(symbol, allocator);

                // Labels used
                const else_label = try ir_.IR.createLabel(self, ast.getToken().span, allocator);
                const end_label = try ir_.IR.createLabel(self, ast.getToken().span, allocator);

                // Test lhs, branch
                const lhs = (try self.flattenAST(scope, ast._or.lhs, return_label, break_label, continue_label, error_label, errors, allocator)) orelse return null;
                const branch = try ir_.IR.createBranch(lhs, else_label, ast.getToken().span, allocator);
                self.appendInstruction(branch);

                // lhs was true, store `true` in temp
                const load_true_lval = try lval_.L_Value.create_unversioned_symbver(symbol, allocator);
                const load_true = try ir_.IR.createInt(load_true_lval, 1, ast.getToken().span, allocator);
                self.appendInstruction(load_true);
                self.appendInstruction(try ir_.IR.createJump(end_label, ast.getToken().span, allocator));

                // lhs was false, recurse to rhs, store in temp
                self.appendInstruction(else_label);
                const rhs = try self.flattenAST(scope, ast._or.rhs, return_label, break_label, continue_label, error_label, errors, allocator);
                if (rhs == null) {
                    return null;
                }
                const copy_right_lval = try lval_.L_Value.create_unversioned_symbver(symbol, allocator);
                const copy_right = try ir_.IR.create_simple_copy(copy_right_lval, rhs.?, ast.getToken().span, allocator);
                self.appendInstruction(copy_right);
                self.appendInstruction(try ir_.IR.createJump(end_label, ast.getToken().span, allocator));
                self.appendInstruction(end_label);
                return temp;
            },
            ._and => {
                // Create the result symbol and IR
                const symbol = try self.createTempSymbol(try ast.typeof(scope, errors, allocator), errors, allocator);
                const temp = try lval_.L_Value.create_unversioned_symbver(symbol, allocator);

                // Labels used
                const else_label = try ir_.IR.createLabel(self, ast.getToken().span, allocator);
                const end_label = try ir_.IR.createLabel(self, ast.getToken().span, allocator);

                // Test lhs, branch
                const lhs = (try self.flattenAST(scope, ast._and.lhs, return_label, break_label, continue_label, error_label, errors, allocator)) orelse return null;
                const branch = try ir_.IR.createBranch(lhs, else_label, ast.getToken().span, allocator);
                self.appendInstruction(branch);

                // lhs was true, recurse to rhs, store in temp
                const rhs = try self.flattenAST(scope, ast._and.rhs, return_label, break_label, continue_label, error_label, errors, allocator);
                if (rhs == null) {
                    return null;
                }
                const copy_right_lval = try lval_.L_Value.create_unversioned_symbver(symbol, allocator);
                const copy_right = try ir_.IR.create_simple_copy(copy_right_lval, rhs.?, ast.getToken().span, allocator);
                self.appendInstruction(copy_right);
                self.appendInstruction(try ir_.IR.createJump(end_label, ast.getToken().span, allocator));

                // lhs was false, store `false` in temp
                self.appendInstruction(else_label);
                const load_false_lval = try lval_.L_Value.create_unversioned_symbver(symbol, allocator);
                const load_false = try ir_.IR.createInt(load_false_lval, 0, ast.getToken().span, allocator);
                self.appendInstruction(load_false);
                self.appendInstruction(try ir_.IR.createJump(end_label, ast.getToken().span, allocator));
                self.appendInstruction(end_label);
                return temp;
            },
            .add => {
                const lhs = try self.flattenAST(scope, ast.add.lhs, return_label, break_label, continue_label, error_label, errors, allocator);
                const rhs = try self.flattenAST(scope, ast.add.rhs, return_label, break_label, continue_label, error_label, errors, allocator);
                if (lhs == null or rhs == null) {
                    return null;
                }
                const temp = try self.create_temp_lvalue(try ast.typeof(scope, errors, allocator), errors, allocator);

                const ir = try ir_.IR.create_int_float_kind(.add_int, .add_float, temp, lhs, rhs, ast.getToken().span, scope, errors, allocator);
                self.appendInstruction(ir);
                return temp;
            },
            .sub => {
                const lhs = try self.flattenAST(scope, ast.sub.lhs, return_label, break_label, continue_label, error_label, errors, allocator);
                const rhs = try self.flattenAST(scope, ast.sub.rhs, return_label, break_label, continue_label, error_label, errors, allocator);
                if (lhs == null or rhs == null) {
                    return null;
                }
                const temp = try self.create_temp_lvalue(try ast.typeof(scope, errors, allocator), errors, allocator);

                const ir = try ir_.IR.create_int_float_kind(.sub_int, .sub_float, temp, lhs, rhs, ast.getToken().span, scope, errors, allocator);
                self.appendInstruction(ir);
                return temp;
            },
            .mult => {
                const lhs = try self.flattenAST(scope, ast.mult.lhs, return_label, break_label, continue_label, error_label, errors, allocator);
                const rhs = try self.flattenAST(scope, ast.mult.rhs, return_label, break_label, continue_label, error_label, errors, allocator);
                if (lhs == null or rhs == null) {
                    return null;
                }
                const temp = try self.create_temp_lvalue(try ast.typeof(scope, errors, allocator), errors, allocator);

                const ir = try ir_.IR.create_int_float_kind(.mult_int, .mult_float, temp, lhs, rhs, ast.getToken().span, scope, errors, allocator);
                self.appendInstruction(ir);
                return temp;
            },
            .div => {
                const lhs = try self.flattenAST(scope, ast.div.lhs, return_label, break_label, continue_label, error_label, errors, allocator);
                const rhs = try self.flattenAST(scope, ast.div.rhs, return_label, break_label, continue_label, error_label, errors, allocator);
                if (lhs == null or rhs == null) {
                    return null;
                }
                const temp = try self.create_temp_lvalue(try ast.typeof(scope, errors, allocator), errors, allocator);

                const ir = try ir_.IR.create_int_float_kind(.div_int, .div_float, temp, lhs, rhs, ast.getToken().span, scope, errors, allocator);
                self.appendInstruction(ir);
                return temp;
            },
            .mod => {
                const lhs = try self.flattenAST(scope, ast.mod.lhs, return_label, break_label, continue_label, error_label, errors, allocator);
                const rhs = try self.flattenAST(scope, ast.mod.rhs, return_label, break_label, continue_label, error_label, errors, allocator);
                if (lhs == null or rhs == null) {
                    return null;
                }
                const temp = try self.create_temp_lvalue(try ast.typeof(scope, errors, allocator), errors, allocator);

                const ir = try ir_.IR.create(.mod, temp, lhs, rhs, ast.getToken().span, allocator);
                self.appendInstruction(ir);
                return temp;
            },
            .equal => {
                const lhs = try self.flattenAST(scope, ast.equal.lhs, return_label, break_label, continue_label, error_label, errors, allocator);
                const rhs = try self.flattenAST(scope, ast.equal.rhs, return_label, break_label, continue_label, error_label, errors, allocator);
                if (lhs == null or rhs == null) {
                    return null;
                }
                const temp = try self.create_temp_lvalue(try ast.typeof(scope, errors, allocator), errors, allocator);

                // Labels used
                const fail_label = try ir_.IR.createLabel(self, ast.getToken().span, allocator);
                const end_label = try ir_.IR.createLabel(self, ast.getToken().span, allocator);

                try self.generate_tuple_equality(scope, lhs.?, rhs.?, fail_label, errors, allocator);

                self.appendInstruction(try ir_.IR.createInt(temp, 1, ast.getToken().span, allocator));
                self.appendInstruction(try ir_.IR.createJump(end_label, ast.getToken().span, allocator));
                self.appendInstruction(fail_label);
                self.appendInstruction(try ir_.IR.createInt(temp, 0, ast.getToken().span, allocator));
                self.appendInstruction(end_label);

                return temp;
            },
            .not_equal => {
                const lhs = try self.flattenAST(scope, ast.not_equal.lhs, return_label, break_label, continue_label, error_label, errors, allocator);
                const rhs = try self.flattenAST(scope, ast.not_equal.rhs, return_label, break_label, continue_label, error_label, errors, allocator);
                if (lhs == null or rhs == null) {
                    return null;
                }
                const temp = try self.create_temp_lvalue(try ast.typeof(scope, errors, allocator), errors, allocator);

                const lhs_type = try (try ast.not_equal.lhs.typeof(scope, errors, allocator)).expand_type(scope, errors, allocator);
                if (lhs_type.* == .sum) {
                    const lhs_tag = try create_temp_lvalue(self, primitives_.word64_type, errors, allocator);
                    const rhs_tag = try create_temp_lvalue(self, primitives_.word64_type, errors, allocator);
                    self.appendInstruction(try ir_.IR.createGetTag(lhs_tag, lhs.?, ast.getToken().span, allocator));
                    self.appendInstruction(try ir_.IR.createGetTag(rhs_tag, rhs.?, ast.getToken().span, allocator));
                    self.appendInstruction(try ir_.IR.create(.not_equal, temp, lhs_tag, rhs_tag, ast.getToken().span, allocator));
                } else {
                    self.appendInstruction(try ir_.IR.create(.not_equal, temp, lhs, rhs, ast.getToken().span, allocator));
                }
                return temp;
            },
            .greater => {
                const lhs = try self.flattenAST(scope, ast.greater.lhs, return_label, break_label, continue_label, error_label, errors, allocator);
                const rhs = try self.flattenAST(scope, ast.greater.rhs, return_label, break_label, continue_label, error_label, errors, allocator);
                if (lhs == null or rhs == null) {
                    return null;
                }
                const temp = try self.create_temp_lvalue(try ast.typeof(scope, errors, allocator), errors, allocator);

                const ir = try ir_.IR.create_int_float_kind(.greater_int, .greater_float, temp, lhs, rhs, ast.getToken().span, scope, errors, allocator);
                self.appendInstruction(ir);
                return temp;
            },
            .lesser => {
                const lhs = try self.flattenAST(scope, ast.lesser.lhs, return_label, break_label, continue_label, error_label, errors, allocator);
                const rhs = try self.flattenAST(scope, ast.lesser.rhs, return_label, break_label, continue_label, error_label, errors, allocator);
                if (lhs == null or rhs == null) {
                    return null;
                }
                const temp = try self.create_temp_lvalue(try ast.typeof(scope, errors, allocator), errors, allocator);

                const ir = try ir_.IR.create_int_float_kind(.lesser_int, .lesser_float, temp, lhs, rhs, ast.getToken().span, scope, errors, allocator);
                self.appendInstruction(ir);
                return temp;
            },
            .greater_equal => {
                const lhs = try self.flattenAST(scope, ast.greater_equal.lhs, return_label, break_label, continue_label, error_label, errors, allocator);
                const rhs = try self.flattenAST(scope, ast.greater_equal.rhs, return_label, break_label, continue_label, error_label, errors, allocator);
                if (lhs == null or rhs == null) {
                    return null;
                }
                const temp = try self.create_temp_lvalue(try ast.typeof(scope, errors, allocator), errors, allocator);

                const ir = try ir_.IR.create_int_float_kind(.greater_equal_int, .greater_equal_float, temp, lhs, rhs, ast.getToken().span, scope, errors, allocator);
                self.appendInstruction(ir);
                return temp;
            },
            .lesser_equal => {
                const lhs = try self.flattenAST(scope, ast.lesser_equal.lhs, return_label, break_label, continue_label, error_label, errors, allocator);
                const rhs = try self.flattenAST(scope, ast.lesser_equal.rhs, return_label, break_label, continue_label, error_label, errors, allocator);
                if (lhs == null or rhs == null) {
                    return null;
                }
                const temp = try self.create_temp_lvalue(try ast.typeof(scope, errors, allocator), errors, allocator);

                const ir = try ir_.IR.create_int_float_kind(.lesser_equal_int, .lesser_equal_float, temp, lhs, rhs, ast.getToken().span, scope, errors, allocator);
                self.appendInstruction(ir);
                return temp;
            },
            ._catch => {
                // Create the result symbol.
                // There is actually a reason to create a symbol first and not a temp symbol directly. Something to do with versioning. Doesn't work otherwise after optimization.
                const symbol = try self.createTempSymbol(try ast.typeof(scope, errors, allocator), errors, allocator);
                const temp = try lval_.L_Value.create_unversioned_symbver(symbol, allocator); // Not actually assigned directly, just so that optimizations can capture the version

                const lhs = (try self.flattenAST(scope, ast._catch.lhs, return_label, break_label, continue_label, error_label, errors, allocator)) orelse return null;

                // Labels used
                const else_label = try ir_.IR.createLabel(self, ast.getToken().span, allocator);
                const end_label = try ir_.IR.createLabel(self, ast.getToken().span, allocator);

                // Test if lhs tag is 0 (ok)
                const condition = try create_temp_lvalue(self, primitives_.word64_type, errors, allocator);
                self.appendInstruction(try ir_.IR.createGetTag(condition, lhs, ast.getToken().span, allocator)); // Assumes `ok` tag is zero, `err` tag is nonzero
                self.appendInstruction(try ir_.IR.createBranch(condition, else_label, ast.getToken().span, allocator));

                // tag was an error, store rhs in temp
                const rhs = (try self.flattenAST(scope, ast._catch.rhs, return_label, break_label, continue_label, error_label, errors, allocator)) orelse return null;
                const rhs_lval = try lval_.L_Value.create_unversioned_symbver(symbol, allocator);
                self.appendInstruction(try ir_.IR.create_simple_copy(rhs_lval, rhs, ast.getToken().span, allocator));

                self.appendInstruction(try ir_.IR.createJump(end_label, ast.getToken().span, allocator));
                self.appendInstruction(else_label);

                // tag was `.ok`, store lhs.some in temp
                const _type = try ast.typeof(scope, errors, allocator);
                const size = (try _type.expand_type(scope, errors, allocator)).sizeof();
                const val = try lval_.L_Value.create_select(lhs, 0, 0, size, _type, try _type.expand_type(scope, errors, allocator), null, allocator);
                const some_lval = try lval_.L_Value.create_unversioned_symbver(symbol, allocator);
                self.appendInstruction(try ir_.IR.create_simple_copy(some_lval, val, ast.getToken().span, allocator));

                self.appendInstruction(end_label);
                return temp;
            },
            ._orelse => {
                // Create the result symbol.
                // There is actually a reason to create a symbol first and not a temp symbol directly. Something to do with versioning. Doesn't work otherwise after optimization.
                const symbol = try self.createTempSymbol(try ast.typeof(scope, errors, allocator), errors, allocator);
                const temp = try lval_.L_Value.create_unversioned_symbver(symbol, allocator); // Not actually assigned directly, just so that optimizations can capture the version

                var lhs = (try self.flattenAST(scope, ast._orelse.lhs, return_label, break_label, continue_label, error_label, errors, allocator)) orelse return null;

                // Labels used
                const else_label = try ir_.IR.createLabel(self, ast.getToken().span, allocator);
                const end_label = try ir_.IR.createLabel(self, ast.getToken().span, allocator);

                // Test if lhs tag is 1 (some)
                const condition = try create_temp_lvalue(self, primitives_.word64_type, errors, allocator);
                const load_tag = try ir_.IR.createGetTag(condition, lhs, ast.getToken().span, allocator); // Assumes `some` tag is nonzero, `none` tag is zero
                self.appendInstruction(load_tag);

                const branch = try ir_.IR.createBranch(condition, else_label, ast.getToken().span, allocator);
                self.appendInstruction(branch);

                // tag was `.some`, store lhs.some in temp
                const _type = try ast.typeof(scope, errors, allocator);
                const size = (try _type.expand_type(scope, errors, allocator)).sizeof();
                const offset = try (try lhs.get_type().expand_type(scope, errors, allocator)).sum.get_offset(1, scope, errors, allocator);
                const val = try lval_.L_Value.create_select(lhs, 1, offset, size, _type, try _type.expand_type(scope, errors, allocator), null, allocator);
                const some_lval = try lval_.L_Value.create_unversioned_symbver(symbol, allocator);
                self.appendInstruction(try ir_.IR.create_simple_copy(some_lval, val, ast.getToken().span, allocator));
                self.appendInstruction(try ir_.IR.createJump(end_label, ast.getToken().span, allocator));

                self.appendInstruction(else_label);

                // tag was `.none`, store rhs in temp
                const rhs = (try self.flattenAST(scope, ast._orelse.rhs, return_label, break_label, continue_label, error_label, errors, allocator)) orelse return null;

                const rhs_lval = try lval_.L_Value.create_unversioned_symbver(symbol, allocator);
                self.appendInstruction(try ir_.IR.create_simple_copy(rhs_lval, rhs, ast.getToken().span, allocator));

                self.appendInstruction(end_label);
                return temp;
            },
            .call => {
                const lhs = (try self.flattenAST(scope, ast.call.lhs, return_label, break_label, continue_label, error_label, errors, allocator)) orelse return null;
                var temp = try self.create_temp_lvalue(try ast.typeof(scope, errors, allocator), errors, allocator);
                temp.extract_symbver().symbol.span = ast.getToken().span;

                var ir = try ir_.IR.createCall(temp, lhs, ast.getToken().span, allocator);
                for (ast.call.args.items) |term| {
                    try ir.data.lval_list.append((try self.flattenAST(scope, term, return_label, break_label, continue_label, error_label, errors, allocator)) orelse continue);
                }
                self.appendInstruction(try ir_.IR.createStackPush(ast.getToken().span, allocator));
                self.appendInstruction(ir);
                self.appendInstruction(try ir_.IR.createStackPop(ast.getToken().span, allocator));
                return temp;
            },
            .function => {
                const temp = try self.create_temp_lvalue(try ast.typeof(scope, errors, allocator), errors, allocator);
                self.appendInstruction(try ir_.IR.create_ast(temp, ast, ast.getToken().span, allocator));
                return temp;
            },
            .index => {
                const _type = try ast.typeof(scope, errors, allocator);
                const size = (try _type.expand_type(scope, errors, allocator)).sizeof();

                // Get the type of the index ast. This will determine if this is an array index or a slice index
                const ast_expanded_type = try (try ast.index.lhs.typeof(scope, errors, allocator)).expand_type(scope, errors, allocator);

                // Flatten index expr
                const rhs = try self.flattenAST(scope, ast.index.rhs, return_label, break_label, continue_label, error_label, errors, allocator);

                // Recursively get index's ast L_Value node
                const pre_ast_lval = try self.flattenAST(scope, ast.index.lhs, return_label, break_label, continue_label, error_label, errors, allocator);
                var ast_lval = pre_ast_lval;

                if (ast_expanded_type.product.was_slice) {
                    // Indexing a slice; index_val := lhs._0^[rhs]
                    const addr_type = ast_expanded_type.product.terms.items[0];
                    const addr_size = (try _type.expand_type(scope, errors, allocator)).sizeof();
                    ast_lval = try lval_.L_Value.create_select(ast_lval.?, 0, 0, addr_size, addr_type, try _type.expand_type(scope, errors, allocator), null, allocator);
                    ast_lval = try lval_.L_Value.create_dereference(ast_lval.?, addr_size, addr_type, try _type.expand_type(scope, errors, allocator), allocator);
                }

                // Do bounds-check
                var length: *lval_.L_Value = undefined;
                if (ast_expanded_type.* == .product and ast_expanded_type.product.was_slice) {
                    const offset = try ast_expanded_type.product.get_offset(1, scope, errors, allocator);
                    length = try lval_.L_Value.create_select(pre_ast_lval.?, 1, offset, 8, primitives_.int64_type, primitives_.int64_type, null, allocator);
                } else if (ast_expanded_type.* == .product and !ast_expanded_type.product.was_slice) {
                    length = try self.create_temp_lvalue(primitives_.int_type, errors, allocator);
                    const ir = try ir_.IR.createInt(length, ast_expanded_type.product.terms.items.len, ast.getToken().span, allocator);
                    self.appendInstruction(ir);
                } else {
                    unreachable;
                }

                // Surround with L_Value node
                return try lval_.L_Value.create_index(ast_lval.?, rhs.?, length, size, _type, try _type.expand_type(scope, errors, allocator), allocator);
            },
            .select => {
                // Recursively get select's ast L_Value node
                const ast_lval = try self.flattenAST(scope, ast.select.lhs, return_label, break_label, continue_label, error_label, errors, allocator);

                // Get the offset into the struct that this select does
                var lhs_expanded_type = try (try ast.select.lhs.typeof(scope, errors, allocator)).expand_type(scope, errors, allocator);
                const offset = if (lhs_expanded_type.* == .product)
                    try lhs_expanded_type.product.get_offset(ast.select.pos.?, scope, errors, allocator)
                else
                    try lhs_expanded_type.sum.get_offset(ast.select.pos.?, scope, errors, allocator);

                var tag: ?*lval_.L_Value = null;
                if (lhs_expanded_type.* == .sum) {
                    // Check that the sum value has the proper tag before a selection
                    tag = try self.create_temp_lvalue(primitives_.word64_type, errors, allocator);
                    self.appendInstruction(try ir_.IR.createGetTag(tag.?, ast_lval.?, ast.getToken().span, allocator));
                }

                // Surround with L_Value node
                const _type = try ast.typeof(scope, errors, allocator);
                const expanded_type = try _type.expand_type(scope, errors, allocator);
                return try lval_.L_Value.create_select(ast_lval.?, ast.select.pos.?, offset, expanded_type.sizeof(), _type, expanded_type, tag, allocator);
            },
            .product => {
                if (try (try ast.product.terms.items[0].typeof(scope, errors, allocator)).typesMatch(primitives_.type_type, scope, errors, allocator)) {
                    const temp = try self.create_temp_lvalue(try ast.typeof(scope, errors, allocator), errors, allocator);
                    self.appendInstruction(try ir_.IR.create_ast(temp, ast, ast.getToken().span, allocator));
                    return temp;
                } else {
                    const temp = try self.create_temp_lvalue(try ast.typeof(scope, errors, allocator), errors, allocator);
                    var ir = try ir_.IR.createLoadStruct(temp, ast.getToken().span, allocator);
                    for (ast.product.terms.items) |term| {
                        try ir.data.lval_list.append((try self.flattenAST(scope, term, return_label, break_label, continue_label, error_label, errors, allocator)) orelse return null);
                    }
                    self.appendInstruction(ir);
                    return temp;
                }
            },
            .sum => {
                const temp = try self.create_temp_lvalue(try ast.typeof(scope, errors, allocator), errors, allocator);
                self.appendInstruction(try ir_.IR.create_ast(temp, ast, ast.getToken().span, allocator));
                return temp;
            },

            // Fancy Operators
            .addrOf => {
                if (try (try ast.typeof(scope, errors, allocator)).typesMatch(primitives_.type_type, scope, errors, allocator)) {
                    const temp = try self.create_temp_lvalue(try ast.typeof(scope, errors, allocator), errors, allocator);
                    self.appendInstruction(try ir_.IR.create_ast(temp, ast, ast.getToken().span, allocator));
                    return temp;
                } else {
                    const expr = try self.flattenAST(scope, ast.addrOf.expr, return_label, break_label, continue_label, error_label, errors, allocator);
                    const temp = try self.create_temp_lvalue(try ast.typeof(scope, errors, allocator), errors, allocator);

                    const ir = try ir_.IR.create(.addrOf, temp, expr, null, ast.getToken().span, allocator);
                    self.appendInstruction(ir);
                    return temp;
                }
            },
            .subSlice => {
                const arr = (try self.flattenAST(scope, ast.subSlice.super, return_label, break_label, continue_label, error_label, errors, allocator)) orelse return null;
                const lower = (try self.flattenAST(scope, ast.subSlice.lower.?, return_label, break_label, continue_label, error_label, errors, allocator)) orelse return null;
                const upper = (try self.flattenAST(scope, ast.subSlice.upper.?, return_label, break_label, continue_label, error_label, errors, allocator)) orelse return null;

                // Statically confirm that lower <= upper
                // if (lower.def.?.kind == .loadInt and upper.def.?.kind == .loadInt and lower.def.?.data.int > upper.def.?.data.int) {
                //     errors.addError(Error{ .slice_lower_upper = .{
                //         .span = lower.def.?.span,
                //         .lower = lower.def.?.data.int,
                //         .upper = upper.def.?.data.int,
                //     } });
                //     return error.typeError;
                // } else
                { // Dynamically confirm that lower <= upper
                    const end_label = try ir_.IR.createLabel(self, ast.getToken().span, allocator);
                    const compare = try self.create_temp_lvalue(primitives_.bool_type, errors, allocator);
                    const ir = try ir_.IR.create(.greater_int, compare, lower, upper, ast.getToken().span, allocator);
                    self.appendInstruction(ir);
                    const branch = try ir_.IR.createBranch(compare, end_label, ast.getToken().span, allocator);
                    self.appendInstruction(branch);
                    self.appendInstruction(try ir_.IR.createStackPush(ast.getToken().span, allocator));
                    self.appendInstruction(try ir_.IR.createPanic("subslice lower bound is greater than upper bound", ast.getToken().span, allocator));
                    self.appendInstruction(end_label);
                }

                const new_size = try self.create_temp_lvalue(primitives_.int_type, errors, allocator);
                const new_size_ir = try ir_.IR.create(.sub_int, new_size, upper, lower, ast.getToken().span, allocator);
                self.appendInstruction(new_size_ir);

                const slice_type = try ast.typeof(scope, errors, allocator);
                const data_type = slice_type.product.terms.items[0];
                const size = (try data_type.expand_type(scope, errors, allocator)).sizeof();
                const data_ptr = try lval_.L_Value.create_select(arr, 0, 0, size, data_type, try data_type.expand_type(scope, errors, allocator), null, allocator);

                const new_data_ptr = try self.create_temp_lvalue(data_type, errors, allocator);
                const new_data_ptr_ir = try ir_.IR.create(.add_int, new_data_ptr, data_ptr, lower, ast.getToken().span, allocator);
                self.appendInstruction(new_data_ptr_ir);

                const temp = try self.create_temp_lvalue(try ast.typeof(scope, errors, allocator), errors, allocator);
                var load_struct = try ir_.IR.createLoadStruct(temp, ast.getToken().span, allocator);
                try load_struct.data.lval_list.append(new_data_ptr);
                try load_struct.data.lval_list.append(new_size);
                self.appendInstruction(load_struct);
                return temp;
            },
            .annotation => {
                const temp = try self.create_temp_lvalue(try ast.typeof(scope, errors, allocator), errors, allocator);
                self.appendInstruction(try ir_.IR.create_ast(temp, ast, ast.getToken().span, allocator));
                return temp;
            },
            .inferredMember => {
                var init: ?*lval_.L_Value = null;
                const pos: i128 = ast.inferredMember.pos.?;
                const proper_term: *ast_.AST = (try ast.typeof(scope, errors, allocator)).sum.terms.items[@as(usize, @intCast(pos))];
                if (ast.inferredMember.init) |_init| {
                    init = try self.flattenAST(scope, _init, return_label, break_label, continue_label, error_label, errors, allocator);
                } else if (proper_term.annotation.init == null and proper_term.annotation.type.* != .unit_type) {
                    errors.addError(errs.Error{ .basic = .{ .span = ast.getToken().span, .msg = "no value provided, and no default value available" } });
                    return error.typeError;
                }
                const temp = try self.create_temp_lvalue(try ast.typeof(scope, errors, allocator), errors, allocator);

                const ir = try ir_.IR.createUnion(temp, init, ast.inferredMember.pos.?, ast.getToken().span, allocator);
                self.appendInstruction(ir);
                return temp;
            },

            // Control-flow expressions
            ._if => {
                // Create the result symbol and IR
                const symbol = try self.createTempSymbol(try ast.typeof(scope, errors, allocator), errors, allocator);
                const temp = try lval_.L_Value.create_unversioned_symbver(symbol, allocator);

                // If there's a let, then do it, dumby!
                if (ast._if.let) |let| {
                    _ = try self.flattenAST(ast._if.scope.?, let, return_label, break_label, continue_label, error_label, errors, allocator);
                }

                // Labels used
                const else_label = try ir_.IR.createLabel(self, ast.getToken().span, allocator);
                const end_label = try ir_.IR.createLabel(self, ast.getToken().span, allocator);

                // Test lhs, branch
                const condition = (try self.flattenAST(ast._if.scope.?, ast._if.condition, return_label, break_label, continue_label, error_label, errors, allocator)) orelse return null;
                const branch = try ir_.IR.createBranch(condition, else_label, ast.getToken().span, allocator);
                self.appendInstruction(branch);

                // lhs was true, recurse to rhs, store in temp
                if (try self.flattenAST(ast._if.scope.?, ast._if.bodyBlock, return_label, break_label, continue_label, error_label, errors, allocator)) |block_lval| {
                    const block_copy_lval = try lval_.L_Value.create_unversioned_symbver(symbol, allocator);
                    var block_copy: *ir_.IR = undefined;
                    if (ast._if.elseBlock == null) {
                        // no else block => if is optional, coerce up to `.some <- block`
                        block_copy = try ir_.IR.createUnion(block_copy_lval, block_lval, 1, ast.getToken().span, allocator);
                    } else {
                        // regular if-else => copy block
                        block_copy = try ir_.IR.create_simple_copy(block_copy_lval, block_lval, ast.getToken().span, allocator);
                    }
                    self.appendInstruction(block_copy);
                }
                self.appendInstruction(try ir_.IR.createJump(end_label, ast.getToken().span, allocator));

                // lhs was false, store `false` in temp
                self.appendInstruction(else_label);
                if (ast._if.elseBlock) |elseBlock| {
                    if (try self.flattenAST(ast._if.scope.?, elseBlock, return_label, break_label, continue_label, error_label, errors, allocator)) |else_lval| {
                        const else_copy_lval = try lval_.L_Value.create_unversioned_symbver(symbol, allocator);
                        const else_copy = try ir_.IR.create_simple_copy(else_copy_lval, else_lval, ast.getToken().span, allocator);
                        self.appendInstruction(else_copy);
                    }
                    self.appendInstruction(try ir_.IR.createJump(end_label, ast.getToken().span, allocator));
                } else {
                    // no else block => if is optional, store null
                    const else_copy_lval = try lval_.L_Value.create_unversioned_symbver(symbol, allocator);
                    const else_copy = try ir_.IR.createUnion(else_copy_lval, null, 0, ast.getToken().span, allocator);
                    self.appendInstruction(else_copy);
                }
                self.appendInstruction(end_label);
                return temp;
            },
            .match => {
                // Create the result symbol and IR
                const symbol_type = if (ast.match.has_else)
                    // Match has an else, type of the mappings should be the type of the match
                    try ast.typeof(scope, errors, allocator)
                else
                    // Match has no else, type of the mappings should be wrapped in an optional type
                    try ast_.AST.create_optional_type(try ast.typeof(scope, errors, allocator), allocator);
                const symbol = try self.createTempSymbol(symbol_type, errors, allocator);
                const temp = try lval_.L_Value.create_unversioned_symbver(symbol, allocator);

                // Exit label of match
                const end_label = try ir_.IR.createLabel(self, ast.getToken().span, allocator);
                // Label jumped to if all tests fail and no `else` mapping
                const none_label = try ir_.IR.createLabel(self, ast.getToken().span, allocator);
                // List of labels to branch to on an unsuccessful test (ie "next pattern")
                var lhs_label_list = std.ArrayList(*ir_.IR).init(allocator);
                defer lhs_label_list.deinit();
                // List of labels to branch to on a successful test (ie "code for the mapping")
                var rhs_label_list = std.ArrayList(*ir_.IR).init(allocator);
                defer rhs_label_list.deinit();
                for (ast.match.mappings.items) |_| {
                    try lhs_label_list.append(try ir_.IR.createLabel(self, ast.getToken().span, allocator));
                    try rhs_label_list.append(try ir_.IR.createLabel(self, ast.getToken().span, allocator));
                }
                std.debug.assert(lhs_label_list.items.len == ast.match.mappings.items.len);

                // If there's a let, then do it, dumby!
                if (ast.match.let) |let| {
                    _ = try self.flattenAST(ast.match.scope.?, let, return_label, break_label, continue_label, error_label, errors, allocator);
                }

                const expr = try self.flattenAST(scope, ast.match.expr, return_label, break_label, continue_label, error_label, errors, allocator);
                if (expr == null) {
                    return null;
                }

                // Generate the lhs of the mappings
                var label_index: usize = 0;
                for (ast.match.mappings.items) |mapping| {
                    const lhs_label = lhs_label_list.items[label_index];
                    self.appendInstruction(lhs_label);
                    if (mapping.mapping.lhs) |lhs| {
                        const next_label = if (label_index < lhs_label_list.items.len - 1)
                            lhs_label_list.items[label_index + 1]
                        else
                            none_label;
                        try self.generate_match_pattern_check(ast.match.scope.?, lhs, expr.?, next_label, return_label, break_label, continue_label, error_label, errors, allocator);
                    }
                    self.appendInstruction(try ir_.IR.createJump(rhs_label_list.items[label_index], mapping.getToken().span, allocator));
                    label_index += 1;
                }

                if (!ast.match.has_else) { // All tests failed, no `else` mapping. Store `.none` as result
                    self.appendInstruction(none_label);
                    const else_copy_lval = try lval_.L_Value.create_unversioned_symbver(symbol, allocator);
                    const else_copy = try ir_.IR.createUnion(else_copy_lval, null, 0, ast.getToken().span, allocator);
                    self.appendInstruction(else_copy);
                    self.appendInstruction(try ir_.IR.createJump(end_label, ast.getToken().span, allocator));
                }

                // Write the labels and the rhs of the mappings
                label_index = 0;
                for (ast.match.mappings.items) |mapping| {
                    self.appendInstruction(rhs_label_list.items[label_index]);
                    if (mapping.mapping.lhs) |lhs| {
                        // Generate initialization for patterns before the rhs
                        try self.generate_pattern(ast.match.scope.?, lhs, expr.?.get_type(), expr.?, errors, allocator);
                    }

                    // Generate the rhs, copy result to temp
                    const mapping_scope = if (mapping.mapping.scope != null) mapping.mapping.scope.? else ast.match.scope.?;
                    if (try self.flattenAST(mapping_scope, mapping.mapping.rhs.?, return_label, break_label, continue_label, error_label, errors, allocator)) |rhs_lval| {
                        const rhs_copy_lval = try lval_.L_Value.create_unversioned_symbver(symbol, allocator);
                        var rhs_copy: *ir_.IR = undefined;
                        if (ast.match.has_else) {
                            rhs_copy = try ir_.IR.create_simple_copy(rhs_copy_lval, rhs_lval, ast.getToken().span, allocator);
                        } else {
                            rhs_copy = try ir_.IR.createUnion(rhs_copy_lval, rhs_lval, 1, ast.getToken().span, allocator);
                        }
                        self.appendInstruction(rhs_copy);
                    }
                    self.appendInstruction(try ir_.IR.createJump(end_label, ast.getToken().span, allocator));
                    label_index += 1;
                }
                self.appendInstruction(end_label);

                return temp;
            },
            ._while => {
                // Create the result symbol and IR
                const symbol = try self.createTempSymbol(try ast.typeof(scope, errors, allocator), errors, allocator);
                const temp = try lval_.L_Value.create_unversioned_symbver(symbol, allocator);

                // Labels used
                const cond_label = try ir_.IR.createLabel(self, ast.getToken().span, allocator);
                const current_continue_label = try ir_.IR.createLabel(self, ast.getToken().span, allocator);
                const else_label = try ir_.IR.createLabel(self, ast.getToken().span, allocator);
                const end_label = try ir_.IR.createLabel(self, ast.getToken().span, allocator);

                // If there's a let, then do it, dumby!
                if (ast._while.let) |let| {
                    _ = try self.flattenAST(ast._while.scope.?, let, return_label, break_label, continue_label, error_label, errors, allocator);
                }

                // Test condition, branch to either body or else block
                self.appendInstruction(cond_label);
                const condition = (try self.flattenAST(ast._while.scope.?, ast._while.condition, return_label, end_label, current_continue_label, error_label, errors, allocator)) orelse return null;
                const branch = try ir_.IR.createBranch(condition, else_label, ast.getToken().span, allocator);
                self.appendInstruction(branch);

                // Body block
                if (try self.flattenAST(ast._while.scope.?, ast._while.bodyBlock, return_label, end_label, current_continue_label, error_label, errors, allocator)) |block_lval| {
                    const block_copy_lval = try lval_.L_Value.create_unversioned_symbver(symbol, allocator);
                    var block_copy: *ir_.IR = undefined;
                    if (ast._while.elseBlock == null) {
                        // no else block => while is optional, coerce up to `.some <- block`
                        block_copy = try ir_.IR.createUnion(block_copy_lval, block_lval, 1, ast.getToken().span, allocator);
                    } else {
                        // regular while-else => copy block
                        block_copy = try ir_.IR.create_simple_copy(block_copy_lval, block_lval, ast.getToken().span, allocator);
                    }
                    self.appendInstruction(block_copy);
                }

                // Post-condition, jump to condition test
                self.appendInstruction(current_continue_label);
                if (ast._while.post) |post| {
                    _ = try self.flattenAST(ast._while.scope.?, post, return_label, end_label, continue_label, error_label, errors, allocator);
                }
                self.appendInstruction(try ir_.IR.createJump(cond_label, ast.getToken().span, allocator));

                // Else block
                self.appendInstruction(else_label);
                if (ast._while.elseBlock) |elseBlock| {
                    if (try self.flattenAST(ast._while.scope.?, elseBlock, return_label, break_label, continue_label, error_label, errors, allocator)) |else_lval| {
                        const elseCopy = try ir_.IR.create_simple_copy(temp, else_lval, ast.getToken().span, allocator);
                        self.appendInstruction(elseCopy);
                    }
                    self.appendInstruction(try ir_.IR.createJump(end_label, ast.getToken().span, allocator));
                } else {
                    // no else block => while is optional, store null
                    const else_copy_lval = try lval_.L_Value.create_unversioned_symbver(symbol, allocator);
                    const else_copy = try ir_.IR.createUnion(else_copy_lval, null, 0, ast.getToken().span, allocator);
                    self.appendInstruction(else_copy);
                }
                self.appendInstruction(end_label);
                return temp;
            },
            .block => {
                if (ast.block.statements.items.len == 0 and ast.block.final == null) {
                    return null;
                } else {
                    var continue_labels = std.ArrayList(*ir_.IR).init(allocator);
                    defer continue_labels.deinit();
                    var break_labels = std.ArrayList(*ir_.IR).init(allocator);
                    defer break_labels.deinit();
                    var return_labels = std.ArrayList(*ir_.IR).init(allocator);
                    defer return_labels.deinit();
                    var error_labels = std.ArrayList(*ir_.IR).init(allocator);
                    defer error_labels.deinit();
                    for (ast.block.scope.?.defers.items) |_| {
                        try continue_labels.append(try ir_.IR.createLabel(self, ast.getToken().span, allocator));
                        try break_labels.append(try ir_.IR.createLabel(self, ast.getToken().span, allocator));
                        try return_labels.append(try ir_.IR.createLabel(self, ast.getToken().span, allocator));
                    }
                    for (ast.block.scope.?.errdefers.items) |_| {
                        try error_labels.append(try ir_.IR.createLabel(self, ast.getToken().span, allocator));
                    }
                    const end = try ir_.IR.createLabel(self, ast.getToken().span, allocator);

                    // These are the labels to go to on each final statement. These are updated to point to different places in the defer chain at the end of this block.
                    var current_continue_label = if (continue_label != null) continue_label else end;
                    var current_break_label = break_label;
                    var current_return_label = return_label;
                    var current_error_label = error_label;
                    var defer_label_index: usize = 0;
                    var errdefer_label_index: usize = 0;

                    var temp: ?*lval_.L_Value = null;
                    for (ast.block.statements.items) |child| {
                        temp = try self.flattenAST(ast.block.scope.?, child, current_return_label, current_break_label, current_continue_label, current_error_label, errors, allocator);
                        if (child.* == ._defer) {
                            current_continue_label = continue_labels.items[defer_label_index];
                            current_break_label = break_labels.items[defer_label_index];
                            current_return_label = return_labels.items[defer_label_index];
                            defer_label_index += 1;
                        } else if (child.* == ._errdefer) {
                            current_error_label = error_labels.items[errdefer_label_index];
                            errdefer_label_index += 1;
                        }
                    }
                    if (ast.block.final) |final| {
                        temp = try self.flattenAST(ast.block.scope.?, final, current_return_label, current_break_label, current_continue_label, current_error_label, errors, allocator);
                    } else if (temp) |_temp| {
                        const expanded_temp_type = try _temp.get_type().expand_type(scope, errors, allocator);
                        if (current_error_label != null and expanded_temp_type.* == .sum and expanded_temp_type.sum.was_error) {
                            // Returning error sum, runtime check if error, branch to error path
                            const condition = try create_temp_lvalue(self, primitives_.word64_type, errors, allocator);
                            self.appendInstruction(try ir_.IR.createGetTag(condition, _temp, ast.getToken().span, allocator)); // Assumes `ok` tag is zero, `err` tag is nonzero
                            const not_condition = try create_temp_lvalue(self, primitives_.bool_type, errors, allocator);
                            self.appendInstruction(try ir_.IR.create(.not, not_condition, condition, null, ast.getToken().span, allocator));
                            self.appendInstruction(try ir_.IR.createBranch(not_condition, current_error_label, ast.getToken().span, allocator));
                        }
                    }

                    try self.generateDefers(&ast.block.scope.?.defers, &continue_labels, ast.block.scope.?, errors, allocator);
                    self.appendInstruction(try ir_.IR.createJump(end, ast.getToken().span, allocator));

                    try self.generateDefers(&ast.block.scope.?.defers, &break_labels, ast.block.scope.?, errors, allocator);
                    self.appendInstruction(try ir_.IR.createJump(break_label, ast.getToken().span, allocator));

                    try self.generateDefers(&ast.block.scope.?.defers, &return_labels, ast.block.scope.?, errors, allocator);
                    self.appendInstruction(try ir_.IR.createJump(return_label, ast.getToken().span, allocator));

                    try self.generateDefers(&ast.block.scope.?.errdefers, &error_labels, ast.block.scope.?, errors, allocator);
                    self.appendInstruction(try ir_.IR.createJump(error_label, ast.getToken().span, allocator));

                    self.appendInstruction(end);

                    return temp;
                }
            },

            // Control-flow statements
            .decl => {
                const def: ?*lval_.L_Value = try self.flattenAST(scope, ast.decl.init, return_label, break_label, continue_label, error_label, errors, allocator);
                if (def == null) {
                    return null;
                }
                try self.generate_pattern(scope, ast.decl.pattern, try ast.decl.type.expand_type(scope, errors, allocator), def.?, errors, allocator);
                return null;
            },
            .fnDecl => {
                _ = try ast.fnDecl.symbol.?.get_cfg(self, self.interned_strings, errors, allocator);
                const temp = try self.create_temp_lvalue(ast.fnDecl.symbol.?._type, errors, allocator);
                var ir = try ir_.IR.create(.loadSymbol, temp, null, null, ast.getToken().span, allocator);
                ir.data = ir_.Data{ .symbol = ast.fnDecl.symbol.? };
                self.appendInstruction(ir);
                return temp;
            },
            ._errdefer, ._defer => {
                return null;
            },
            ._continue => {
                self.appendInstruction(try ir_.IR.createJump(continue_label, ast.getToken().span, allocator));
                return null;
            },
            ._unreachable => {
                self.appendInstruction(try ir_.IR.createStackPush(ast.getToken().span, allocator));
                self.appendInstruction(try ir_.IR.createPanic("reached unreachable code", ast.getToken().span, allocator));
                return null;
            },
            ._break => {
                self.appendInstruction(try ir_.IR.createJump(break_label, ast.getToken().span, allocator));
                return null;
            },
            ._return => {
                if (ast._return.expr) |expr| {
                    // Copy expr to retval
                    const retval = (try self.flattenAST(scope, expr, return_label, break_label, continue_label, error_label, errors, allocator)) orelse return null;
                    const retval_lval = try lval_.L_Value.create_unversioned_symbver(self.return_symbol, allocator);
                    const retval_copy = try ir_.IR.create_simple_copy(retval_lval, retval, ast.getToken().span, allocator);
                    self.appendInstruction(retval_copy);

                    const expanded_expr_type = try (try expr.typeof(scope, errors, allocator)).expand_type(scope, errors, allocator);
                    if (expanded_expr_type.* == .sum and expanded_expr_type.sum.was_error) {
                        // Returning error sum, runtime check if error, branch to error path
                        const condition = try create_temp_lvalue(self, primitives_.word64_type, errors, allocator);
                        self.appendInstruction(try ir_.IR.createGetTag(condition, retval, ast.getToken().span, allocator)); // Assumes `ok` tag is zero, `err` tag is nonzero
                        const not_condition = try create_temp_lvalue(self, primitives_.bool_type, errors, allocator);
                        self.appendInstruction(try ir_.IR.create(.not, not_condition, condition, null, ast.getToken().span, allocator));
                        self.appendInstruction(try ir_.IR.createBranch(not_condition, error_label, ast.getToken().span, allocator));
                    }
                    self.appendInstruction(try ir_.IR.createJump(return_label, ast.getToken().span, allocator));
                } else {
                    // Jump to return_label
                    self.appendInstruction(try ir_.IR.createJump(return_label, ast.getToken().span, allocator));
                }
                return null;
            },

            else => {
                std.debug.print("Unimplemented flattenAST() for: AST.{s}\n", .{@tagName(ast.*)});
                unreachable;
            },
        }
    }

    fn generate_tuple_equality(
        self: *CFG,
        scope: *symbol_.Scope,
        lhs: *lval_.L_Value,
        rhs: *lval_.L_Value,
        fail_label: *ir_.IR,
        errors: *errs.Errors,
        allocator: std.mem.Allocator,
    ) FlattenASTError!void {
        const new_lhs = lhs; // try L_Value.create_unversioned_symbver(lhs.symbol, lhs.symbol._type.?, allocator);
        const new_rhs = rhs; // try L_Value.create_unversioned_symbver(rhs.symbol, rhs.symbol._type.?, allocator);
        const temp = try self.create_temp_lvalue(primitives_.bool_type, errors, allocator);
        var lhs_type = try lhs.get_type().expand_type(scope, errors, allocator);
        if (lhs_type.* == .product) {
            for (0..lhs_type.product.terms.items.len) |i| {
                const _type = lhs_type.product.terms.items[i];
                const size = (try _type.expand_type(scope, errors, allocator)).sizeof();
                const lhs_select = try lval_.L_Value.create_select(new_lhs, i, try lhs_type.product.get_offset(i, scope, errors, allocator), size, _type, try _type.expand_type(scope, errors, allocator), null, allocator);
                const rhs_select = try lval_.L_Value.create_select(new_rhs, i, try lhs_type.product.get_offset(i, scope, errors, allocator), size, _type, try _type.expand_type(scope, errors, allocator), null, allocator);
                try self.generate_tuple_equality(scope, lhs_select, rhs_select, fail_label, errors, allocator);
            }
        } else if (lhs_type.* == .sum) {
            const lhs_tag = try create_temp_lvalue(self, primitives_.word64_type, errors, allocator);
            const rhs_tag = try create_temp_lvalue(self, primitives_.word64_type, errors, allocator);
            self.appendInstruction(try ir_.IR.createGetTag(lhs_tag, new_lhs, lhs.extract_symbver().symbol.span, allocator));
            self.appendInstruction(try ir_.IR.createGetTag(rhs_tag, new_rhs, lhs.extract_symbver().symbol.span, allocator));
            self.appendInstruction(try ir_.IR.create(.equal, temp, lhs_tag, rhs_tag, lhs.extract_symbver().symbol.span, allocator));
            self.appendInstruction(try ir_.IR.createBranch(temp, fail_label, lhs.extract_symbver().symbol.span, allocator));
        } else {
            self.appendInstruction(try ir_.IR.create(.equal, temp, new_lhs, rhs, lhs.extract_symbver().symbol.span, allocator));
            self.appendInstruction(try ir_.IR.createBranch(temp, fail_label, lhs.extract_symbver().symbol.span, allocator));
        }
    }

    fn generate_assign(
        self: *CFG, // Current control-flow-graph
        scope: *symbol_.Scope, // Scope node to use for symbol-tree lookups
        lhs: *ast_.AST, // AST node for the LHS of the `=`
        rhs: *lval_.L_Value, // L_Value which holds the value to assign
        return_label: ?*ir_.IR,
        break_label: ?*ir_.IR,
        continue_label: ?*ir_.IR,
        error_label: ?*ir_.IR,
        errors: *errs.Errors,
        allocator: std.mem.Allocator,
    ) FlattenASTError!?*lval_.L_Value // If assign is to a single symbver, returns the symbver
    {
        if (lhs.* == .product) {
            // Recursively call `generate_assign` for each term in the product.
            // product-assigns may be nested, for example:
            //     ((x, y), (a, b)) = get_tuple()
            // So it's important that this is recursive
            var lhs_expanded_type = try (try lhs.typeof(scope, errors, allocator)).expand_type(scope, errors, allocator);
            for (lhs.product.terms.items, 0..) |term, i| {
                const product_lhs = try self.flattenAST(scope, term, return_label, break_label, continue_label, error_label, errors, allocator);
                if (product_lhs == null) {
                    continue;
                }
                const _type = rhs.get_type().product.terms.items[i];
                const size = (try _type.expand_type(scope, errors, allocator)).sizeof();
                const select = try lval_.L_Value.create_select(rhs, i, try lhs_expanded_type.product.get_offset(i, scope, errors, allocator), size, _type, try _type.expand_type(scope, errors, allocator), null, allocator);
                _ = try self.generate_assign(scope, term, select, return_label, break_label, continue_label, error_label, errors, allocator);
            }
            return null;
        } else {
            // Get L_Value tree, create a `copy` IR of L_Value tree and rhs
            const lval = try self.flattenAST(scope, lhs, return_label, break_label, continue_label, error_label, errors, allocator);
            var ir = try ir_.IR.create(.copy, null, rhs, null, lhs.getToken().span, allocator);
            ir.dest = lval;
            ir.safe = true;
            self.appendInstruction(ir);
            return null;
        }
    }

    fn generate_pattern(
        self: *CFG,
        scope: *symbol_.Scope,
        pattern: *ast_.AST,
        _type: *ast_.AST,
        def: *lval_.L_Value,
        errors: *errs.Errors,
        allocator: std.mem.Allocator,
    ) FlattenASTError!void {
        if (pattern.* == .symbol) {
            if (!std.mem.eql(u8, pattern.symbol.name, "_")) {
                const symbver = try lval_.L_Value.create_unversioned_symbver(pattern.symbol.symbol, allocator);
                const ir = try ir_.IR.create_simple_copy(symbver, def, pattern.getToken().span, allocator);
                self.appendInstruction(ir);
            }
        } else if (pattern.* == .product) {
            for (pattern.product.terms.items, 0..) |term, i| {
                const subscript_type = _type.product.terms.items[i];
                const size = (try subscript_type.expand_type(scope, errors, allocator)).sizeof();
                const offset = try _type.product.get_offset(i, scope, errors, allocator);
                const lval = try lval_.L_Value.create_select(def, i, offset, size, subscript_type, try subscript_type.expand_type(scope, errors, allocator), null, allocator);
                try self.generate_pattern(scope, term, subscript_type, lval, errors, allocator);
            }
        } else if (pattern.* == .inject) {
            const lhs_type = try pattern.inject.lhs.typeof(scope, errors, allocator);
            const domain = try validate_.domainof(pattern, lhs_type, scope, errors, allocator);
            const size = (try domain.expand_type(scope, errors, allocator)).sizeof();
            const lval = try lval_.L_Value.create_select(def, pattern.inject.lhs.inferredMember.pos.?, 0, size, domain, try domain.expand_type(scope, errors, allocator), null, allocator);
            try self.generate_pattern(scope, pattern.inject.rhs, domain, lval, errors, allocator);
        }
    }

    /// Generates the code which checks if the pattern matches the match expression
    fn generate_match_pattern_check(
        self: *CFG,
        scope: *symbol_.Scope,
        pattern: ?*ast_.AST,
        expr: *lval_.L_Value,
        next_pattern: *ir_.IR,
        return_label: ?*ir_.IR,
        break_label: ?*ir_.IR,
        continue_label: ?*ir_.IR,
        error_label: ?*ir_.IR,
        errors: *errs.Errors,
        allocator: std.mem.Allocator,
    ) FlattenASTError!void {
        if (pattern == null) {
            // Implies `else` branch, infallible.
            return;
        }
        const new_expr = expr; // try L_Value.create_unversioned_symbver(expr.symbol, expr.type, allocator);
        switch (pattern.?.*) {
            .int,
            .float,
            ._true,
            ._false,
            .char,
            .string,
            .block,
            => {
                const value = try self.flattenAST(scope, pattern.?, return_label, break_label, continue_label, error_label, errors, allocator);
                const condition = try self.create_temp_lvalue(primitives_.bool_type, errors, allocator);
                const condition_ir = try ir_.IR.create(.equal, condition, new_expr, value.?, pattern.?.getToken().span, allocator);
                self.appendInstruction(condition_ir);
                const branch = try ir_.IR.createBranch(condition, next_pattern, pattern.?.getToken().span, allocator);
                self.appendInstruction(branch);
            },
            .symbol => {
                // Infallible check, do not branch to next pattern
            },
            .product => {
                for (pattern.?.product.terms.items, 0..) |term, i| {
                    const subscript_type = new_expr.get_type().product.terms.items[i];
                    const size = (try subscript_type.expand_type(scope, errors, allocator)).sizeof();
                    const pattern_type = try (try pattern.?.typeof(scope, errors, allocator)).expand_type(scope, errors, allocator);
                    const offset = try pattern_type.product.get_offset(i, scope, errors, allocator);
                    const lval = try lval_.L_Value.create_select(new_expr, i, offset, size, subscript_type, try subscript_type.expand_type(scope, errors, allocator), null, allocator);
                    try self.generate_match_pattern_check(scope, term, lval, next_pattern, return_label, break_label, continue_label, error_label, errors, allocator);
                }
            },
            .select => {
                // Get tag of pattern
                const sel = try self.create_temp_lvalue(primitives_.word64_type, errors, allocator);
                const sel_ir = try ir_.IR.createInt(sel, pattern.?.select.pos.?, pattern.?.getToken().span, allocator);
                self.appendInstruction(sel_ir);

                // Get tag of expr
                const tag = try self.create_temp_lvalue(primitives_.word64_type, errors, allocator);
                const tag_ir = try ir_.IR.createGetTag(tag, expr, pattern.?.getToken().span, allocator);
                self.appendInstruction(tag_ir);

                // Compare them, jump to next pattern if they are not equal
                const neql = try self.create_temp_lvalue(primitives_.bool_type, errors, allocator);
                const neql_ir = try ir_.IR.create(.equal, neql, tag, sel, pattern.?.getToken().span, allocator);
                self.appendInstruction(neql_ir);
                const branch = try ir_.IR.createBranch(neql, next_pattern, pattern.?.getToken().span, allocator);
                self.appendInstruction(branch);
            },
            .inferredMember => {
                // Get tag of pattern
                const sel = try self.create_temp_lvalue(primitives_.word64_type, errors, allocator);
                const sel_ir = try ir_.IR.createInt(sel, pattern.?.inferredMember.pos.?, pattern.?.getToken().span, allocator);
                self.appendInstruction(sel_ir);

                // Get tag of expr
                const tag = try self.create_temp_lvalue(primitives_.word64_type, errors, allocator);
                const tag_ir = try ir_.IR.createGetTag(tag, expr, pattern.?.getToken().span, allocator);
                self.appendInstruction(tag_ir);

                // Compare them, jump to next pattern if they are not equal
                const neql = try self.create_temp_lvalue(primitives_.bool_type, errors, allocator);
                const neql_ir = try ir_.IR.create(.equal, neql, tag, sel, pattern.?.getToken().span, allocator);
                self.appendInstruction(neql_ir);
                const branch = try ir_.IR.createBranch(neql, next_pattern, pattern.?.getToken().span, allocator);
                self.appendInstruction(branch);
            },
            .inject => {
                try self.generate_match_pattern_check(scope, pattern.?.inject.lhs, expr, next_pattern, return_label, break_label, continue_label, error_label, errors, allocator);
            },
            else => {
                std.debug.print("Unimplemented generate_match_pattern_check() for {s}\n", .{@tagName(pattern.?.*)});
                unreachable;
            },
        }
    }

    fn generateDefers(self: *CFG, defers: *std.ArrayList(*ast_.AST), deferLabels: *std.ArrayList(*ir_.IR), scope: *symbol_.Scope, errors: *errs.Errors, allocator: std.mem.Allocator) FlattenASTError!void {
        var i: usize = defers.items.len;
        while (i > 0) : (i -= 1) {
            self.appendInstruction(deferLabels.items[i - 1]);
            _ = try self.flattenAST(scope, defers.items[i - 1], null, null, null, null, errors, allocator);
        }
    }

    /// Converts the list of IR to a web of BB's
    /// Also versions IR dest's if they are symbvers. This versioning should persist and should not be wiped.
    fn basicBlockFromIR(self: *CFG, maybe_ir: ?*ir_.IR, allocator: std.mem.Allocator) !?*basic_block_.Basic_Block {
        if (maybe_ir == null) {
            return null;
        } else if (maybe_ir.?.in_block) |in_block| {
            return in_block;
        } else {
            var retval: *basic_block_.Basic_Block = try basic_block_.Basic_Block.create(self, allocator);
            retval.ir_head = maybe_ir;
            var _maybe_ir = maybe_ir;
            while (_maybe_ir) |ir| : (_maybe_ir = ir.next) {
                ir.in_block = retval;

                if (ir.dest != null and ir.dest.?.* == .symbver) {
                    ir.dest.?.symbver.makeUnique();
                }

                if (ir.kind == .label) {
                    // If you find a label declaration, end this block and jump to new block
                    retval.has_branch = false;
                    retval.next = try self.basicBlockFromIR(ir.next, allocator);
                    if (ir.next) |_| {
                        ir.next.?.prev = null;
                        ir.next = null;
                    }
                    break;
                } else if (ir.kind == .jump) {
                    // If you find a jump, end this block and start new block
                    retval.has_branch = false;
                    if (ir.data == .branch) {
                        if (ir.data.branch) |branch| {
                            retval.next = try self.basicBlockFromIR(branch.next, allocator);
                        } else {
                            retval.next = try self.basicBlockFromIR(null, allocator);
                        }
                    } else {
                        retval.next = null;
                    }
                    if (ir.next) |_| {
                        ir.next.?.prev = null;
                        ir.next = null;
                    }
                    break;
                } else if (ir.kind == .panic) {
                    // If you find a panic, end this block with null jump and start new block
                    retval.has_branch = false;
                    retval.next = null;
                    retval.has_panic = true;
                    if (ir.next != null and ir.next.?.next != null) {
                        ir.next.?.next.?.prev = null;
                        ir.next.?.next = null;
                    }
                    break;
                } else if (ir.kind == .branchIfFalse) {
                    // If you find a branch, end this block, start both blocks
                    retval.has_branch = true;
                    var branchNext: ?*ir_.IR = null; // = ir.data.branch.next; // Since ir->branch->next may get nullifued by calling this function on ir->next
                    if (ir.data.branch) |branch| {
                        branchNext = branch.next;
                    } else {
                        branchNext = null;
                    }
                    retval.next = try self.basicBlockFromIR(ir.next, allocator);
                    retval.branch = try self.basicBlockFromIR(branchNext, allocator);
                    retval.condition = ir.src1;
                    if (ir.next) |_| {
                        ir.next.?.prev = null;
                        ir.next = null;
                    }
                    break;
                }
            }
            return retval;
        }
    }

    fn removeBasicBlockLastInstruction(cfg: *CFG) void {
        for (cfg.basic_blocks.items) |bb| {
            if (bb.ir_head == null) {
                continue;
            } else if (bb.ir_head.?.next == null) {
                bb.ir_head = null;
            } else {
                var maybe_ir: ?*ir_.IR = bb.ir_head;
                while (maybe_ir.?.next != null) : (maybe_ir = maybe_ir.?.next) {}
                maybe_ir.?.prev.?.next = null;
            }
        }
    }

    // Determines which symbol versions need to be requested as phi parameters, and which need to be passed to children basic-blocks as phi arguments
    pub fn calculatePhiParamsAndArgs(self: *CFG, allocator: std.mem.Allocator) !void {
        // clear arguments
        for (self.basic_blocks.items) |bb| {
            bb.parameters.clearRetainingCapacity();
            bb.next_arguments.clearRetainingCapacity();
            bb.branch_arguments.clearRetainingCapacity();

            // Parameters are symbols used by IR without a definition for the symbol before the IR
            var maybe_ir: ?*ir_.IR = bb.ir_head;
            while (maybe_ir) |ir| : (maybe_ir = ir.next) {
                if (ir.dest != null and ir.dest.?.* != .symbver) {
                    // Recursively version L_Value symbvers, if they are not a leaf symbver.
                    try version_lvalue(ir.dest.?, bb, ir, &bb.parameters);
                }
                if (ir.src1 != null) {
                    // If src1 version is not null, and is not defined in this BB, request it as a parameter
                    try version_lvalue(ir.src1.?, bb, ir, &bb.parameters);
                }
                if (ir.src2 != null) {
                    // If src2 version is not null, and is not defined in this BB, request it as a parameter
                    try version_lvalue(ir.src2.?, bb, ir, &bb.parameters);
                }

                if (ir.data == .lval_list) {
                    // Do the same as above for each symbver in a symbver list, if there is one
                    for (ir.data.lval_list.items) |lval| {
                        try version_lvalue(lval, bb, ir, &bb.parameters);
                    }
                }
            }

            if (bb.has_branch) {
                // Do the same as above for the condition of a branch, if there is one
                try version_lvalue(bb.condition.?, bb, null, &bb.parameters);
            }
        }

        // Find phi arguments
        self.clearVisitedBBs();
        var i: usize = 0;
        while (try self.childrenArgPropagation(self.block_graph_head orelse return, allocator)) {
            self.clearVisitedBBs();
            i += 1;
        }
        self.clearVisitedBBs();
    }

    fn version_lvalue(lval: *lval_.L_Value, bb: *basic_block_.Basic_Block, ir: ?*ir_.IR, parameters: *std.ArrayList(*lval_.Symbol_Version)) !void {
        switch (lval.*) {
            .symbver => {
                var retval = lval.symbver.findVersion(bb.ir_head, ir);
                if (retval.version == null) {
                    _ = try retval.putSymbolVersionSet(parameters);
                }
                lval.symbver = retval;
            },
            .dereference => {
                try version_lvalue(lval.dereference.expr, bb, ir, parameters);
            },
            .index => {
                try version_lvalue(lval.index.rhs, bb, ir, parameters);
                try version_lvalue(lval.index.lhs, bb, ir, parameters);
                if (lval.index.upper_bound != null) {
                    try version_lvalue(lval.index.upper_bound.?, bb, ir, parameters);
                }
            },
            .select => {
                try version_lvalue(lval.select.lhs, bb, ir, parameters);
                if (lval.select.tag != null) {
                    try version_lvalue(lval.select.tag.?, bb, ir, parameters);
                }
            },
        }
    }

    /// Finds the phi *arguments* that each basic block needs to pass along, whereas calculatePhiParamsAndArgs finds the *parameters* it needs to include.
    fn childrenArgPropagation(self: *CFG, bb: *basic_block_.Basic_Block, allocator: std.mem.Allocator) !bool {
        var retval: bool = false;
        if (bb.visited) {
            return false;
        }
        bb.visited = true;

        if (bb.next) |next| {
            // Have the next block request parameters
            retval = try self.childrenArgPropagation(next, allocator) or retval;

            // Go through the parameters the next block requested, see if they exist in this block.
            // Request them if they do not.
            for (next.parameters.items) |param| {
                var symbver = param.findVersion(bb.ir_head, null);
                if (symbver == param) { // Could not find param def in this block, require it as a parameter for this own block
                    const myParam = param.findSymbolVersionSet(&bb.parameters);
                    if (myParam) |_myParam| {
                        symbver = _myParam;
                    } else {
                        symbver = try lval_.Symbol_Version.createUnversioned(param.symbol, allocator);
                        _ = try symbver.putSymbolVersionSet(&bb.parameters);
                    }
                } // else found in this block already, add it to the arguments
                retval = try symbver.putSymbolVersionSet(&bb.next_arguments) or retval;
            }
        }

        if (bb.has_branch) {
            if (bb.branch) |branch| {
                retval = try self.childrenArgPropagation(branch, allocator) or retval;
                for (branch.parameters.items) |param| { // go through branch BB's params
                    var symbver = param.findVersion(bb.ir_head, null); // look for definition of param in this block
                    if (symbver == param) {
                        // Could not find param def in this block, require it as a parameter for this own block
                        const myParam = param.findSymbolVersionSet(&bb.parameters); // see if param is already in block paramlist
                        if (myParam) |_myParam| {
                            symbver = _myParam; // if so, we will add param to arglist
                        } else {
                            // else, create a new param and add to paramlist. (will later be added to arglist too)
                            symbver = try lval_.Symbol_Version.createUnversioned(param.symbol, allocator);
                            _ = try symbver.putSymbolVersionSet(&bb.parameters);
                        }
                    } // else found in this block already, add it to the arguments
                    retval = try symbver.putSymbolVersionSet(&bb.branch_arguments) or retval;
                }
            }
        }

        return retval;
    }
};
