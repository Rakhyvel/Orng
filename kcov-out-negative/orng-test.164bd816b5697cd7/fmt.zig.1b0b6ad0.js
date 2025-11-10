var data = {lines:[
{"lineNum":"    1","line":"const std = @import(\"std\");"},
{"lineNum":"    2","line":""},
{"lineNum":"    3","line":"pub fn List_Printer(Elem: type) type {"},
{"lineNum":"    4","line":"    return struct {"},
{"lineNum":"    5","line":"        list: *const std.array_list.Managed(*Elem),"},
{"lineNum":"    6","line":"        pub fn format(self: *const @This(), writer: *std.io.Writer) !void {","class":"lineNoCov","hits":"0","possible_hits":"4",},
{"lineNum":"    7","line":"            try writer.print(\"[\", .{});","class":"lineNoCov","hits":"0","possible_hits":"2",},
{"lineNum":"    8","line":"            for (self.list.items, 0..) |item, i| {","class":"lineNoCov","hits":"0","possible_hits":"6",},
{"lineNum":"    9","line":"                try writer.print(\"{f}\", .{item});","class":"lineNoCov","hits":"0","possible_hits":"4",},
{"lineNum":"   10","line":"                if (i < self.list.items.len -| 1) {","class":"lineNoCov","hits":"0","possible_hits":"2",},
{"lineNum":"   11","line":"                    try writer.print(\", \", .{});","class":"lineNoCov","hits":"0","possible_hits":"4",},
{"lineNum":"   12","line":"                }"},
{"lineNum":"   13","line":"            }","class":"lineNoCov","hits":"0","possible_hits":"6",},
{"lineNum":"   14","line":"            try writer.print(\"]\", .{});","class":"lineNoCov","hits":"0","possible_hits":"4",},
{"lineNum":"   15","line":"        }"},
{"lineNum":"   16","line":"    };"},
{"lineNum":"   17","line":"}"},
]};
var percent_low = 25;var percent_high = 75;
var header = { "command" : "orng-test", "date" : "2025-11-10 15:43:08", "instrumented" : 8, "covered" : 0,};
var merged_data = [];
