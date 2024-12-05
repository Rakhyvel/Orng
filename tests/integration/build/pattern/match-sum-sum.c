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
int64_t _1358_main(void);


/* Function definitions */
int64_t _1358_main(void){
    int64_t _1358_t2;
    struct struct0 _1358_t3;
    struct struct1 _1359_x;
    struct struct0 _1367_y;
    uint64_t _1358_t21;
    uint64_t _1358_t22;
    uint8_t _1358_t23;
    uint64_t _1358_t24;
    uint64_t _1358_t25;
    uint8_t _1358_t26;
    int64_t _1358_$retval;
    int64_t _1358_t20;
    _1358_t2 = 173;
    _1358_t3 = (struct struct0) {.tag=0, ._0=_1358_t2};
    _1359_x = (struct struct1) {.tag=1, ._1=_1358_t3};
    _1367_y = _1359_x._1;
    _1358_t21 = 0;
    _1358_t22 = _1367_y.tag;
    _1358_t23 = _1358_t22==_1358_t21;
    if (_1358_t23) {
        goto BB1590;
    } else {
        goto BB1592;
    }
BB1590:
    _1358_t20 = _1367_y._0;
    goto BB1591;
BB1592:
    _1358_t24 = 1;
    _1358_t25 = _1367_y.tag;
    _1358_t26 = _1358_t25==_1358_t24;
    if (_1358_t26) {
        goto BB1594;
    } else {
        goto BB1596;
    }
BB1591:
    _1358_$retval = _1358_t20;
    return _1358_$retval;
BB1594:
    _1358_t20 = _1367_y._1;
    goto BB1591;
BB1596:
    $lines[$line_idx++] = "tests/integration/pattern/match-sum-sum.orng:15:36:\n            _        => unreachable\n                                  ^";
    $panic("reached unreachable code\n");
}


int main(void) {
  printf("%ld",_1358_main());
  return 0;
}
