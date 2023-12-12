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
int64_t _857_main(void);

/* Function definitions */
int64_t _857_main(void) {
    int64_t _857_t1;
    int64_t _857_t2;
    struct0 _857_t0;
    int64_t _858_x;
    int64_t _858_y;
    struct0 _857_t3;
    int64_t _857_t6;
    uint8_t _857_t8;
    uint8_t _857_t10;
    uint8_t _857_t5;
    int64_t _857_t9;
    uint8_t _857_t11;
    int64_t _857_$retval;
    _857_t1 = 1;
    _857_t2 = 2;
    _857_t0 = (struct0) {_857_t1, _857_t2};
    _858_x = _857_t0._0;
    _858_y = _857_t0._1;
    _857_t3 = (struct0) {_858_x, _858_y};
    _858_y = _857_t3._0;
    _858_x = _857_t3._1;
    _857_t6 = 1;
    _857_t8 = _858_y == _857_t6;
    if (_857_t8) {
        goto BB3;
    } else {
        goto BB13;
    }
BB3:
    _857_t9 = 2;
    _857_t11 = _858_x == _857_t9;
    if (_857_t11) {
        goto BB4;
    } else {
        goto BB12;
    }
BB13:
    _857_t5 = 0;
    goto BB11;
BB4:
    _857_t10 = 1;
    goto BB5;
BB12:
    _857_t10 = 0;
    goto BB5;
BB11:
    $lines[$line_idx++] = "tests/integration/pattern/assign-swap.orng:8:20:\n        unreachable\n                  ^";
    $panic("reached unreachable code\n");
BB5:
    _857_t5 = _857_t10;
    goto BB6;
BB6:
    if (_857_t5) {
        goto BB7;
    } else {
        goto BB11;
    }
BB7:
    _857_$retval = 159;
    return _857_$retval;
}

int main(void) {
  printf("%ld",_857_main());
  return 0;
}
