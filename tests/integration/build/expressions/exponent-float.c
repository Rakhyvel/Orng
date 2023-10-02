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
int64_t _1_main();
uint8_t _6_close_enough(double _6_a,double _6_b,double _6_e);

/* Function definitions */
int64_t _1_main() {
    uint8_t _1_t1;
    int64_t _1_t0;
    int64_t _1_$retval;
    $lines[$line_idx++] = "tests/integration/expressions/exponent-float.orng:3:21:\n    if close_enough(2.0 ** 4.0, 16.0, 0.01) {\n                   ^";
    _1_t1 = _6_close_enough(1.6e+01, 1.6e+01, 1.0e-02);
    $line_idx--;
    if (_1_t1) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _1_t0 = 193;
    goto BB4;
BB5:
    _1_t0 = 4;
BB4:
    _1_$retval = _1_t0;
    return _1_$retval;
}

uint8_t _6_close_enough(double _6_a,double _6_b,double _6_e) {
    uint8_t _6_$retval;
    double _6_t3;
    if (_6_a == _6_b) {
        goto BB1;
    } else {
        goto BB2;
    }
BB1:
    _6_$retval = 1;
    return _6_$retval;
BB2:
    if (_6_a > _6_b) {
        goto BB3;
    } else {
        goto BB8;
    }
BB3:
    _6_t3 = _6_a - _6_b;
    goto BB5;
BB8:
    _6_t3 = _6_b - _6_a;
BB5:
    _6_$retval = _6_t3 <= _6_e;
    return _6_$retval;
}

int main()
{
  printf("%ld",_1_main());
  return 0;
}
