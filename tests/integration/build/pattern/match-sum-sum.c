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
int64_t _1350_main(void);


/* Function definitions */
int64_t _1350_main(void){
    int64_t _1350_t2;
    struct struct0 _1350_t3;
    struct struct1 _1351_x;
    struct struct0 _1359_y;
    uint64_t _1350_t21;
    uint64_t _1350_t22;
    uint8_t _1350_t23;
    uint64_t _1350_t24;
    uint64_t _1350_t25;
    uint8_t _1350_t26;
    int64_t _1350_$retval;
    int64_t _1350_t20;
    _1350_t2 = 173;
    _1350_t3 = (struct struct0) {.tag=0, ._0=_1350_t2};
    _1351_x = (struct struct1) {.tag=1, ._1=_1350_t3};
    _1359_y = _1351_x._1;
    _1350_t21 = 0;
    _1350_t22 = _1359_y.tag;
    _1350_t23 = _1350_t22==_1350_t21;
    if (_1350_t23) {
        goto BB1584;
    } else {
        goto BB1586;
    }
BB1584:
    _1350_t20 = _1359_y._0;
    goto BB1585;
BB1586:
    _1350_t24 = 1;
    _1350_t25 = _1359_y.tag;
    _1350_t26 = _1350_t25==_1350_t24;
    if (_1350_t26) {
        goto BB1588;
    } else {
        goto BB1590;
    }
BB1585:
    _1350_$retval = _1350_t20;
    return _1350_$retval;
BB1588:
    _1350_t20 = _1359_y._1;
    goto BB1585;
BB1590:
    $lines[$line_idx++] = "tests/integration/pattern/match-sum-sum.orng:15:36:\n            _        => unreachable\n                                  ^";
    $panic("reached unreachable code\n");
}


int main(void) {
  printf("%ld",_1350_main());
  return 0;
}
