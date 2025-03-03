//! This file represents a struct for an AST walk, and walks over the AST and performs simple, local expansions on
//! it.

const std = @import("std");
const ast_ = @import("../ast/ast.zig");
const errs_ = @import("../util/errors.zig");
const primitives_ = @import("../hierarchy/primitives.zig");
const token_ = @import("../lexer/token.zig");
const walk_ = @import("../ast/walker.zig");

errors: *errs_.Errors,
allocator: std.mem.Allocator,

const Self = @This();

pub fn new(errors: *errs_.Errors, allocator: std.mem.Allocator) Self {
    return Self{
        .errors = errors,
        .allocator = allocator,
    };
}

/// Expand ASTs before descending to further children
pub fn prefix(self: Self, ast: *ast_.AST) walk_.Error!?Self {
    switch (ast.*) {
        else => {},

        .sum_type => {
            var changed = false;
            var new_terms = std.ArrayList(*ast_.AST).init(self.allocator);
            var idents_seen = std.StringArrayHashMap(*ast_.AST).init(self.allocator);
            defer idents_seen.deinit();
            errdefer new_terms.deinit();

            // Make sure identifiers aren't repeated
            for (ast.children().items) |term| {
                changed = changed or term.* == .identifier;
                var annotation: *ast_.AST = try annot_from_ast(term, self.errors, self.allocator);
                new_terms.append(annotation) catch unreachable;
                const name = annotation.annotation.pattern.token().data;
                const res = idents_seen.fetchPut(name, annotation) catch unreachable;
                if (res) |_res| {
                    self.errors.add_error(errs_.Error{
                        .duplicate = .{ .span = term.token().span, .identifier = name, .first = _res.value.token().span },
                    });
                    return error.CompileError;
                }
            }

            if (changed) {
                ast.set_children(new_terms);
            } else {
                new_terms.deinit();
            }
        },

        .sub_slice => {
            if (ast.sub_slice.lower == null) {
                ast.sub_slice.lower = ast_.AST.create_int(ast.token(), 0, self.allocator);
            }
            if (ast.sub_slice.upper == null) {
                const length = ast_.AST.create_field(token_.Token.init("length", null, "", "", 0, 0), self.allocator);
                ast.sub_slice.upper = ast_.AST.create_select(
                    ast.token(),
                    ast.sub_slice.super,
                    length,
                    self.allocator,
                );
            }
        },
    }

    return self;
}

fn annot_from_ast(ast: *ast_.AST, errors: *errs_.Errors, allocator: std.mem.Allocator) walk_.Error!*ast_.AST {
    if (ast.* == .annotation) {
        return ast;
    } else if (ast.* == .identifier) {
        return ast_.AST.create_annotation(ast.token(), ast, primitives_.unit_type, null, null, allocator).assert_ast_valid();
    } else {
        errors.add_error(errs_.Error{ .basic = .{
            .span = ast.token().span,
            .msg = "invalid sum expression, must be annotation or identifier",
        } });
        return error.CompileError;
    }
}
