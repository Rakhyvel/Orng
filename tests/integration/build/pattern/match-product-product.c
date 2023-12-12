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
int64_t _950_main(void);

/* Function definitions */
int64_t _950_main(void) {
    int64_t _950_t3;
    int64_t _950_t4;
    struct0 _950_t2;
    int64_t _950_t6;
    int64_t _950_t7;
    struct0 _950_t5;
    struct1 _950_t1;
    int64_t _950_t8;
    uint8_t _950_t9;
    int64_t _950_t10;
    uint8_t _950_t11;
    int64_t _950_t0;
    int64_t _950_t14;
    uint8_t _950_t15;
    int64_t _950_$retval;
    int64_t _950_t12;
    uint8_t _950_t13;
    _950_t3 = 100;
    _950_t4 = 100;
    _950_t2 = (struct0) {_950_t3, _950_t4};
    _950_t6 = 200;
    _950_t7 = 200;
    _950_t5 = (struct0) {_950_t6, _950_t7};
    _950_t1 = (struct1) {_950_t2, _950_t5};
    _950_t8 = 100;
    _950_t9 = _950_t1._0._0 == _950_t8;
    if (_950_t9) {
        goto BB2;
    } else {
        goto BB7;
    }
BB2:
    _950_t10 = 130;
    _950_t11 = _950_t1._0._1 == _950_t10;
    if (_950_t11) {
        goto BB4;
    } else {
        goto BB7;
    }
BB7:
    _950_t12 = 100;
    _950_t13 = _950_t1._0._0 == _950_t12;
    if (_950_t13) {
        goto BB8;
    } else {
        goto BB12;
    }
BB4:
    _950_t0 = 4;
    goto BB6;
BB8:
    _950_t14 = 100;
    _950_t15 = _950_t1._0._1 == _950_t14;
    if (_950_t15) {
        goto BB10;
    } else {
        goto BB12;
    }
BB12:
    $lines[$line_idx++] = "tests/integration/pattern/match-product-product.orng:6:28:\n        else => unreachable\n                          ^";
    $panic("reached unreachable code\n");
BB6:
    _950_$retval = _950_t0;
    return _950_$retval;
BB10:
    _950_t0 = 170;
    goto BB6;
}

int main(void) {
  printf("%ld",_950_main());
  return 0;
}
