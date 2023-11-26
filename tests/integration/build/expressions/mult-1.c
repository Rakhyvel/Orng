/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef uint8_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _140_main(void);
uint8_t _145_f(int64_t _145_x);

/* Function definitions */
int64_t _140_main(void) {
    function0 _140_t1;
    int64_t _140_t3;
    uint8_t _140_t2;
    int64_t _140_t0;
    int64_t _140_$retval;
    _140_t1 = _145_f;
    _140_t3 = 4;
    $lines[$line_idx++] = "tests/integration/expressions/mult-1.orng:3:10:\n    if f(4) {\n        ^";
    _140_t2 = _140_t1(_140_t3);
    $line_idx--;
    if (_140_t2) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _140_t0 = 186;
    goto BB4;
BB5:
    _140_t0 = 4;
    goto BB4;
BB4:
    _140_$retval = _140_t0;
    return _140_$retval;
}

uint8_t _145_f(int64_t _145_x) {
    uint8_t _145_t4;
    uint8_t _145_t3;
    uint8_t _145_t8;
    uint8_t _145_t7;
    uint8_t _145_t0;
    uint8_t _145_$retval;
    (void)_145_x;
    _145_t4 = 1;
    if (_145_t4) {
        goto BB1;
    } else {
        goto BB10;
    }
BB1:
    _145_t3 = 1;
    goto BB2;
BB10:
    _145_t3 = 0;
    goto BB2;
BB2:
    if (_145_t3) {
        goto BB3;
    } else {
        goto BB9;
    }
BB3:
    _145_t8 = 1;
    if (_145_t8) {
        goto BB4;
    } else {
        goto BB8;
    }
BB9:
    _145_t0 = 0;
    goto BB7;
BB4:
    _145_t7 = 1;
    goto BB5;
BB8:
    _145_t7 = 0;
    goto BB5;
BB7:
    _145_$retval = _145_t0;
    return _145_$retval;
BB5:
    _145_t0 = _145_t7;
    goto BB7;
}

int main(void) {
  printf("%ld",_140_main());
  return 0;
}
