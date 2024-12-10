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
int64_t _1361_main(void);


/* Function definitions */
int64_t _1361_main(void){
    int64_t _1361_t3;
    int64_t _1361_t4;
    struct struct0 _1361_t2;
    int64_t _1361_t6;
    int64_t _1361_t7;
    struct struct0 _1361_t5;
    struct struct1 _1361_t1;
    int64_t _1361_t8;
    uint8_t _1361_t9;
    int64_t _1361_t10;
    uint8_t _1361_t11;
    int64_t _1361_t0;
    int64_t _1361_t14;
    uint8_t _1361_t15;
    int64_t _1361_$retval;
    int64_t _1361_t12;
    uint8_t _1361_t13;
    _1361_t3 = 100;
    _1361_t4 = 100;
    _1361_t2 = (struct struct0) {_1361_t3, _1361_t4};
    _1361_t6 = 200;
    _1361_t7 = 200;
    _1361_t5 = (struct struct0) {_1361_t6, _1361_t7};
    _1361_t1 = (struct struct1) {_1361_t2, _1361_t5};
    _1361_t8 = 100;
    _1361_t9 = _1361_t1._0._0==_1361_t8;
    if (_1361_t9) {
        goto BB1565;
    } else {
        goto BB1570;
    }
BB1565:
    _1361_t10 = 130;
    _1361_t11 = _1361_t1._0._1==_1361_t10;
    if (_1361_t11) {
        goto BB1567;
    } else {
        goto BB1570;
    }
BB1570:
    _1361_t12 = 100;
    _1361_t13 = _1361_t1._0._0==_1361_t12;
    if (_1361_t13) {
        goto BB1571;
    } else {
        goto BB1575;
    }
BB1567:
    _1361_t0 = 4;
    goto BB1569;
BB1571:
    _1361_t14 = 100;
    _1361_t15 = _1361_t1._0._1==_1361_t14;
    if (_1361_t15) {
        goto BB1573;
    } else {
        goto BB1575;
    }
BB1575:
    $lines[$line_idx++] = "tests/integration/pattern/match-product-product.orng:6:39:\n        _               => unreachable\n                                     ^";
    $panic("reached unreachable code\n");
BB1569:
    _1361_$retval = _1361_t0;
    return _1361_$retval;
BB1573:
    _1361_t0 = 170;
    goto BB1569;
}


int main(void) {
  printf("%ld",_1361_main());
  return 0;
}
