/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward typedefs */
struct struct0;
struct struct1;

/* Typedefs */
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
int64_t _1267_main(void);

/* Function definitions */
int64_t _1267_main(void){
    int64_t _1267_t1;
    struct struct0 _1267_t2;
    struct struct1 _1268_x;
    struct struct0 _1276_y;
    uint64_t _1267_t19;
    uint64_t _1267_t20;
    uint8_t _1267_t21;
    uint64_t _1267_t22;
    uint64_t _1267_t23;
    uint8_t _1267_t24;
    int64_t _1267_$retval;
    int64_t _1267_t18;
    _1267_t1 = 173;
    _1267_t2 = (struct struct0) {.tag=0, ._0=_1267_t1};
    _1268_x = (struct struct1) {.tag=1, ._1=_1267_t2};
    _1276_y = _1268_x._1;
    _1267_t19 = 0;
    _1267_t20 = _1276_y.tag;
    _1267_t21 = _1267_t20==_1267_t19;
    if (_1267_t21) {
        goto BB1526;
    } else {
        goto BB1528;
    }
BB1526:
    _1267_t18 = _1276_y._0;
    goto BB1527;
BB1528:
    _1267_t22 = 1;
    _1267_t23 = _1276_y.tag;
    _1267_t24 = _1267_t23==_1267_t22;
    if (_1267_t24) {
        goto BB1530;
    } else {
        goto BB1532;
    }
BB1527:
    _1267_$retval = _1267_t18;
    return _1267_$retval;
BB1530:
    _1267_t18 = _1276_y._1;
    goto BB1527;
BB1532:
    $lines[$line_idx++] = "tests/integration/pattern/match-sum-sum.orng:15:36:\n            _        => unreachable\n                                  ^";
    $panic("reached unreachable code\n");
}

int main(void) {
  printf("%ld",_1267_main());
  return 0;
}
