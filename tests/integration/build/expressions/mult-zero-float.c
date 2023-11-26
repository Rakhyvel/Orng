/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef uint8_t(*function0)(double);

/* Function forward definitions */
int64_t _154_main(void);
uint8_t _159_f(double _159_x);

/* Function definitions */
int64_t _154_main(void) {
    function0 _154_t1;
    double _154_t3;
    uint8_t _154_t2;
    int64_t _154_t0;
    int64_t _154_$retval;
    _154_t1 = _159_f;
    _154_t3 = 4.0e+00;
    $lines[$line_idx++] = "tests/integration/expressions/mult-zero-float.orng:3:10:\n    if f(4.0) {\n        ^";
    _154_t2 = _154_t1(_154_t3);
    $line_idx--;
    if (_154_t2) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _154_t0 = 188;
    goto BB4;
BB5:
    _154_t0 = 4;
    goto BB4;
BB4:
    _154_$retval = _154_t0;
    return _154_$retval;
}

uint8_t _159_f(double _159_x) {
    uint8_t _159_t5;
    uint8_t _159_t4;
    uint8_t _159_t10;
    uint8_t _159_t9;
    uint8_t _159_t0;
    uint8_t _159_$retval;
    (void)_159_x;
    _159_t5 = 1;
    if (_159_t5) {
        goto BB1;
    } else {
        goto BB10;
    }
BB1:
    _159_t4 = 1;
    goto BB2;
BB10:
    _159_t4 = 0;
    goto BB2;
BB2:
    if (_159_t4) {
        goto BB3;
    } else {
        goto BB9;
    }
BB3:
    _159_t10 = 1;
    if (_159_t10) {
        goto BB4;
    } else {
        goto BB8;
    }
BB9:
    _159_t0 = 0;
    goto BB7;
BB4:
    _159_t9 = 1;
    goto BB5;
BB8:
    _159_t9 = 0;
    goto BB5;
BB7:
    _159_$retval = _159_t0;
    return _159_$retval;
BB5:
    _159_t0 = _159_t9;
    goto BB7;
}

int main(void) {
  printf("%ld",_154_main());
  return 0;
}
