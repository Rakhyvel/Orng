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
int64_t _1259_main(void);

/* Function definitions */
int64_t _1259_main(void){
    int64_t _1259_t1;
    struct0 _1259_t2;
    struct1 _1260_x;
    struct0 _1268_y;
    uint64_t _1259_t19;
    uint64_t _1259_t20;
    uint8_t _1259_t21;
    uint64_t _1259_t22;
    uint64_t _1259_t23;
    uint8_t _1259_t24;
    int64_t _1259_$retval;
    int64_t _1259_t18;
    _1259_t1 = 173;
    _1259_t2 = (struct0) {.tag=0, ._0=_1259_t1};
    _1260_x = (struct1) {.tag=1, ._1=_1259_t2};
    _1268_y = _1260_x._1;
    _1259_t19 = 0;
    _1259_t20 = _1268_y.tag;
    _1259_t21 = _1259_t20==_1259_t19;
    if (_1259_t21) {
        goto BB1530;
    } else {
        goto BB1532;
    }
BB1530:
    _1259_t18 = _1268_y._0;
    goto BB1531;
BB1532:
    _1259_t22 = 1;
    _1259_t23 = _1268_y.tag;
    _1259_t24 = _1259_t23==_1259_t22;
    if (_1259_t24) {
        goto BB1534;
    } else {
        goto BB1536;
    }
BB1531:
    _1259_$retval = _1259_t18;
    return _1259_$retval;
BB1534:
    _1259_t18 = _1268_y._1;
    goto BB1531;
BB1536:
    $lines[$line_idx++] = "tests/integration/pattern/match-sum-sum.orng:15:36:\n            _        => unreachable\n                                  ^";
    $panic("reached unreachable code\n");
}

int main(void) {
  printf("%ld",_1259_main());
  return 0;
}
