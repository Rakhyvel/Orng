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
int64_t _1239_main(void);

/* Function definitions */
int64_t _1239_main(void){
    int64_t _1239_t3;
    int64_t _1239_t4;
    struct struct0 _1239_t2;
    int64_t _1239_t6;
    int64_t _1239_t7;
    struct struct0 _1239_t5;
    struct struct1 _1239_t1;
    int64_t _1239_t8;
    uint8_t _1239_t9;
    int64_t _1239_t10;
    uint8_t _1239_t11;
    int64_t _1239_t0;
    int64_t _1239_t14;
    uint8_t _1239_t15;
    int64_t _1239_$retval;
    int64_t _1239_t12;
    uint8_t _1239_t13;
    _1239_t3 = 100;
    _1239_t4 = 100;
    _1239_t2 = (struct struct0) {_1239_t3, _1239_t4};
    _1239_t6 = 200;
    _1239_t7 = 200;
    _1239_t5 = (struct struct0) {_1239_t6, _1239_t7};
    _1239_t1 = (struct struct1) {_1239_t2, _1239_t5};
    _1239_t8 = 100;
    _1239_t9 = _1239_t1._0._0==_1239_t8;
    if (_1239_t9) {
        goto BB1469;
    } else {
        goto BB1474;
    }
BB1469:
    _1239_t10 = 130;
    _1239_t11 = _1239_t1._0._1==_1239_t10;
    if (_1239_t11) {
        goto BB1471;
    } else {
        goto BB1474;
    }
BB1474:
    _1239_t12 = 100;
    _1239_t13 = _1239_t1._0._0==_1239_t12;
    if (_1239_t13) {
        goto BB1475;
    } else {
        goto BB1479;
    }
BB1471:
    _1239_t0 = 4;
    goto BB1473;
BB1475:
    _1239_t14 = 100;
    _1239_t15 = _1239_t1._0._1==_1239_t14;
    if (_1239_t15) {
        goto BB1477;
    } else {
        goto BB1479;
    }
BB1479:
    $lines[$line_idx++] = "tests/integration/pattern/match-product-product.orng:6:39:\n        _               => unreachable\n                                     ^";
    $panic("reached unreachable code\n");
BB1473:
    _1239_$retval = _1239_t0;
    return _1239_$retval;
BB1477:
    _1239_t0 = 170;
    goto BB1473;
}

int main(void) {
  printf("%ld",_1239_main());
  return 0;
}
