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
    int64_t _0;
    int64_t _1;
};

struct struct1 {
    struct struct0 _0;
    struct struct0 _1;
};

/* Function forward definitions */
int64_t _1236_main(void);

/* Function definitions */
int64_t _1236_main(void){
    int64_t _1236_t3;
    int64_t _1236_t4;
    struct struct0 _1236_t2;
    int64_t _1236_t6;
    int64_t _1236_t7;
    struct struct0 _1236_t5;
    struct struct1 _1236_t1;
    int64_t _1236_t8;
    uint8_t _1236_t9;
    int64_t _1236_t10;
    uint8_t _1236_t11;
    int64_t _1236_t0;
    int64_t _1236_t14;
    uint8_t _1236_t15;
    int64_t _1236_$retval;
    int64_t _1236_t12;
    uint8_t _1236_t13;
    _1236_t3 = 100;
    _1236_t4 = 100;
    _1236_t2 = (struct struct0) {_1236_t3, _1236_t4};
    _1236_t6 = 200;
    _1236_t7 = 200;
    _1236_t5 = (struct struct0) {_1236_t6, _1236_t7};
    _1236_t1 = (struct struct1) {_1236_t2, _1236_t5};
    _1236_t8 = 100;
    _1236_t9 = _1236_t1._0._0==_1236_t8;
    if (_1236_t9) {
        goto BB1477;
    } else {
        goto BB1482;
    }
BB1477:
    _1236_t10 = 130;
    _1236_t11 = _1236_t1._0._1==_1236_t10;
    if (_1236_t11) {
        goto BB1479;
    } else {
        goto BB1482;
    }
BB1482:
    _1236_t12 = 100;
    _1236_t13 = _1236_t1._0._0==_1236_t12;
    if (_1236_t13) {
        goto BB1483;
    } else {
        goto BB1487;
    }
BB1479:
    _1236_t0 = 4;
    goto BB1481;
BB1483:
    _1236_t14 = 100;
    _1236_t15 = _1236_t1._0._1==_1236_t14;
    if (_1236_t15) {
        goto BB1485;
    } else {
        goto BB1487;
    }
BB1487:
    $lines[$line_idx++] = "tests/integration/pattern/match-product-product.orng:6:39:\n        _               => unreachable\n                                     ^";
    $panic("reached unreachable code\n");
BB1481:
    _1236_$retval = _1236_t0;
    return _1236_$retval;
BB1485:
    _1236_t0 = 170;
    goto BB1481;
}

int main(void) {
  printf("%ld",_1236_main());
  return 0;
}
