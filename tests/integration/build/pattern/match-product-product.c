/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef struct {
    int64_t _0;
    int64_t _1;
} struct0;

typedef struct {
    struct0 _0;
    struct0 _1;
} struct1;

/* Function forward definitions */
int64_t _833_main(void);

/* Function definitions */
int64_t _833_main(void) {
    int64_t _833_t3;
    int64_t _833_t4;
    struct0 _833_t2;
    int64_t _833_t6;
    int64_t _833_t7;
    struct0 _833_t5;
    struct1 _833_t1;
    int64_t _833_t8;
    uint8_t _833_t9;
    int64_t _833_t10;
    uint8_t _833_t11;
    int64_t _833_t0;
    int64_t _833_t14;
    uint8_t _833_t15;
    int64_t _833_$retval;
    int64_t _833_t12;
    uint8_t _833_t13;
    _833_t3 = 100;
    _833_t4 = 100;
    _833_t2 = (struct0) {_833_t3, _833_t4};
    _833_t6 = 200;
    _833_t7 = 200;
    _833_t5 = (struct0) {_833_t6, _833_t7};
    _833_t1 = (struct1) {_833_t2, _833_t5};
    _833_t8 = 100;
    _833_t9 = _833_t1._0._0 == _833_t8;
    if (_833_t9) {
        goto BB2;
    } else {
        goto BB7;
    }
BB2:
    _833_t10 = 130;
    _833_t11 = _833_t1._0._1 == _833_t10;
    if (_833_t11) {
        goto BB4;
    } else {
        goto BB7;
    }
BB7:
    _833_t12 = 100;
    _833_t13 = _833_t1._0._0 == _833_t12;
    if (_833_t13) {
        goto BB8;
    } else {
        goto BB12;
    }
BB4:
    _833_t0 = 4;
    goto BB6;
BB8:
    _833_t14 = 100;
    _833_t15 = _833_t1._0._1 == _833_t14;
    if (_833_t15) {
        goto BB10;
    } else {
        goto BB12;
    }
BB12:
    $lines[$line_idx++] = "tests/integration/pattern/match-product-product.orng:6:28:\n        else => unreachable\n                          ^";
    $panic("reached unreachable code\n");
BB6:
    _833_$retval = _833_t0;
    return _833_$retval;
BB10:
    _833_t0 = 170;
    goto BB6;
}

int main(void) {
  printf("%ld",_833_main());
  return 0;
}
