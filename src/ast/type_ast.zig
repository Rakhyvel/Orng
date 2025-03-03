const std = @import("std");
const AST = @import("ast.zig").AST;

pub const Type_AST = struct {
    inner: *AST,

    /// Retrieves either the `ok` or `some` type from either an optional type or an error type
    pub fn get_nominal_type(opt_or_error_sum: Type_AST) *AST {
        std.debug.assert(opt_or_error_sum.inner.sum_type.from == .optional or opt_or_error_sum.inner.sum_type.from == .@"error");
        return opt_or_error_sum.inner.children().items[0];
    }

    pub fn get_some_type(opt_sum: Type_AST) *AST {
        std.debug.assert(opt_sum.inner.sum_type.from == .optional);
        return opt_sum.inner.children().items[0];
    }

    pub fn get_none_type(opt_sum: Type_AST) *AST {
        std.debug.assert(opt_sum.inner.sum_type.from == .optional);
        return opt_sum.inner.children().items[1];
    }

    pub fn get_ok_type(err_union: Type_AST) *AST {
        std.debug.assert(err_union.inner.sum_type.from == .@"error");
        return err_union.inner.children().items[0];
    }

    pub fn get_err_type(err_union: Type_AST) *AST {
        std.debug.assert(err_union.inner.sum_type.from == .@"error");
        return err_union.inner.children().items[1];
    }

    /// Recursively goes through types that contain `Self`, and replaces them with the impl-for type
    pub fn convert_self_type(
        trait_type: Type_AST, // the type specified by the trait, potentially `Self`
        for_type: Type_AST, // the type the trait is being implemented for
        allocator: std.mem.Allocator,
    ) Type_AST {
        switch (trait_type.inner.*) {
            .anyptr_type, .dyn_type, .unit_type => return trait_type,
            .identifier => if (std.mem.eql(u8, trait_type.token().data, "Self")) {
                return for_type;
            } else {
                return trait_type;
            },
            .addr_of => {
                const _expr = convert_self_type(trait_type.inner.expr(), for_type, allocator);
                return AST.create_addr_of(trait_type.inner.token(), _expr, trait_type.inner.mut(), trait_type.inner.addr_of.multiptr, allocator);
            },
            .slice_of => {
                const _expr = convert_self_type(trait_type.inner.expr(), for_type, allocator);
                return AST.create_slice_of(trait_type.inner.token(), _expr, trait_type.inner.slice_of.mut, allocator);
            },
            .array_of => {
                const _expr = convert_self_type(trait_type.inner.expr(), for_type, allocator);
                return AST.create_array_of(trait_type.inner.token(), _expr, trait_type.inner.array_of.len, allocator);
            },
            .annotation => {
                const _type = convert_self_type(trait_type.inner.annotation.type, for_type, allocator);
                return AST.create_annotation(trait_type.inner.token(), trait_type.inner.annotation.pattern, _type, trait_type.inner.annotation.predicate, trait_type.inner.annotation.init, allocator);
            },
            .function => {
                const _lhs = convert_self_type(trait_type.inner.lhs(), for_type, allocator);
                const _rhs = convert_self_type(trait_type.inner.rhs(), for_type, allocator);
                return AST.create_function(trait_type.inner.token(), _lhs, _rhs, allocator);
            },
            .@"union" => {
                const _lhs = convert_self_type(trait_type.inner.lhs(), for_type, allocator);
                const _rhs = convert_self_type(trait_type.inner.rhs(), for_type, allocator);
                return AST.create_union(trait_type.inner.token(), _lhs, _rhs, allocator);
            },
            .sum_type => {
                var new_children = std.ArrayList(*AST).init(allocator);
                for (trait_type.inner.children().items) |item| {
                    const new_type = item.convert_self_type(for_type, allocator);
                    new_children.append(new_type) catch unreachable;
                }
                var retval = AST.create_sum_type(trait_type.inner.token(), new_children, allocator);
                retval.sum_type.from = trait_type.inner.sum_type.from;
                // NOTE: Do NOT copy over the `all_unit` type, as Self could be unit. Leave it null to be re-evaluated.
                return retval;
            },
            else => std.debug.panic("compiler error: convert_self_type doesn't support trait type AST `{s}`", .{@tagName(trait_type.inner.*)}),
        }
    }

    pub fn refers_to_self(_type: Type_AST) bool {
        return switch (_type.inner.*) {
            .anyptr_type, .unit_type, .dyn_type => false,
            .identifier => std.mem.eql(u8, _type.inner.token().data, "Self"),
            .addr_of, .slice_of, .array_of => _type.inner.expr().refers_to_self(),
            .annotation => _type.inner.annotation.type.refers_to_self(),
            .function, .@"union" => _type.inner.lhs().refers_to_self() or _type.inner.rhs().refers_to_self(),
            .product, .sum_type => {
                for (_type.inner.children().items) |item| {
                    if (item.refers_to_self()) {
                        return true;
                    }
                }
                return false;
            },
            // I think everything above covers everything, but just in case, error out
            else => true,
        };
    }

    /// Determines if an AST can structurally refer to a type. This is looser than if an AST value is Type typed, as
    /// some ASTs that pass this check might fail `types_match(primitives_.type_type)`.
    ///
    /// The types_match() function assumes it's arguments pass this test.
    pub fn valid_type(_type: Type_AST) bool {
        const val = switch (_type.inner.*) {
            // Always well-formed, comptime types
            .type_of,
            .domain_of,
            .anyptr_type,
            .unit_type,
            .dyn_type,
            .call,
            .invoke,
            .poison,
            .identifier,
            .access,
            .pattern_symbol,
            .untagged_sum_type,
            => true,

            // Anything else probably isn't a valid type
            else => _type.inner.common().ok_for_comptime, // HACK: This allows generic functions to return a type without surrounding it in a comptime block

            // Recursive
            .index => _type.inner.lhs().valid_type(), // Used by pattern matching, lhs is the array_of type, rhs is the index
            .addr_of, .slice_of, .array_of => _type.inner.expr().valid_type(),
            .annotation => _type.inner.annotation.type.valid_type(),
            .function, .@"union" => _type.inner.lhs().valid_type() and _type.inner.rhs().valid_type(),
            .product, .sum_type => {
                for (_type.inner.children().items) |item| {
                    if (!item.valid_type()) {
                        return false;
                    }
                }
                return true;
            },
        };
        return val;
    }

    pub fn non_comptime_type(_type: Type_AST) bool {
        return switch (_type.inner.*) {
            .@"comptime" => false,
            else => true,

            // Recursive
            .index => _type.inner.lhs().non_comptime_type(), // Used by pattern matching, lhs is the array_of type, rhs is the index
            .addr_of, .slice_of, .array_of => _type.inner.expr().non_comptime_type(),
            .annotation => _type.inner.annotation.type.non_comptime_type(),
            .function, .@"union" => _type.inner.lhs().non_comptime_type() and _type.inner.rhs().non_comptime_type(),
            .product, .sum_type => {
                for (_type.inner.children().items) |item| {
                    if (!item.non_comptime_type()) {
                        return false;
                    }
                }
                return true;
            },
        };
    }

    /// Expands an ast one level if it is an identifier
    pub fn expand_identifier(self: Type_AST) Type_AST {
        if ((self.inner.* == .identifier or self.inner.* == .access) and self.inner.symbol().?.init != null) {
            const init = self.inner.symbol().?.init.?;
            return init;
        } else {
            return self;
        }
    }
};
