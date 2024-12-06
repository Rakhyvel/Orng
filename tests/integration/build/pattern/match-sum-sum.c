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
int64_t _1364_main(void);


/* Function definitions */
int64_t _1364_main(void){
    int64_t _1364_t2;
    struct struct0 _1364_t3;
    struct struct1 _1365_x;
    struct struct0 _1373_y;
    uint64_t _1364_t21;
    uint64_t _1364_t22;
    uint8_t _1364_t23;
    uint64_t _1364_t24;
    uint64_t _1364_t25;
    uint8_t _1364_t26;
    int64_t _1364_$retval;
    int64_t _1364_t20;
    _1364_t2 = 173;
    _1364_t3 = (struct struct0) {.tag=0, ._0=_1364_t2};
    _1365_x = (struct struct1) {.tag=1, ._1=_1364_t3};
    _1373_y = _1365_x._1;
    _1364_t21 = 0;
    _1364_t22 = _1373_y.tag;
    _1364_t23 = _1364_t22==_1364_t21;
    if (_1364_t23) {
        goto BB1599;
    } else {
        goto BB1601;
    }
BB1599:
    _1364_t20 = _1373_y._0;
    goto BB1600;
BB1601:
    _1364_t24 = 1;
    _1364_t25 = _1373_y.tag;
    _1364_t26 = _1364_t25==_1364_t24;
    if (_1364_t26) {
        goto BB1603;
    } else {
        goto BB1605;
    }
BB1600:
    _1364_$retval = _1364_t20;
    return _1364_$retval;
BB1603:
    _1364_t20 = _1373_y._1;
    goto BB1600;
BB1605:
    $lines[$line_idx++] = "tests/integration/pattern/match-sum-sum.orng:15:36:\n            _        => unreachable\n                                  ^";
    $panic("reached unreachable code\n");
}


int main(void) {
  printf("%ld",_1364_main());
  return 0;
}
