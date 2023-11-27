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
int64_t _771_main(void);

/* Function definitions */
int64_t _771_main(void) {
    int64_t _771_t1;
    int64_t _771_t2;
    struct0 _771_t0;
    int64_t _772_x;
    int64_t _772_y;
    struct0 _771_t3;
    int64_t _771_t6;
    uint8_t _771_t8;
    uint8_t _771_t10;
    uint8_t _771_t5;
    int64_t _771_t9;
    uint8_t _771_t11;
    int64_t _771_$retval;
    _771_t1 = 1;
    _771_t2 = 2;
    _771_t0 = (struct0) {_771_t1, _771_t2};
    _772_x = _771_t0._0;
    _772_y = _771_t0._1;
    _771_t3 = (struct0) {_772_x, _772_y};
    _772_y = _771_t3._0;
    _772_x = _771_t3._1;
    _771_t6 = 1;
    _771_t8 = _772_y == _771_t6;
    if (_771_t8) {
        goto BB3;
    } else {
        goto BB13;
    }
BB3:
    _771_t9 = 2;
    _771_t11 = _772_x == _771_t9;
    if (_771_t11) {
        goto BB4;
    } else {
        goto BB12;
    }
BB13:
    _771_t5 = 0;
    goto BB11;
BB4:
    _771_t10 = 1;
    goto BB5;
BB12:
    _771_t10 = 0;
    goto BB5;
BB11:
    $lines[$line_idx++] = "tests/integration/pattern/assign-swap.orng:8:20:\n        unreachable\n                  ^";
    $panic("reached unreachable code\n");
BB5:
    _771_t5 = _771_t10;
    goto BB6;
BB6:
    if (_771_t5) {
        goto BB7;
    } else {
        goto BB11;
    }
BB7:
    _771_$retval = 159;
    return _771_$retval;
}

int main(void) {
  printf("%ld",_771_main());
  return 0;
}
