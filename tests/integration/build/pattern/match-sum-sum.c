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
int64_t _1342_main(void);


/* Function definitions */
int64_t _1342_main(void){
    int64_t _1342_t2;
    struct struct0 _1342_t3;
    struct struct1 _1343_x;
    struct struct0 _1351_y;
    uint64_t _1342_t21;
    uint64_t _1342_t22;
    uint8_t _1342_t23;
    uint64_t _1342_t24;
    uint64_t _1342_t25;
    uint8_t _1342_t26;
    int64_t _1342_$retval;
    int64_t _1342_t20;
    _1342_t2 = 173;
    _1342_t3 = (struct struct0) {.tag=0, ._0=_1342_t2};
    _1343_x = (struct struct1) {.tag=1, ._1=_1342_t3};
    _1351_y = _1343_x._1;
    _1342_t21 = 0;
    _1342_t22 = _1351_y.tag;
    _1342_t23 = _1342_t22==_1342_t21;
    if (_1342_t23) {
        goto BB1573;
    } else {
        goto BB1575;
    }
BB1573:
    _1342_t20 = _1351_y._0;
    goto BB1574;
BB1575:
    _1342_t24 = 1;
    _1342_t25 = _1351_y.tag;
    _1342_t26 = _1342_t25==_1342_t24;
    if (_1342_t26) {
        goto BB1577;
    } else {
        goto BB1579;
    }
BB1574:
    _1342_$retval = _1342_t20;
    return _1342_$retval;
BB1577:
    _1342_t20 = _1351_y._1;
    goto BB1574;
BB1579:
    $lines[$line_idx++] = "tests/integration/pattern/match-sum-sum.orng:15:36:\n            _        => unreachable\n                                  ^";
    $panic("reached unreachable code\n");
}


int main(void) {
  printf("%ld",_1342_main());
  return 0;
}
