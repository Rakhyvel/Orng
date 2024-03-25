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
int64_t _1287_main(void);


/* Function definitions */
int64_t _1287_main(void){
    int64_t _1287_t2;
    struct struct0 _1287_t3;
    struct struct1 _1288_x;
    struct struct0 _1296_y;
    uint64_t _1287_t21;
    uint64_t _1287_t22;
    uint8_t _1287_t23;
    uint64_t _1287_t24;
    uint64_t _1287_t25;
    uint8_t _1287_t26;
    int64_t _1287_$retval;
    int64_t _1287_t20;
    _1287_t2 = 173;
    _1287_t3 = (struct struct0) {.tag=0, ._0=_1287_t2};
    _1288_x = (struct struct1) {.tag=1, ._1=_1287_t3};
    _1296_y = _1288_x._1;
    _1287_t21 = 0;
    _1287_t22 = _1296_y.tag;
    _1287_t23 = _1287_t22==_1287_t21;
    if (_1287_t23) {
        goto BB1511;
    } else {
        goto BB1513;
    }
BB1511:
    _1287_t20 = _1296_y._0;
    goto BB1512;
BB1513:
    _1287_t24 = 1;
    _1287_t25 = _1296_y.tag;
    _1287_t26 = _1287_t25==_1287_t24;
    if (_1287_t26) {
        goto BB1515;
    } else {
        goto BB1517;
    }
BB1512:
    _1287_$retval = _1287_t20;
    return _1287_$retval;
BB1515:
    _1287_t20 = _1296_y._1;
    goto BB1512;
BB1517:
    $lines[$line_idx++] = "tests/integration/pattern/match-sum-sum.orng:15:36:\n            _        => unreachable\n                                  ^";
    $panic("reached unreachable code\n");
}


int main(void) {
  printf("%ld",_1287_main());
  return 0;
}
