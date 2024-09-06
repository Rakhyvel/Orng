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
int64_t _1322_main(void);


/* Function definitions */
int64_t _1322_main(void){
    int64_t _1322_t3;
    int64_t _1322_t4;
    struct struct0 _1322_t2;
    int64_t _1322_t6;
    int64_t _1322_t7;
    struct struct0 _1322_t5;
    struct struct1 _1322_t1;
    int64_t _1322_t8;
    uint8_t _1322_t9;
    int64_t _1322_t10;
    uint8_t _1322_t11;
    int64_t _1322_t0;
    int64_t _1322_t14;
    uint8_t _1322_t15;
    int64_t _1322_$retval;
    int64_t _1322_t12;
    uint8_t _1322_t13;
    _1322_t3 = 100;
    _1322_t4 = 100;
    _1322_t2 = (struct struct0) {_1322_t3, _1322_t4};
    _1322_t6 = 200;
    _1322_t7 = 200;
    _1322_t5 = (struct struct0) {_1322_t6, _1322_t7};
    _1322_t1 = (struct struct1) {_1322_t2, _1322_t5};
    _1322_t8 = 100;
    _1322_t9 = _1322_t1._0._0==_1322_t8;
    if (_1322_t9) {
        goto BB1523;
    } else {
        goto BB1528;
    }
BB1523:
    _1322_t10 = 130;
    _1322_t11 = _1322_t1._0._1==_1322_t10;
    if (_1322_t11) {
        goto BB1525;
    } else {
        goto BB1528;
    }
BB1528:
    _1322_t12 = 100;
    _1322_t13 = _1322_t1._0._0==_1322_t12;
    if (_1322_t13) {
        goto BB1529;
    } else {
        goto BB1533;
    }
BB1525:
    _1322_t0 = 4;
    goto BB1527;
BB1529:
    _1322_t14 = 100;
    _1322_t15 = _1322_t1._0._1==_1322_t14;
    if (_1322_t15) {
        goto BB1531;
    } else {
        goto BB1533;
    }
BB1533:
    $lines[$line_idx++] = "tests/integration/pattern/match-product-product.orng:6:39:\n        _               => unreachable\n                                     ^";
    $panic("reached unreachable code\n");
BB1527:
    _1322_$retval = _1322_t0;
    return _1322_$retval;
BB1531:
    _1322_t0 = 170;
    goto BB1527;
}


int main(void) {
  printf("%ld",_1322_main());
  return 0;
}
