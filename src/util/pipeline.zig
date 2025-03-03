//! This file defines a generic data pipeline framework. It allows a sequence of processing steps to be applied, where
//! each step builds off the results of the previous. This design allows modular and reusable components, and simplifies
//! complex transformations.
const std = @import("std");

/// The main function to execute a pipeline.
///
/// Takes a pipeline (anonymous struct value) of steps (values of struct types which implement the `run` method, and an
/// inital value. The function feeds the initial value to the first step, which produces an output. Then feeds that
/// output to the next step, and so on. Returns the final output, or an error if any occured.
pub fn run(initial_value: anytype, pipeline: anytype) !ProcessResult(@TypeOf(pipeline), @TypeOf(initial_value), pipeline.len -| 1) {
    if (pipeline.len == 0) {
        // If the pipeline is empty, the initial value is unchanged
        return initial_value;
    } else {
        // Run the first pipeline
        return run_inner(initial_value, pipeline, 0);
    }
}

/// Recursive helper function to process the step at `step_index` in the `pipeline` struct.
fn run_inner(previous_value: anytype, pipeline: anytype, comptime step_index: usize) !ProcessResult(@TypeOf(pipeline), @TypeOf(previous_value), pipeline.len -| 1) {
    // Get the step struct for this step
    const PipelineType = @TypeOf(pipeline);
    const fields = std.meta.fields(PipelineType);
    const field = fields[step_index];
    var step = @field(pipeline, field.name);

    // Run the step on the previous value
    const run_result = try step.run(previous_value);

    if (step_index + 1 == fields.len) {
        // If this is the last step, just return the run result
        return run_result;
    } else {
        // Otherwise, pass run result to next step
        return run_inner(run_result, pipeline, step_index + 1);
    }
}

/// Helper function to get the return type of the pipeline, and each intermediate step.
fn ProcessResult(comptime PipelineType: type, comptime InitialType: type, comptime i: usize) type {
    const fields = std.meta.fields(PipelineType);

    if (fields.len == 0) {
        return InitialType;
    }

    const Step_Type = fields[i].type;
    const RunFnType = @TypeOf(Step_Type.run);
    const fn_info = @typeInfo(RunFnType).Fn;
    // Get the return type, extracting from error union if needed
    const return_type = fn_info.return_type.?;
    return switch (@typeInfo(return_type)) {
        .ErrorUnion => |eu| eu.payload,
        else => return_type,
    };
}

test "test-pipeline" {
    const Get_Length: type = struct {
        const Self: type = @This();

        pub fn init() Self {
            return .{};
        }

        pub fn run(self: *Self, str: []const u8) error{CompileError}!usize {
            _ = self;
            return str.len;
        }
    };

    const Add: type = struct {
        const Self: type = @This();
        addend: usize,

        pub fn init(addend: usize) Self {
            return .{ .addend = addend };
        }

        pub fn run(self: *Self, x: usize) error{CompileError}!usize {
            return self.addend + x;
        }
    };

    const res = try run("Hello, World!", .{ Get_Length.init(), Add.init(4) });

    try std.testing.expectEqual(res, 17);
}

test "empty-pipeline" {
    const res = try run(435, .{});
    try std.testing.expectEqual(res, 435);
}
