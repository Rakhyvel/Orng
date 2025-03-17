const std = @import("std");

const Self = @This();

json_module_hash_map: ?std.json.Value,
json_absolute_path: []const u8,

pub fn init(package_absolute_path: []const u8, allocator: std.mem.Allocator) !Self {
    const json_absolute_paths = [_][]const u8{ package_absolute_path, "build", "hash.json" };
    const json_absolute_path = std.fs.path.join(allocator, &json_absolute_paths) catch unreachable;
    const contents = read_contents(json_absolute_path, allocator) catch |err| switch (err) {
        error.FileNotFound => return Self{ .json_module_hash_map = null, .json_absolute_path = json_absolute_path },
        else => return error.CompileError,
    };
    const parsed = std.json.parseFromSlice(std.json.Value, allocator, contents, .{}) catch
        return Self{ .json_module_hash_map = null, .json_absolute_path = json_absolute_path };
    return Self{
        .json_module_hash_map = parsed.value,
        .json_absolute_path = json_absolute_path,
    };
}

fn read_contents(absolute_path: []const u8, allocator: std.mem.Allocator) ![]const u8 {
    var file = std.fs.openFileAbsolute(absolute_path, .{}) catch |err| switch (err) {
        error.FileNotFound => return error.FileNotFound,
        else => return error.CompileError,
    };
    defer file.close();

    const stat = file.stat() catch return error.CompileError;
    const uid = stat.mtime;
    _ = uid;

    // Read in the contents of the file
    var buf_reader = std.io.bufferedReader(file.reader());
    var in_stream = buf_reader.reader();
    var contents_arraylist = std.ArrayList(u8).init(allocator);
    defer contents_arraylist.deinit();
    in_stream.readAllArrayList(&contents_arraylist, 0xFFFF_FFFF) catch unreachable;
    const contents = contents_arraylist.toOwnedSlice() catch unreachable;

    return contents;
}

pub fn get_module_stored_hash(self: *Self, module_name: []const u8) ?[]const u8 {
    if (self.json_module_hash_map) |old_json_map| {
        const module_lookup_res = old_json_map.object.get(module_name) orelse return null;
        return module_lookup_res.string;
    } else {
        return null;
    }
}

pub fn set_module_hash(self: *Self, module_name: []const u8, hash_number_string: []const u8, allocator: std.mem.Allocator) !void {
    if (self.json_module_hash_map == null) {
        self.json_module_hash_map = (std.json.parseFromSlice(std.json.Value, allocator, "{}", .{}) catch unreachable).value;
    }

    self.json_module_hash_map.?.object.put(module_name, std.json.Value{ .string = hash_number_string }) catch unreachable;
}

pub fn output_new_json(self: *Self) void {
    var json_file_handle = std.fs.createFileAbsolute(self.json_absolute_path, .{}) catch unreachable;
    defer json_file_handle.close();
    const writer = json_file_handle.writer();
    std.json.stringify(self.json_module_hash_map.?, .{}, writer) catch unreachable;
}
