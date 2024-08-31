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
int64_t _1269_main(void);


/* Function definitions */
int64_t _1269_main(void){
    int64_t _1269_t3;
    int64_t _1269_t4;
    struct struct0 _1269_t2;
    int64_t _1269_t6;
    int64_t _1269_t7;
    struct struct0 _1269_t5;
    struct struct1 _1269_t1;
    int64_t _1269_t8;
    uint8_t _1269_t9;
    int64_t _1269_t10;
    uint8_t _1269_t11;
    int64_t _1269_t0;
    int64_t _1269_t14;
    uint8_t _1269_t15;
    int64_t _1269_$retval;
    int64_t _1269_t12;
    uint8_t _1269_t13;
    _1269_t3 = 100;
    _1269_t4 = 100;
    _1269_t2 = (struct struct0) {_1269_t3, _1269_t4};
    _1269_t6 = 200;
    _1269_t7 = 200;
    _1269_t5 = (struct struct0) {_1269_t6, _1269_t7};
    _1269_t1 = (struct struct1) {_1269_t2, _1269_t5};
    _1269_t8 = 100;
    _1269_t9 = _1269_t1._0._0==_1269_t8;
    if (_1269_t9) {
        goto BB1462;
    } else {
        goto BB1467;
    }
BB1462:
    _1269_t10 = 130;
    _1269_t11 = _1269_t1._0._1==_1269_t10;
    if (_1269_t11) {
        goto BB1464;
    } else {
        goto BB1467;
    }
BB1467:
    _1269_t12 = 100;
    _1269_t13 = _1269_t1._0._0==_1269_t12;
    if (_1269_t13) {
        goto BB1468;
    } else {
        goto BB1472;
    }
BB1464:
    _1269_t0 = 4;
    goto BB1466;
BB1468:
    _1269_t14 = 100;
    _1269_t15 = _1269_t1._0._1==_1269_t14;
    if (_1269_t15) {
        goto BB1470;
    } else {
        goto BB1472;
    }
BB1472:
    $lines[$line_idx++] = "tests/integration/pattern/match-product-product.orng:6:39:\n        _               => unreachable\n                                     ^";
    $panic("reached unreachable code\n");
BB1466:
    _1269_$retval = _1269_t0;
    return _1269_$retval;
BB1470:
    _1269_t0 = 170;
    goto BB1466;
}


int main(void) {
  printf("%ld",_1269_main());
  return 0;
}
