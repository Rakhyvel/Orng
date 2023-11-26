/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef uint8_t(*function0)(double);

/* Function forward definitions */
int64_t _459_main(void);
uint8_t _464_f(double _464_x);

/* Function definitions */
int64_t _459_main(void) {
    function0 _459_t1;
    double _459_t3;
    uint8_t _459_t2;
    int64_t _459_t0;
    int64_t _459_$retval;
    _459_t1 = _464_f;
    _459_t3 = 4.0e+00;
    $lines[$line_idx++] = "tests/integration/expressions/mult-zero-float.orng:3:10:\n    if f(4.0) {\n        ^";
    _459_t2 = _459_t1(_459_t3);
    $line_idx--;
    if (_459_t2) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _459_t0 = 188;
    goto BB4;
BB5:
    _459_t0 = 4;
    goto BB4;
BB4:
    _459_$retval = _459_t0;
    return _459_$retval;
}

uint8_t _464_f(double _464_x) {
    uint8_t _464_t5;
    uint8_t _464_t4;
    uint8_t _464_t10;
    uint8_t _464_t9;
    uint8_t _464_t0;
    uint8_t _464_$retval;
    (void)_464_x;
    _464_t5 = 1;
    if (_464_t5) {
        goto BB1;
    } else {
        goto BB10;
    }
BB1:
    _464_t4 = 1;
    goto BB2;
BB10:
    _464_t4 = 0;
    goto BB2;
BB2:
    if (_464_t4) {
        goto BB3;
    } else {
        goto BB9;
    }
BB3:
    _464_t10 = 1;
    if (_464_t10) {
        goto BB4;
    } else {
        goto BB8;
    }
BB9:
    _464_t0 = 0;
    goto BB7;
BB4:
    _464_t9 = 1;
    goto BB5;
BB8:
    _464_t9 = 0;
    goto BB5;
BB7:
    _464_$retval = _464_t0;
    return _464_$retval;
BB5:
    _464_t0 = _464_t9;
    goto BB7;
}

int main(void) {
  printf("%ld",_459_main());
  return 0;
}
