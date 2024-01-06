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
int64_t _1244_main(void);

/* Function definitions */
int64_t _1244_main(void){
    int64_t _1244_t3;
    int64_t _1244_t4;
    struct struct0 _1244_t2;
    int64_t _1244_t6;
    int64_t _1244_t7;
    struct struct0 _1244_t5;
    struct struct1 _1244_t1;
    int64_t _1244_t8;
    uint8_t _1244_t9;
    int64_t _1244_t10;
    uint8_t _1244_t11;
    int64_t _1244_t0;
    int64_t _1244_t14;
    uint8_t _1244_t15;
    int64_t _1244_$retval;
    int64_t _1244_t12;
    uint8_t _1244_t13;
    _1244_t3 = 100;
    _1244_t4 = 100;
    _1244_t2 = (struct struct0) {_1244_t3, _1244_t4};
    _1244_t6 = 200;
    _1244_t7 = 200;
    _1244_t5 = (struct struct0) {_1244_t6, _1244_t7};
    _1244_t1 = (struct struct1) {_1244_t2, _1244_t5};
    _1244_t8 = 100;
    _1244_t9 = _1244_t1._0._0==_1244_t8;
    if (_1244_t9) {
        goto BB1473;
    } else {
        goto BB1478;
    }
BB1473:
    _1244_t10 = 130;
    _1244_t11 = _1244_t1._0._1==_1244_t10;
    if (_1244_t11) {
        goto BB1475;
    } else {
        goto BB1478;
    }
BB1478:
    _1244_t12 = 100;
    _1244_t13 = _1244_t1._0._0==_1244_t12;
    if (_1244_t13) {
        goto BB1479;
    } else {
        goto BB1483;
    }
BB1475:
    _1244_t0 = 4;
    goto BB1477;
BB1479:
    _1244_t14 = 100;
    _1244_t15 = _1244_t1._0._1==_1244_t14;
    if (_1244_t15) {
        goto BB1481;
    } else {
        goto BB1483;
    }
BB1483:
    $lines[$line_idx++] = "tests/integration/pattern/match-product-product.orng:6:39:\n        _               => unreachable\n                                     ^";
    $panic("reached unreachable code\n");
BB1477:
    _1244_$retval = _1244_t0;
    return _1244_$retval;
BB1481:
    _1244_t0 = 170;
    goto BB1477;
}

int main(void) {
  printf("%ld",_1244_main());
  return 0;
}
