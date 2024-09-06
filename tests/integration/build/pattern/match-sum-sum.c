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
int64_t _1353_main(void);


/* Function definitions */
int64_t _1353_main(void){
    int64_t _1353_t2;
    struct struct0 _1353_t3;
    struct struct1 _1354_x;
    struct struct0 _1362_y;
    uint64_t _1353_t21;
    uint64_t _1353_t22;
    uint8_t _1353_t23;
    uint64_t _1353_t24;
    uint64_t _1353_t25;
    uint8_t _1353_t26;
    int64_t _1353_$retval;
    int64_t _1353_t20;
    _1353_t2 = 173;
    _1353_t3 = (struct struct0) {.tag=0, ._0=_1353_t2};
    _1354_x = (struct struct1) {.tag=1, ._1=_1353_t3};
    _1362_y = _1354_x._1;
    _1353_t21 = 0;
    _1353_t22 = _1362_y.tag;
    _1353_t23 = _1353_t22==_1353_t21;
    if (_1353_t23) {
        goto BB1586;
    } else {
        goto BB1588;
    }
BB1586:
    _1353_t20 = _1362_y._0;
    goto BB1587;
BB1588:
    _1353_t24 = 1;
    _1353_t25 = _1362_y.tag;
    _1353_t26 = _1353_t25==_1353_t24;
    if (_1353_t26) {
        goto BB1590;
    } else {
        goto BB1592;
    }
BB1587:
    _1353_$retval = _1353_t20;
    return _1353_$retval;
BB1590:
    _1353_t20 = _1362_y._1;
    goto BB1587;
BB1592:
    $lines[$line_idx++] = "tests/integration/pattern/match-sum-sum.orng:15:36:\n            _        => unreachable\n                                  ^";
    $panic("reached unreachable code\n");
}


int main(void) {
  printf("%ld",_1353_main());
  return 0;
}
