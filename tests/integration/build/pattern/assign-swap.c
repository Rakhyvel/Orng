/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef struct {
    int64_t _0;
    int64_t _1;
} struct0;

/* Function forward definitions */
int64_t _25_main(void);

/* Function definitions */
int64_t _25_main(void) {
    int64_t _25_t1;
    int64_t _25_t2;
    struct0 _25_t0;
    int64_t _26_x;
    int64_t _26_y;
    struct0 _25_t3;
    int64_t _25_t6;
    uint8_t _25_t8;
    uint8_t _25_t7;
    int64_t _25_t9;
    uint8_t _25_t11;
    uint8_t _25_t10;
    uint8_t _25_t5;
    int64_t _25_$retval;
    _25_t1 = 1;
    _25_t2 = 2;
    _25_t0 = (struct0) {_25_t1, _25_t2};
    _26_x = _25_t0._0;
    _26_y = _25_t0._1;
    _25_t3 = (struct0) {_26_x, _26_y};
    _26_y = _25_t3._0;
    _26_x = _25_t3._1;
    _25_t6 = 1;
    _25_t8 = _26_y == _25_t6;
    if (_25_t8) {
        goto BB1;
    } else {
        goto BB14;
    }
BB1:
    _25_t7 = 1;
    goto BB2;
BB14:
    _25_t7 = 0;
    goto BB2;
BB2:
    if (_25_t7) {
        goto BB3;
    } else {
        goto BB13;
    }
BB3:
    _25_t9 = 2;
    _25_t11 = _26_x == _25_t9;
    if (_25_t11) {
        goto BB4;
    } else {
        goto BB12;
    }
BB13:
    _25_t5 = 0;
    goto BB6;
BB4:
    _25_t10 = 1;
    goto BB5;
BB12:
    _25_t10 = 0;
    goto BB5;
BB6:
    if (_25_t5) {
        goto BB7;
    } else {
        goto BB11;
    }
BB5:
    _25_t5 = _25_t10;
    goto BB6;
BB7:
    _25_$retval = 159;
    return _25_$retval;
BB11:
    $lines[$line_idx++] = "tests/integration/pattern/assign-swap.orng:8:20:\n        unreachable\n                  ^";
    $panic("reached unreachable code\n");
}

int main(void) {
  printf("%ld",_25_main());
  return 0;
}
