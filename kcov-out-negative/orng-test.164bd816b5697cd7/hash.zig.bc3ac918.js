var data = {lines:[
{"lineNum":"    1","line":"//! This file is responsible for calculating the hash of a module, to track changes"},
{"lineNum":"    2","line":""},
{"lineNum":"    3","line":"const std = @import(\"std\");"},
{"lineNum":"    4","line":""},
{"lineNum":"    5","line":"const Self = @This();"},
{"lineNum":"    6","line":""},
{"lineNum":"    7","line":"module_contents_hash: *u64,"},
{"lineNum":"    8","line":""},
{"lineNum":"    9","line":"pub fn init(module_contents_hash: *u64) Self {","class":"lineCov","hits":"2","order":"486","possible_hits":"2",},
{"lineNum":"   10","line":"    return Self{","class":"lineCov","hits":"1","order":"487","possible_hits":"1",},
{"lineNum":"   11","line":"        .module_contents_hash = module_contents_hash,"},
{"lineNum":"   12","line":"    };"},
{"lineNum":"   13","line":"}"},
{"lineNum":"   14","line":""},
{"lineNum":"   15","line":"pub fn run(self: *Self, contents: []const u8) error{}![]const u8 {","class":"lineCov","hits":"2","order":"533","possible_hits":"2",},
{"lineNum":"   16","line":"    self.module_contents_hash.* = std.hash.XxHash3.hash(0, contents);","class":"lineCov","hits":"1","order":"534","possible_hits":"1",},
{"lineNum":"   17","line":"    return contents;","class":"lineCov","hits":"1","order":"535","possible_hits":"1",},
{"lineNum":"   18","line":"}"},
]};
var percent_low = 25;var percent_high = 75;
var header = { "command" : "orng-test", "date" : "2025-11-10 15:43:08", "instrumented" : 5, "covered" : 5,};
var merged_data = [];
