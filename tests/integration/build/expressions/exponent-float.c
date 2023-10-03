/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

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
