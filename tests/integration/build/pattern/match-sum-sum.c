/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward struct, union, and function declarations */
struct struct0;
struct struct1;

/* Struct, union, and function definitions */
struct struct0 {
    uint64_t tag;
    union {
        int64_t _0;
        int64_t _1;
    };
};

struct struct1 {
    uint64_t tag;
    union {
        struct struct0 _0;
        struct struct0 _1;
    };
};

/* Function forward definitions */
int64_t _1312_main(void);


/* Function definitions */
int64_t _1312_main(void){
    int64_t _1312_t2;
    struct struct0 _1312_t3;
    struct struct1 _1313_x;
    struct struct0 _1321_y;
    uint64_t _1312_t21;
    uint64_t _1312_t22;
    uint8_t _1312_t23;
    uint64_t _1312_t24;
    uint64_t _1312_t25;
    uint8_t _1312_t26;
    int64_t _1312_$retval;
    int64_t _1312_t20;
    _1312_t2 = 173;
    _1312_t3 = (struct struct0) {.tag=0, ._0=_1312_t2};
    _1313_x = (struct struct1) {.tag=1, ._1=_1312_t3};
    _1321_y = _1313_x._1;
    _1312_t21 = 0;
    _1312_t22 = _1321_y.tag;
    _1312_t23 = _1312_t22==_1312_t21;
    if (_1312_t23) {
        goto BB1558;
    } else {
        goto BB1560;
    }
BB1558:
    _1312_t20 = _1321_y._0;
    goto BB1559;
BB1560:
    _1312_t24 = 1;
    _1312_t25 = _1321_y.tag;
    _1312_t26 = _1312_t25==_1312_t24;
    if (_1312_t26) {
        goto BB1562;
    } else {
        goto BB1564;
    }
BB1559:
    _1312_$retval = _1312_t20;
    return _1312_$retval;
BB1562:
    _1312_t20 = _1321_y._1;
    goto BB1559;
BB1564:
    $lines[$line_idx++] = "tests/integration/pattern/match-sum-sum.orng:15:36:\n            _        => unreachable\n                                  ^";
    $panic("reached unreachable code\n");
}


int main(void) {
  printf("%ld",_1312_main());
  return 0;
}
