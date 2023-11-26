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
int64_t _137_main(void);

/* Function definitions */
int64_t _137_main(void) {
    int64_t _137_t0;
    struct0 _137_t1;
    struct1 _138_x;
    uint8_t _137_t6;
    struct0 _140_y;
    uint64_t _137_t11;
    uint64_t _137_t12;
    uint8_t _137_t13;
    int64_t _137_t17;
    struct0 _144_y;
    uint64_t _137_t18;
    uint64_t _137_t19;
    uint8_t _137_t20;
    int64_t _137_t10;
    int64_t _137_t3;
    int64_t _137_$retval;
    uint64_t _137_t14;
    uint64_t _137_t15;
    uint8_t _137_t16;
    uint64_t _137_t21;
    uint64_t _137_t22;
    uint8_t _137_t23;
    uint64_t _137_t7;
    uint64_t _137_t8;
    uint8_t _137_t9;
    _137_t0 = 173;
    _137_t1 = (struct0) {.tag=0, ._0=_137_t0};
    _138_x = (struct1) {.tag=1, ._1=_137_t1};
    _137_t6 = 0;
    if (_137_t6) {
        goto BB3;
    } else {
        goto BB15;
    }
BB3:
    _140_y = _138_x._0;
    _137_t11 = 0;
    _137_t12 = _140_y.tag;
    _137_t13 = _137_t12 == _137_t11;
    if (_137_t13) {
        goto BB6;
    } else {
        goto BB10;
    }
BB15:
    _137_t7 = 1;
    _137_t8 = _138_x.tag;
    _137_t9 = _137_t8 == _137_t7;
    if (_137_t9) {
        goto BB17;
    } else {
        goto BB28;
    }
BB6:
    _137_t10 = _140_y._0;
    goto BB7;
BB10:
    _137_t14 = 1;
    _137_t15 = _140_y.tag;
    _137_t16 = _137_t15 == _137_t14;
    if (_137_t16) {
        goto BB12;
    } else {
        goto BB14;
    }
BB17:
    _144_y = _138_x._1;
    _137_t18 = 0;
    _137_t19 = _144_y.tag;
    _137_t20 = _137_t19 == _137_t18;
    if (_137_t20) {
        goto BB20;
    } else {
        goto BB22;
    }
BB28:
    $lines[$line_idx++] = "tests/integration/pattern/match-sum-sum.orng:17:28:\n        else => unreachable\n                          ^";
    $panic("reached unreachable code\n");
BB7:
    _137_t3 = _137_t10;
    goto BB9;
BB12:
    _137_t10 = _140_y._1;
    goto BB7;
BB14:
    $lines[$line_idx++] = "tests/integration/pattern/match-sum-sum.orng:10:32:\n            else => unreachable\n                              ^";
    $panic("reached unreachable code\n");
BB20:
    _137_t17 = _144_y._0;
    goto BB21;
BB22:
    _137_t21 = 1;
    _137_t22 = _144_y.tag;
    _137_t23 = _137_t22 == _137_t21;
    if (_137_t23) {
        goto BB24;
    } else {
        goto BB26;
    }
BB9:
    _137_$retval = _137_t3;
    return _137_$retval;
BB21:
    _137_t3 = _137_t17;
    goto BB9;
BB24:
    _137_t17 = _144_y._1;
    goto BB21;
BB26:
    $lines[$line_idx++] = "tests/integration/pattern/match-sum-sum.orng:15:32:\n            else => unreachable\n                              ^";
    $panic("reached unreachable code\n");
}

int main(void) {
  printf("%ld",_137_main());
  return 0;
}
