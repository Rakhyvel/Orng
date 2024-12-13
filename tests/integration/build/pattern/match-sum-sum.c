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
int64_t _1394_main(void);


/* Function definitions */
int64_t _1394_main(void){
    int64_t _1394_t2;
    struct struct0 _1394_t3;
    struct struct1 _1395_x;
    struct struct0 _1403_y;
    uint64_t _1394_t21;
    uint64_t _1394_t22;
    uint8_t _1394_t23;
    uint64_t _1394_t24;
    uint64_t _1394_t25;
    uint8_t _1394_t26;
    int64_t _1394_$retval;
    int64_t _1394_t20;
    _1394_t2 = 173;
    _1394_t3 = (struct struct0) {.tag=0, ._0=_1394_t2};
    _1395_x = (struct struct1) {.tag=1, ._1=_1394_t3};
    _1403_y = _1395_x._1;
    _1394_t21 = 0;
    _1394_t22 = _1403_y.tag;
    _1394_t23 = _1394_t22==_1394_t21;
    if (_1394_t23) {
        goto BB1630;
    } else {
        goto BB1632;
    }
BB1630:
    _1394_t20 = _1403_y._0;
    goto BB1631;
BB1632:
    _1394_t24 = 1;
    _1394_t25 = _1403_y.tag;
    _1394_t26 = _1394_t25==_1394_t24;
    if (_1394_t26) {
        goto BB1634;
    } else {
        goto BB1636;
    }
BB1631:
    _1394_$retval = _1394_t20;
    return _1394_$retval;
BB1634:
    _1394_t20 = _1403_y._1;
    goto BB1631;
BB1636:
    $lines[$line_idx++] = "tests/integration/pattern/match-sum-sum.orng:15:36:\n            _        => unreachable\n                                  ^";
    $panic("reached unreachable code\n");
}


int main(void) {
  printf("%ld",_1394_main());
  return 0;
}
