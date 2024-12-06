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
int64_t _1333_main(void);


/* Function definitions */
int64_t _1333_main(void){
    int64_t _1333_t3;
    int64_t _1333_t4;
    struct struct0 _1333_t2;
    int64_t _1333_t6;
    int64_t _1333_t7;
    struct struct0 _1333_t5;
    struct struct1 _1333_t1;
    int64_t _1333_t8;
    uint8_t _1333_t9;
    int64_t _1333_t10;
    uint8_t _1333_t11;
    int64_t _1333_t0;
    int64_t _1333_t14;
    uint8_t _1333_t15;
    int64_t _1333_$retval;
    int64_t _1333_t12;
    uint8_t _1333_t13;
    _1333_t3 = 100;
    _1333_t4 = 100;
    _1333_t2 = (struct struct0) {_1333_t3, _1333_t4};
    _1333_t6 = 200;
    _1333_t7 = 200;
    _1333_t5 = (struct struct0) {_1333_t6, _1333_t7};
    _1333_t1 = (struct struct1) {_1333_t2, _1333_t5};
    _1333_t8 = 100;
    _1333_t9 = _1333_t1._0._0==_1333_t8;
    if (_1333_t9) {
        goto BB1536;
    } else {
        goto BB1541;
    }
BB1536:
    _1333_t10 = 130;
    _1333_t11 = _1333_t1._0._1==_1333_t10;
    if (_1333_t11) {
        goto BB1538;
    } else {
        goto BB1541;
    }
BB1541:
    _1333_t12 = 100;
    _1333_t13 = _1333_t1._0._0==_1333_t12;
    if (_1333_t13) {
        goto BB1542;
    } else {
        goto BB1546;
    }
BB1538:
    _1333_t0 = 4;
    goto BB1540;
BB1542:
    _1333_t14 = 100;
    _1333_t15 = _1333_t1._0._1==_1333_t14;
    if (_1333_t15) {
        goto BB1544;
    } else {
        goto BB1546;
    }
BB1546:
    $lines[$line_idx++] = "tests/integration/pattern/match-product-product.orng:6:39:\n        _               => unreachable\n                                     ^";
    $panic("reached unreachable code\n");
BB1540:
    _1333_$retval = _1333_t0;
    return _1333_$retval;
BB1544:
    _1333_t0 = 170;
    goto BB1540;
}


int main(void) {
  printf("%ld",_1333_main());
  return 0;
}
