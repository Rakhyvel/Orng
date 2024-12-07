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
    int64_t _0;
    int64_t _1;
};

struct struct1 {
    struct struct0 _0;
    struct struct0 _1;
};

/* Function forward definitions */
int64_t _1341_main(void);


/* Function definitions */
int64_t _1341_main(void){
    int64_t _1341_t3;
    int64_t _1341_t4;
    struct struct0 _1341_t2;
    int64_t _1341_t6;
    int64_t _1341_t7;
    struct struct0 _1341_t5;
    struct struct1 _1341_t1;
    int64_t _1341_t8;
    uint8_t _1341_t9;
    int64_t _1341_t10;
    uint8_t _1341_t11;
    int64_t _1341_t0;
    int64_t _1341_t14;
    uint8_t _1341_t15;
    int64_t _1341_$retval;
    int64_t _1341_t12;
    uint8_t _1341_t13;
    _1341_t3 = 100;
    _1341_t4 = 100;
    _1341_t2 = (struct struct0) {_1341_t3, _1341_t4};
    _1341_t6 = 200;
    _1341_t7 = 200;
    _1341_t5 = (struct struct0) {_1341_t6, _1341_t7};
    _1341_t1 = (struct struct1) {_1341_t2, _1341_t5};
    _1341_t8 = 100;
    _1341_t9 = _1341_t1._0._0==_1341_t8;
    if (_1341_t9) {
        goto BB1546;
    } else {
        goto BB1551;
    }
BB1546:
    _1341_t10 = 130;
    _1341_t11 = _1341_t1._0._1==_1341_t10;
    if (_1341_t11) {
        goto BB1548;
    } else {
        goto BB1551;
    }
BB1551:
    _1341_t12 = 100;
    _1341_t13 = _1341_t1._0._0==_1341_t12;
    if (_1341_t13) {
        goto BB1552;
    } else {
        goto BB1556;
    }
BB1548:
    _1341_t0 = 4;
    goto BB1550;
BB1552:
    _1341_t14 = 100;
    _1341_t15 = _1341_t1._0._1==_1341_t14;
    if (_1341_t15) {
        goto BB1554;
    } else {
        goto BB1556;
    }
BB1556:
    $lines[$line_idx++] = "tests/integration/pattern/match-product-product.orng:6:39:\n        _               => unreachable\n                                     ^";
    $panic("reached unreachable code\n");
BB1550:
    _1341_$retval = _1341_t0;
    return _1341_$retval;
BB1554:
    _1341_t0 = 170;
    goto BB1550;
}


int main(void) {
  printf("%ld",_1341_main());
  return 0;
}
