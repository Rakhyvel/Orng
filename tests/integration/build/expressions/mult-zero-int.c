/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef uint8_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _162_main(void);
uint8_t _167_f(int64_t _167_x);

/* Function definitions */
int64_t _162_main(void) {
    function0 _162_t1;
    int64_t _162_t3;
    uint8_t _162_t2;
    int64_t _162_t0;
    int64_t _162_$retval;
    _162_t1 = _167_f;
    _162_t3 = 4;
    $lines[$line_idx++] = "tests/integration/expressions/mult-zero-int.orng:3:10:\n    if f(4) {\n        ^";
    _162_t2 = _162_t1(_162_t3);
    $line_idx--;
    if (_162_t2) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _162_t0 = 187;
    goto BB4;
BB5:
    _162_t0 = 4;
    goto BB4;
BB4:
    _162_$retval = _162_t0;
    return _162_$retval;
}

uint8_t _167_f(int64_t _167_x) {
    uint8_t _167_t5;
    uint8_t _167_t4;
    uint8_t _167_t10;
    uint8_t _167_t9;
    uint8_t _167_t0;
    uint8_t _167_$retval;
    (void)_167_x;
    _167_t5 = 1;
    if (_167_t5) {
        goto BB1;
    } else {
        goto BB10;
    }
BB1:
    _167_t4 = 1;
    goto BB2;
BB10:
    _167_t4 = 0;
    goto BB2;
BB2:
    if (_167_t4) {
        goto BB3;
    } else {
        goto BB9;
    }
BB3:
    _167_t10 = 1;
    if (_167_t10) {
        goto BB4;
    } else {
        goto BB8;
    }
BB9:
    _167_t0 = 0;
    goto BB7;
BB4:
    _167_t9 = 1;
    goto BB5;
BB8:
    _167_t9 = 0;
    goto BB5;
BB7:
    _167_$retval = _167_t0;
    return _167_$retval;
BB5:
    _167_t0 = _167_t9;
    goto BB7;
}

int main(void) {
  printf("%ld",_162_main());
  return 0;
}
