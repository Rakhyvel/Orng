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
int64_t _1331_main(void);


/* Function definitions */
int64_t _1331_main(void){
    int64_t _1331_t2;
    struct struct0 _1331_t3;
    struct struct1 _1332_x;
    struct struct0 _1340_y;
    uint64_t _1331_t21;
    uint64_t _1331_t22;
    uint8_t _1331_t23;
    uint64_t _1331_t24;
    uint64_t _1331_t25;
    uint8_t _1331_t26;
    int64_t _1331_$retval;
    int64_t _1331_t20;
    _1331_t2 = 173;
    _1331_t3 = (struct struct0) {.tag=0, ._0=_1331_t2};
    _1332_x = (struct struct1) {.tag=1, ._1=_1331_t3};
    _1340_y = _1332_x._1;
    _1331_t21 = 0;
    _1331_t22 = _1340_y.tag;
    _1331_t23 = _1331_t22==_1331_t21;
    if (_1331_t23) {
        goto BB1563;
    } else {
        goto BB1565;
    }
BB1563:
    _1331_t20 = _1340_y._0;
    goto BB1564;
BB1565:
    _1331_t24 = 1;
    _1331_t25 = _1340_y.tag;
    _1331_t26 = _1331_t25==_1331_t24;
    if (_1331_t26) {
        goto BB1567;
    } else {
        goto BB1569;
    }
BB1564:
    _1331_$retval = _1331_t20;
    return _1331_$retval;
BB1567:
    _1331_t20 = _1340_y._1;
    goto BB1564;
BB1569:
    $lines[$line_idx++] = "tests/integration/pattern/match-sum-sum.orng:15:36:\n            _        => unreachable\n                                  ^";
    $panic("reached unreachable code\n");
}


int main(void) {
  printf("%ld",_1331_main());
  return 0;
}
