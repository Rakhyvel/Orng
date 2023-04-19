var data = {lines:[
{"lineNum":"    1","line":"const math = @import(\"../math.zig\");"},
{"lineNum":"    2","line":""},
{"lineNum":"    3","line":"/// Returns the nan representation for type T."},
{"lineNum":"    4","line":"pub inline fn nan(comptime T: type) T {"},
{"lineNum":"    5","line":"    return switch (@typeInfo(T).Float.bits) {","class":"lineNoCov","hits":"0","possible_hits":"1",},
{"lineNum":"    6","line":"        16 => math.nan_f16,"},
{"lineNum":"    7","line":"        32 => math.nan_f32,"},
{"lineNum":"    8","line":"        64 => math.nan_f64,","class":"lineNoCov","hits":"0","possible_hits":"1",},
{"lineNum":"    9","line":"        80 => math.nan_f80,"},
{"lineNum":"   10","line":"        128 => math.nan_f128,"},
{"lineNum":"   11","line":"        else => @compileError(\"unreachable\"),"},
{"lineNum":"   12","line":"    };"},
{"lineNum":"   13","line":"}"},
{"lineNum":"   14","line":""},
{"lineNum":"   15","line":"/// Returns the signalling nan representation for type T."},
{"lineNum":"   16","line":"/// Note: A signalling nan is identical to a standard right now by may have a different bit"},
{"lineNum":"   17","line":"/// representation in the future when required."},
{"lineNum":"   18","line":"pub inline fn snan(comptime T: type) T {"},
{"lineNum":"   19","line":"    return nan(T);"},
{"lineNum":"   20","line":"}"},
]};
var percent_low = 25;var percent_high = 75;
var header = { "command" : "test", "date" : "2023-04-18 20:41:50", "instrumented" : 2, "covered" : 0,};
var merged_data = [];
