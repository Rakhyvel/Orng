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
int64_t _1278_main(void);


/* Function definitions */
int64_t _1278_main(void){
    int64_t _1278_t2;
    struct struct0 _1278_t3;
    struct struct1 _1279_x;
    struct struct0 _1287_y;
    uint64_t _1278_t21;
    uint64_t _1278_t22;
    uint8_t _1278_t23;
    uint64_t _1278_t24;
    uint64_t _1278_t25;
    uint8_t _1278_t26;
    int64_t _1278_$retval;
    int64_t _1278_t20;
    _1278_t2 = 173;
    _1278_t3 = (struct struct0) {.tag=0, ._0=_1278_t2};
    _1279_x = (struct struct1) {.tag=1, ._1=_1278_t3};
    _1287_y = _1279_x._1;
    _1278_t21 = 0;
    _1278_t22 = _1287_y.tag;
    _1278_t23 = _1278_t22==_1278_t21;
    if (_1278_t23) {
        goto BB1505;
    } else {
        goto BB1507;
    }
BB1505:
    _1278_t20 = _1287_y._0;
    goto BB1506;
BB1507:
    _1278_t24 = 1;
    _1278_t25 = _1287_y.tag;
    _1278_t26 = _1278_t25==_1278_t24;
    if (_1278_t26) {
        goto BB1509;
    } else {
        goto BB1511;
    }
BB1506:
    _1278_$retval = _1278_t20;
    return _1278_$retval;
BB1509:
    _1278_t20 = _1287_y._1;
    goto BB1506;
BB1511:
    $lines[$line_idx++] = "tests/integration/pattern/match-sum-sum.orng:15:36:\n            _        => unreachable\n                                  ^";
    $panic("reached unreachable code\n");
}


int main(void) {
  printf("%ld",_1278_main());
  return 0;
}
