/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef uint8_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _445_main(void);
uint8_t _450_f(int64_t _450_x);

/* Function definitions */
int64_t _445_main(void) {
    function0 _445_t1;
    int64_t _445_t3;
    uint8_t _445_t2;
    int64_t _445_t0;
    int64_t _445_$retval;
    _445_t1 = _450_f;
    _445_t3 = 4;
    $lines[$line_idx++] = "tests/integration/expressions/mult-1.orng:3:10:\n    if f(4) {\n        ^";
    _445_t2 = _445_t1(_445_t3);
    $line_idx--;
    if (_445_t2) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _445_t0 = 186;
    goto BB4;
BB5:
    _445_t0 = 4;
    goto BB4;
BB4:
    _445_$retval = _445_t0;
    return _445_$retval;
}

uint8_t _450_f(int64_t _450_x) {
    uint8_t _450_t4;
    uint8_t _450_t3;
    uint8_t _450_t8;
    uint8_t _450_t7;
    uint8_t _450_t0;
    uint8_t _450_$retval;
    (void)_450_x;
    _450_t4 = 1;
    if (_450_t4) {
        goto BB1;
    } else {
        goto BB10;
    }
BB1:
    _450_t3 = 1;
    goto BB2;
BB10:
    _450_t3 = 0;
    goto BB2;
BB2:
    if (_450_t3) {
        goto BB3;
    } else {
        goto BB9;
    }
BB3:
    _450_t8 = 1;
    if (_450_t8) {
        goto BB4;
    } else {
        goto BB8;
    }
BB9:
    _450_t0 = 0;
    goto BB7;
BB4:
    _450_t7 = 1;
    goto BB5;
BB8:
    _450_t7 = 0;
    goto BB5;
BB7:
    _450_$retval = _450_t0;
    return _450_$retval;
BB5:
    _450_t0 = _450_t7;
    goto BB7;
}

int main(void) {
  printf("%ld",_445_main());
  return 0;
}
