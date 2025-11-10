var data = {lines:[
{"lineNum":"    1","line":"const std = @import(\"std\");"},
{"lineNum":"    2","line":""},
{"lineNum":"    3","line":"const Self = @This();"},
{"lineNum":"    4","line":"allocator: std.mem.Allocator,"},
{"lineNum":"    5","line":""},
{"lineNum":"    6","line":"pub fn init(allocator: std.mem.Allocator) Self {","class":"lineCov","hits":"1","order":"4303","possible_hits":"1",},
{"lineNum":"    7","line":"    return .{ .allocator = allocator };","class":"lineCov","hits":"1","order":"4304","possible_hits":"1",},
{"lineNum":"    8","line":"}"},
{"lineNum":"    9","line":""},
{"lineNum":"   10","line":"pub fn run(self: Self, absolute_path: []const u8) error{FileNotFound}![]const u8 {","class":"lineCov","hits":"2","order":"4305","possible_hits":"2",},
{"lineNum":"   11","line":"    var file = std.fs.openFileAbsolute(absolute_path, .{}) catch return error.FileNotFound;","class":"lineCov","hits":"2","order":"4306","possible_hits":"2",},
{"lineNum":"   12","line":"    defer file.close();","class":"lineCov","hits":"1","order":"4309","possible_hits":"1",},
{"lineNum":"   13","line":""},
{"lineNum":"   14","line":"    const stat = file.stat() catch unreachable;","class":"lineCov","hits":"2","order":"4307","possible_hits":"2",},
{"lineNum":"   15","line":"    const contents = file.readToEndAlloc(self.allocator, stat.size) catch unreachable;","class":"lineCov","hits":"3","order":"4308","possible_hits":"3",},
{"lineNum":"   16","line":"    return contents;","class":"lineCov","hits":"1","order":"4310","possible_hits":"1",},
{"lineNum":"   17","line":"}"},
]};
var percent_low = 25;var percent_high = 75;
var header = { "command" : "orng-test", "date" : "2025-11-10 15:43:08", "instrumented" : 8, "covered" : 8,};
var merged_data = [];
