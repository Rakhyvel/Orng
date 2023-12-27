/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef struct {
    uint64_t tag;
    union {
        int64_t _0;
        int64_t _1;
    };
} struct0;

typedef struct {
    uint64_t tag;
    union {
        struct0 _0;
        struct0 _1;
    };
} struct1;

/* Function forward definitions */
int64_t _1240_main(void);

/* Function definitions */
int64_t _1240_main(void){
    int64_t _1240_t1;
    struct0 _1240_t2;
    struct1 _1241_x;
    struct0 _1248_y;
    uint64_t _1240_t19;
    uint64_t _1240_t20;
    uint8_t _1240_t21;
    uint64_t _1240_t22;
    uint64_t _1240_t23;
    uint8_t _1240_t24;
    int64_t _1240_$retval;
    int64_t _1240_t18;
    _1240_t1 = 173;
    _1240_t2 = (struct0) {.tag=0, ._0=_1240_t1};
    _1241_x = (struct1) {.tag=1, ._1=_1240_t2};
    _1248_y = _1241_x._1;
    _1240_t19 = 0;
    _1240_t20 = _1248_y.tag;
    _1240_t21 = _1240_t20==_1240_t19;
    if (_1240_t21) {
        goto BB1533;
    } else {
        goto BB1535;
    }
BB1533:
    _1240_t18 = _1248_y._0;
    goto BB1534;
BB1535:
    _1240_t22 = 1;
    _1240_t23 = _1248_y.tag;
    _1240_t24 = _1240_t23==_1240_t22;
    if (_1240_t24) {
        goto BB1537;
    } else {
        goto BB1539;
    }
BB1534:
    _1240_$retval = _1240_t18;
    return _1240_$retval;
BB1537:
    _1240_t18 = _1248_y._1;
    goto BB1534;
BB1539:
    $lines[$line_idx++] = "tests/integration/pattern/match-sum-sum.orng:15:32:\n            else => unreachable\n                              ^";
    $panic("reached unreachable code\n");
}

int main(void) {
  printf("%ld",_1240_main());
  return 0;
}
