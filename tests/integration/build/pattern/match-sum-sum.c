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
int64_t _1282_main(void);

/* Function definitions */
int64_t _1282_main(void){
    int64_t _1282_t1;
    struct struct0 _1282_t2;
    struct struct1 _1283_x;
    struct struct0 _1291_y;
    uint64_t _1282_t19;
    uint64_t _1282_t20;
    uint8_t _1282_t21;
    uint64_t _1282_t22;
    uint64_t _1282_t23;
    uint8_t _1282_t24;
    int64_t _1282_$retval;
    int64_t _1282_t18;
    _1282_t1 = 173;
    _1282_t2 = (struct struct0) {.tag=0, ._0=_1282_t1};
    _1283_x = (struct struct1) {.tag=1, ._1=_1282_t2};
    _1291_y = _1283_x._1;
    _1282_t19 = 0;
    _1282_t20 = _1291_y.tag;
    _1282_t21 = _1282_t20==_1282_t19;
    if (_1282_t21) {
        goto BB1542;
    } else {
        goto BB1544;
    }
BB1542:
    _1282_t18 = _1291_y._0;
    goto BB1543;
BB1544:
    _1282_t22 = 1;
    _1282_t23 = _1291_y.tag;
    _1282_t24 = _1282_t23==_1282_t22;
    if (_1282_t24) {
        goto BB1546;
    } else {
        goto BB1548;
    }
BB1543:
    _1282_$retval = _1282_t18;
    return _1282_$retval;
BB1546:
    _1282_t18 = _1291_y._1;
    goto BB1543;
BB1548:
    $lines[$line_idx++] = "tests/integration/pattern/match-sum-sum.orng:15:36:\n            _        => unreachable\n                                  ^";
    $panic("reached unreachable code\n");
}

int main(void) {
  printf("%ld",_1282_main());
  return 0;
}
