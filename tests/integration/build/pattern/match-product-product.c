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
int64_t _1346_main(void);


/* Function definitions */
int64_t _1346_main(void){
    int64_t _1346_t3;
    int64_t _1346_t4;
    struct struct0 _1346_t2;
    int64_t _1346_t6;
    int64_t _1346_t7;
    struct struct0 _1346_t5;
    struct struct1 _1346_t1;
    int64_t _1346_t8;
    uint8_t _1346_t9;
    int64_t _1346_t10;
    uint8_t _1346_t11;
    int64_t _1346_t0;
    int64_t _1346_t14;
    uint8_t _1346_t15;
    int64_t _1346_$retval;
    int64_t _1346_t12;
    uint8_t _1346_t13;
    _1346_t3 = 100;
    _1346_t4 = 100;
    _1346_t2 = (struct struct0) {_1346_t3, _1346_t4};
    _1346_t6 = 200;
    _1346_t7 = 200;
    _1346_t5 = (struct struct0) {_1346_t6, _1346_t7};
    _1346_t1 = (struct struct1) {_1346_t2, _1346_t5};
    _1346_t8 = 100;
    _1346_t9 = _1346_t1._0._0==_1346_t8;
    if (_1346_t9) {
        goto BB1549;
    } else {
        goto BB1554;
    }
BB1549:
    _1346_t10 = 130;
    _1346_t11 = _1346_t1._0._1==_1346_t10;
    if (_1346_t11) {
        goto BB1551;
    } else {
        goto BB1554;
    }
BB1554:
    _1346_t12 = 100;
    _1346_t13 = _1346_t1._0._0==_1346_t12;
    if (_1346_t13) {
        goto BB1555;
    } else {
        goto BB1559;
    }
BB1551:
    _1346_t0 = 4;
    goto BB1553;
BB1555:
    _1346_t14 = 100;
    _1346_t15 = _1346_t1._0._1==_1346_t14;
    if (_1346_t15) {
        goto BB1557;
    } else {
        goto BB1559;
    }
BB1559:
    $lines[$line_idx++] = "tests/integration/pattern/match-product-product.orng:6:39:\n        _               => unreachable\n                                     ^";
    $panic("reached unreachable code\n");
BB1553:
    _1346_$retval = _1346_t0;
    return _1346_$retval;
BB1557:
    _1346_t0 = 170;
    goto BB1553;
}


int main(void) {
  printf("%ld",_1346_main());
  return 0;
}
