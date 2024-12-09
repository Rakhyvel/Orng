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
int64_t _1377_main(void);


/* Function definitions */
int64_t _1377_main(void){
    int64_t _1377_t2;
    struct struct0 _1377_t3;
    struct struct1 _1378_x;
    struct struct0 _1386_y;
    uint64_t _1377_t21;
    uint64_t _1377_t22;
    uint8_t _1377_t23;
    uint64_t _1377_t24;
    uint64_t _1377_t25;
    uint8_t _1377_t26;
    int64_t _1377_$retval;
    int64_t _1377_t20;
    _1377_t2 = 173;
    _1377_t3 = (struct struct0) {.tag=0, ._0=_1377_t2};
    _1378_x = (struct struct1) {.tag=1, ._1=_1377_t3};
    _1386_y = _1378_x._1;
    _1377_t21 = 0;
    _1377_t22 = _1386_y.tag;
    _1377_t23 = _1377_t22==_1377_t21;
    if (_1377_t23) {
        goto BB1612;
    } else {
        goto BB1614;
    }
BB1612:
    _1377_t20 = _1386_y._0;
    goto BB1613;
BB1614:
    _1377_t24 = 1;
    _1377_t25 = _1386_y.tag;
    _1377_t26 = _1377_t25==_1377_t24;
    if (_1377_t26) {
        goto BB1616;
    } else {
        goto BB1618;
    }
BB1613:
    _1377_$retval = _1377_t20;
    return _1377_$retval;
BB1616:
    _1377_t20 = _1386_y._1;
    goto BB1613;
BB1618:
    $lines[$line_idx++] = "tests/integration/pattern/match-sum-sum.orng:15:36:\n            _        => unreachable\n                                  ^";
    $panic("reached unreachable code\n");
}


int main(void) {
  printf("%ld",_1377_main());
  return 0;
}
