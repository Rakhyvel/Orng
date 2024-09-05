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
int64_t _1319_main(void);


/* Function definitions */
int64_t _1319_main(void){
    int64_t _1319_t3;
    int64_t _1319_t4;
    struct struct0 _1319_t2;
    int64_t _1319_t6;
    int64_t _1319_t7;
    struct struct0 _1319_t5;
    struct struct1 _1319_t1;
    int64_t _1319_t8;
    uint8_t _1319_t9;
    int64_t _1319_t10;
    uint8_t _1319_t11;
    int64_t _1319_t0;
    int64_t _1319_t14;
    uint8_t _1319_t15;
    int64_t _1319_$retval;
    int64_t _1319_t12;
    uint8_t _1319_t13;
    _1319_t3 = 100;
    _1319_t4 = 100;
    _1319_t2 = (struct struct0) {_1319_t3, _1319_t4};
    _1319_t6 = 200;
    _1319_t7 = 200;
    _1319_t5 = (struct struct0) {_1319_t6, _1319_t7};
    _1319_t1 = (struct struct1) {_1319_t2, _1319_t5};
    _1319_t8 = 100;
    _1319_t9 = _1319_t1._0._0==_1319_t8;
    if (_1319_t9) {
        goto BB1520;
    } else {
        goto BB1525;
    }
BB1520:
    _1319_t10 = 130;
    _1319_t11 = _1319_t1._0._1==_1319_t10;
    if (_1319_t11) {
        goto BB1522;
    } else {
        goto BB1525;
    }
BB1525:
    _1319_t12 = 100;
    _1319_t13 = _1319_t1._0._0==_1319_t12;
    if (_1319_t13) {
        goto BB1526;
    } else {
        goto BB1530;
    }
BB1522:
    _1319_t0 = 4;
    goto BB1524;
BB1526:
    _1319_t14 = 100;
    _1319_t15 = _1319_t1._0._1==_1319_t14;
    if (_1319_t15) {
        goto BB1528;
    } else {
        goto BB1530;
    }
BB1530:
    $lines[$line_idx++] = "tests/integration/pattern/match-product-product.orng:6:39:\n        _               => unreachable\n                                     ^";
    $panic("reached unreachable code\n");
BB1524:
    _1319_$retval = _1319_t0;
    return _1319_$retval;
BB1528:
    _1319_t0 = 170;
    goto BB1524;
}


int main(void) {
  printf("%ld",_1319_main());
  return 0;
}
