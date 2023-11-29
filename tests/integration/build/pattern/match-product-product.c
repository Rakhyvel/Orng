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
int64_t _1163_main(void);

/* Function definitions */
int64_t _1163_main(void) {
    int64_t _1163_t3;
    int64_t _1163_t4;
    struct0 _1163_t2;
    int64_t _1163_t6;
    int64_t _1163_t7;
    struct0 _1163_t5;
    struct1 _1163_t1;
    int64_t _1163_t8;
    uint8_t _1163_t9;
    int64_t _1163_t10;
    uint8_t _1163_t11;
    int64_t _1163_t0;
    int64_t _1163_t14;
    uint8_t _1163_t15;
    int64_t _1163_$retval;
    int64_t _1163_t12;
    uint8_t _1163_t13;
    _1163_t3 = 100;
    _1163_t4 = 100;
    _1163_t2 = (struct0) {_1163_t3, _1163_t4};
    _1163_t6 = 200;
    _1163_t7 = 200;
    _1163_t5 = (struct0) {_1163_t6, _1163_t7};
    _1163_t1 = (struct1) {_1163_t2, _1163_t5};
    _1163_t8 = 100;
    _1163_t9 = _1163_t1._0._0 == _1163_t8;
    if (_1163_t9) {
        goto BB2;
    } else {
        goto BB7;
    }
BB2:
    _1163_t10 = 130;
    _1163_t11 = _1163_t1._0._1 == _1163_t10;
    if (_1163_t11) {
        goto BB4;
    } else {
        goto BB7;
    }
BB7:
    _1163_t12 = 100;
    _1163_t13 = _1163_t1._0._0 == _1163_t12;
    if (_1163_t13) {
        goto BB8;
    } else {
        goto BB12;
    }
BB4:
    _1163_t0 = 4;
    goto BB6;
BB8:
    _1163_t14 = 100;
    _1163_t15 = _1163_t1._0._1 == _1163_t14;
    if (_1163_t15) {
        goto BB10;
    } else {
        goto BB12;
    }
BB12:
    $lines[$line_idx++] = "tests/integration/pattern/match-product-product.orng:6:28:\n        else => unreachable\n                          ^";
    $panic("reached unreachable code\n");
BB6:
    _1163_$retval = _1163_t0;
    return _1163_$retval;
BB10:
    _1163_t0 = 170;
    goto BB6;
}

int main(void) {
  printf("%ld",_1163_main());
  return 0;
}
