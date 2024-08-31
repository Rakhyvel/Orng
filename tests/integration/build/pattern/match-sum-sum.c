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
int64_t _1292_main(void);


/* Function definitions */
int64_t _1292_main(void){
    int64_t _1292_t2;
    struct struct0 _1292_t3;
    struct struct1 _1293_x;
    struct struct0 _1301_y;
    uint64_t _1292_t21;
    uint64_t _1292_t22;
    uint8_t _1292_t23;
    uint64_t _1292_t24;
    uint64_t _1292_t25;
    uint8_t _1292_t26;
    int64_t _1292_$retval;
    int64_t _1292_t20;
    _1292_t2 = 173;
    _1292_t3 = (struct struct0) {.tag=0, ._0=_1292_t2};
    _1293_x = (struct struct1) {.tag=1, ._1=_1292_t3};
    _1301_y = _1293_x._1;
    _1292_t21 = 0;
    _1292_t22 = _1301_y.tag;
    _1292_t23 = _1292_t22==_1292_t21;
    if (_1292_t23) {
        goto BB1515;
    } else {
        goto BB1517;
    }
BB1515:
    _1292_t20 = _1301_y._0;
    goto BB1516;
BB1517:
    _1292_t24 = 1;
    _1292_t25 = _1301_y.tag;
    _1292_t26 = _1292_t25==_1292_t24;
    if (_1292_t26) {
        goto BB1519;
    } else {
        goto BB1521;
    }
BB1516:
    _1292_$retval = _1292_t20;
    return _1292_$retval;
BB1519:
    _1292_t20 = _1301_y._1;
    goto BB1516;
BB1521:
    $lines[$line_idx++] = "tests/integration/pattern/match-sum-sum.orng:15:36:\n            _        => unreachable\n                                  ^";
    $panic("reached unreachable code\n");
}


int main(void) {
  printf("%ld",_1292_main());
  return 0;
}
