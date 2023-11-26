/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef uint8_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _467_main(void);
uint8_t _472_f(int64_t _472_x);

/* Function definitions */
int64_t _467_main(void) {
    function0 _467_t1;
    int64_t _467_t3;
    uint8_t _467_t2;
    int64_t _467_t0;
    int64_t _467_$retval;
    _467_t1 = _472_f;
    _467_t3 = 4;
    $lines[$line_idx++] = "tests/integration/expressions/mult-zero-int.orng:3:10:\n    if f(4) {\n        ^";
    _467_t2 = _467_t1(_467_t3);
    $line_idx--;
    if (_467_t2) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _467_t0 = 187;
    goto BB4;
BB5:
    _467_t0 = 4;
    goto BB4;
BB4:
    _467_$retval = _467_t0;
    return _467_$retval;
}

uint8_t _472_f(int64_t _472_x) {
    uint8_t _472_t5;
    uint8_t _472_t4;
    uint8_t _472_t10;
    uint8_t _472_t9;
    uint8_t _472_t0;
    uint8_t _472_$retval;
    (void)_472_x;
    _472_t5 = 1;
    if (_472_t5) {
        goto BB1;
    } else {
        goto BB10;
    }
BB1:
    _472_t4 = 1;
    goto BB2;
BB10:
    _472_t4 = 0;
    goto BB2;
BB2:
    if (_472_t4) {
        goto BB3;
    } else {
        goto BB9;
    }
BB3:
    _472_t10 = 1;
    if (_472_t10) {
        goto BB4;
    } else {
        goto BB8;
    }
BB9:
    _472_t0 = 0;
    goto BB7;
BB4:
    _472_t9 = 1;
    goto BB5;
BB8:
    _472_t9 = 0;
    goto BB5;
BB7:
    _472_$retval = _472_t0;
    return _472_$retval;
BB5:
    _472_t0 = _472_t9;
    goto BB7;
}

int main(void) {
  printf("%ld",_467_main());
  return 0;
}
