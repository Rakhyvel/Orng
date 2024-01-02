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
int64_t _1262_main(void);

/* Function definitions */
int64_t _1262_main(void){
    int64_t _1262_t1;
    struct struct0 _1262_t2;
    struct struct1 _1263_x;
    struct struct0 _1271_y;
    uint64_t _1262_t19;
    uint64_t _1262_t20;
    uint8_t _1262_t21;
    uint64_t _1262_t22;
    uint64_t _1262_t23;
    uint8_t _1262_t24;
    int64_t _1262_$retval;
    int64_t _1262_t18;
    _1262_t1 = 173;
    _1262_t2 = (struct struct0) {.tag=0, ._0=_1262_t1};
    _1263_x = (struct struct1) {.tag=1, ._1=_1262_t2};
    _1271_y = _1263_x._1;
    _1262_t19 = 0;
    _1262_t20 = _1271_y.tag;
    _1262_t21 = _1262_t20==_1262_t19;
    if (_1262_t21) {
        goto BB1522;
    } else {
        goto BB1524;
    }
BB1522:
    _1262_t18 = _1271_y._0;
    goto BB1523;
BB1524:
    _1262_t22 = 1;
    _1262_t23 = _1271_y.tag;
    _1262_t24 = _1262_t23==_1262_t22;
    if (_1262_t24) {
        goto BB1526;
    } else {
        goto BB1528;
    }
BB1523:
    _1262_$retval = _1262_t18;
    return _1262_$retval;
BB1526:
    _1262_t18 = _1271_y._1;
    goto BB1523;
BB1528:
    $lines[$line_idx++] = "tests/integration/pattern/match-sum-sum.orng:15:36:\n            _        => unreachable\n                                  ^";
    $panic("reached unreachable code\n");
}

int main(void) {
  printf("%ld",_1262_main());
  return 0;
}
