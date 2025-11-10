var data = {lines:[
{"lineNum":"    1","line":"const Self = @This();"},
{"lineNum":"    2","line":""},
{"lineNum":"    3","line":"scope_uid: usize = 0,"},
{"lineNum":"    4","line":""},
{"lineNum":"    5","line":"pub fn init() Self {","class":"lineCov","hits":"1","order":"206","possible_hits":"1",},
{"lineNum":"    6","line":"    return .{ .scope_uid = 0 };","class":"lineCov","hits":"1","order":"207","possible_hits":"1",},
{"lineNum":"    7","line":"}"},
{"lineNum":"    8","line":""},
{"lineNum":"    9","line":"pub fn uid(self: *@This()) usize {","class":"lineCov","hits":"2","order":"218","possible_hits":"2",},
{"lineNum":"   10","line":"    const retval = self.scope_uid;","class":"lineCov","hits":"1","order":"219","possible_hits":"1",},
{"lineNum":"   11","line":"    self.scope_uid += 1;","class":"lineCov","hits":"1","order":"220","possible_hits":"1",},
{"lineNum":"   12","line":"    return retval;","class":"lineCov","hits":"1","order":"221","possible_hits":"1",},
{"lineNum":"   13","line":"}"},
]};
var percent_low = 25;var percent_high = 75;
var header = { "command" : "orng-test", "date" : "2025-11-10 15:43:08", "instrumented" : 6, "covered" : 6,};
var merged_data = [];
