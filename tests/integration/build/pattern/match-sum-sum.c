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
int64_t _1309_main(void);


/* Function definitions */
int64_t _1309_main(void){
    int64_t _1309_t1;
    struct struct0 _1309_t2;
    struct struct1 _1310_x;
    struct struct0 _1318_y;
    uint64_t _1309_t19;
    uint64_t _1309_t20;
    uint8_t _1309_t21;
    uint64_t _1309_t22;
    uint64_t _1309_t23;
    uint8_t _1309_t24;
    int64_t _1309_$retval;
    int64_t _1309_t18;
    _1309_t1 = 173;
    _1309_t2 = (struct struct0) {.tag=0, ._0=_1309_t1};
    _1310_x = (struct struct1) {.tag=1, ._1=_1309_t2};
    _1318_y = _1310_x._1;
    _1309_t19 = 0;
    _1309_t20 = _1318_y.tag;
    _1309_t21 = _1309_t20==_1309_t19;
    if (_1309_t21) {
        goto BB1564;
    } else {
        goto BB1566;
    }
BB1564:
    _1309_t18 = _1318_y._0;
    goto BB1565;
BB1566:
    _1309_t22 = 1;
    _1309_t23 = _1318_y.tag;
    _1309_t24 = _1309_t23==_1309_t22;
    if (_1309_t24) {
        goto BB1568;
    } else {
        goto BB1570;
    }
BB1565:
    _1309_$retval = _1309_t18;
    return _1309_$retval;
BB1568:
    _1309_t18 = _1318_y._1;
    goto BB1565;
BB1570:
    $lines[$line_idx++] = "tests/integration/pattern/match-sum-sum.orng:15:36:\n            _        => unreachable\n                                  ^";
    $panic("reached unreachable code\n");
}


int main(void) {
  printf("%ld",_1309_main());
  return 0;
}
