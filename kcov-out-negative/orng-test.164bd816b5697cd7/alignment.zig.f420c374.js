var data = {lines:[
{"lineNum":"    1","line":"const std = @import(\"std\");"},
{"lineNum":"    2","line":""},
{"lineNum":"    3","line":"pub fn next_alignment(address: i64, align_to: i64) i64 {","class":"lineCov","hits":"2","order":"2816","possible_hits":"2",},
{"lineNum":"    4","line":"    // std.debug.print(\"align_to:{}\\n\", .{align_to});"},
{"lineNum":"    5","line":"    std.debug.assert(align_to == 1 or align_to == 2 or align_to == 4 or align_to == 8);","class":"lineCov","hits":"2","order":"2817","possible_hits":"2",},
{"lineNum":"    6","line":"    if (address == 0) {","class":"lineCov","hits":"1","order":"2818","possible_hits":"1",},
{"lineNum":"    7","line":"        return address;","class":"lineCov","hits":"1","order":"2819","possible_hits":"1",},
{"lineNum":"    8","line":"    } else if (address > 0) {","class":"lineCov","hits":"1","order":"2826","possible_hits":"1",},
{"lineNum":"    9","line":"        const div = @divTrunc(address - 1, align_to);","class":"linePartCov","hits":"2","order":"2827","possible_hits":"3",},
{"lineNum":"   10","line":"        return div * align_to + align_to;","class":"linePartCov","hits":"1","order":"2828","possible_hits":"2",},
{"lineNum":"   11","line":"    } else {"},
{"lineNum":"   12","line":"        // needed because offsets can sometimes be negative!"},
{"lineNum":"   13","line":"        const div = @divTrunc(address + 1, align_to);","class":"lineNoCov","hits":"0","possible_hits":"3",},
{"lineNum":"   14","line":"        return div * align_to - align_to;","class":"lineNoCov","hits":"0","possible_hits":"2",},
{"lineNum":"   15","line":"    }"},
{"lineNum":"   16","line":"}"},
]};
var percent_low = 25;var percent_high = 75;
var header = { "command" : "orng-test", "date" : "2025-11-10 15:43:08", "instrumented" : 9, "covered" : 7,};
var merged_data = [];
