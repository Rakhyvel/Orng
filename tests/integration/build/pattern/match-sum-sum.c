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
int64_t _1372_main(void);


/* Function definitions */
int64_t _1372_main(void){
    int64_t _1372_t2;
    struct struct0 _1372_t3;
    struct struct1 _1373_x;
    struct struct0 _1381_y;
    uint64_t _1372_t21;
    uint64_t _1372_t22;
    uint8_t _1372_t23;
    uint64_t _1372_t24;
    uint64_t _1372_t25;
    uint8_t _1372_t26;
    int64_t _1372_$retval;
    int64_t _1372_t20;
    _1372_t2 = 173;
    _1372_t3 = (struct struct0) {.tag=0, ._0=_1372_t2};
    _1373_x = (struct struct1) {.tag=1, ._1=_1372_t3};
    _1381_y = _1373_x._1;
    _1372_t21 = 0;
    _1372_t22 = _1381_y.tag;
    _1372_t23 = _1372_t22==_1372_t21;
    if (_1372_t23) {
        goto BB1609;
    } else {
        goto BB1611;
    }
BB1609:
    _1372_t20 = _1381_y._0;
    goto BB1610;
BB1611:
    _1372_t24 = 1;
    _1372_t25 = _1381_y.tag;
    _1372_t26 = _1372_t25==_1372_t24;
    if (_1372_t26) {
        goto BB1613;
    } else {
        goto BB1615;
    }
BB1610:
    _1372_$retval = _1372_t20;
    return _1372_$retval;
BB1613:
    _1372_t20 = _1381_y._1;
    goto BB1610;
BB1615:
    $lines[$line_idx++] = "tests/integration/pattern/match-sum-sum.orng:15:36:\n            _        => unreachable\n                                  ^";
    $panic("reached unreachable code\n");
}


int main(void) {
  printf("%ld",_1372_main());
  return 0;
}
