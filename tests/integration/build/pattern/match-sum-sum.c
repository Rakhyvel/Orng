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
int64_t _1392_main(void);


/* Function definitions */
int64_t _1392_main(void){
    int64_t _1392_t2;
    struct struct0 _1392_t3;
    struct struct1 _1393_x;
    struct struct0 _1401_y;
    uint64_t _1392_t21;
    uint64_t _1392_t22;
    uint8_t _1392_t23;
    uint64_t _1392_t24;
    uint64_t _1392_t25;
    uint8_t _1392_t26;
    int64_t _1392_$retval;
    int64_t _1392_t20;
    _1392_t2 = 173;
    _1392_t3 = (struct struct0) {.tag=0, ._0=_1392_t2};
    _1393_x = (struct struct1) {.tag=1, ._1=_1392_t3};
    _1401_y = _1393_x._1;
    _1392_t21 = 0;
    _1392_t22 = _1401_y.tag;
    _1392_t23 = _1392_t22==_1392_t21;
    if (_1392_t23) {
        goto BB1628;
    } else {
        goto BB1630;
    }
BB1628:
    _1392_t20 = _1401_y._0;
    goto BB1629;
BB1630:
    _1392_t24 = 1;
    _1392_t25 = _1401_y.tag;
    _1392_t26 = _1392_t25==_1392_t24;
    if (_1392_t26) {
        goto BB1632;
    } else {
        goto BB1634;
    }
BB1629:
    _1392_$retval = _1392_t20;
    return _1392_$retval;
BB1632:
    _1392_t20 = _1401_y._1;
    goto BB1629;
BB1634:
    $lines[$line_idx++] = "tests/integration/pattern/match-sum-sum.orng:15:36:\n            _        => unreachable\n                                  ^";
    $panic("reached unreachable code\n");
}


int main(void) {
  printf("%ld",_1392_main());
  return 0;
}
