/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

/* Debug information */
static const char* $lines[1024];
static uint16_t $line_idx = 0;

inline static void $panic(const char *restrict msg) {
    fprintf(stderr, "panic: %s\n", msg);
    for(uint16_t $i = 0; $i < $line_idx; $i++) {
        fprintf(stderr, "%s\n", $lines[$line_idx - $i - 1]);
    }
    exit(1);
}

inline static void $bounds_check(const int64_t idx, const int64_t length, const char *restrict line) {
    if (0 > idx || idx >= length) {
        $lines[$line_idx++] = line;
        $panic("bounds check failed");
    }
}

inline static void $tag_check(const int64_t tag, const int64_t sel, const char *restrict line) {
    if (tag != sel) {
        $lines[$line_idx++] = line;
        $panic("inactive field");
    }
}
/* Function forward definitions */
int64_t _2_main();
uint8_t _7_close_enough(double _7_a,double _7_b,double _7_e);

/* Function definitions */
int64_t _2_main() {
    uint8_t _2_t1;
    int64_t _2_t0;
    int64_t _2_$retval;
    $lines[$line_idx++] = "tests/integration/expressions/exponent-float.orng:3:21:\n    if close_enough(2.0 ** 4.0, 16.0, 0.01) {\n                   ^";
    _2_t1 = _7_close_enough(1.6e+01, 1.6e+01, 1.0e-02);
    $line_idx--;
    if (_2_t1) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _2_t0 = 193;
    goto BB4;
BB5:
    _2_t0 = 4;
BB4:
    _2_$retval = _2_t0;
    return _2_$retval;
}

uint8_t _7_close_enough(double _7_a,double _7_b,double _7_e) {
    uint8_t _7_$retval;
    uint8_t _7_t7;
    double _7_t3;
    if (_7_a == _7_b) {
        goto BB3;
    } else {
        goto BB4;
    }
BB3:
    _7_$retval = 1;
    return _7_$retval;
BB4:
    if (_7_a > _7_b) {
        goto BB7;
    } else {
        goto BB15;
    }
BB7:
    _7_t3 = _7_a - _7_b;
    goto BB9;
BB15:
    _7_t3 = _7_b - _7_a;
BB9:
    _7_t7 = _7_t3 <= _7_e;
    if (_7_t7) {
        goto BB11;
    } else {
        goto BB14;
    }
BB11:
    _7_t7 = 1;
    goto BB13;
BB14:
    _7_t7 = 0;
BB13:
    _7_$retval = _7_t7;
    return _7_$retval;
}

int main()
{
  printf("%ld",_2_main());
  return 0;
}
