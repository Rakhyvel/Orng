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
int64_t _1277_main(void);

/* Function definitions */
int64_t _1277_main(void){
    int64_t _1277_t1;
    struct struct0 _1277_t2;
    struct struct1 _1278_x;
    struct struct0 _1286_y;
    uint64_t _1277_t19;
    uint64_t _1277_t20;
    uint8_t _1277_t21;
    uint64_t _1277_t22;
    uint64_t _1277_t23;
    uint8_t _1277_t24;
    int64_t _1277_$retval;
    int64_t _1277_t18;
    _1277_t1 = 173;
    _1277_t2 = (struct struct0) {.tag=0, ._0=_1277_t1};
    _1278_x = (struct struct1) {.tag=1, ._1=_1277_t2};
    _1286_y = _1278_x._1;
    _1277_t19 = 0;
    _1277_t20 = _1286_y.tag;
    _1277_t21 = _1277_t20==_1277_t19;
    if (_1277_t21) {
        goto BB1538;
    } else {
        goto BB1540;
    }
BB1538:
    _1277_t18 = _1286_y._0;
    goto BB1539;
BB1540:
    _1277_t22 = 1;
    _1277_t23 = _1286_y.tag;
    _1277_t24 = _1277_t23==_1277_t22;
    if (_1277_t24) {
        goto BB1542;
    } else {
        goto BB1544;
    }
BB1539:
    _1277_$retval = _1277_t18;
    return _1277_$retval;
BB1542:
    _1277_t18 = _1286_y._1;
    goto BB1539;
BB1544:
    $lines[$line_idx++] = "tests/integration/pattern/match-sum-sum.orng:15:36:\n            _        => unreachable\n                                  ^";
    $panic("reached unreachable code\n");
}

int main(void) {
  printf("%ld",_1277_main());
  return 0;
}
