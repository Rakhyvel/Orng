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
int64_t _1289_main(void);


/* Function definitions */
int64_t _1289_main(void){
    int64_t _1289_t3;
    int64_t _1289_t4;
    struct struct0 _1289_t2;
    int64_t _1289_t6;
    int64_t _1289_t7;
    struct struct0 _1289_t5;
    struct struct1 _1289_t1;
    int64_t _1289_t8;
    uint8_t _1289_t9;
    int64_t _1289_t10;
    uint8_t _1289_t11;
    int64_t _1289_t0;
    int64_t _1289_t14;
    uint8_t _1289_t15;
    int64_t _1289_$retval;
    int64_t _1289_t12;
    uint8_t _1289_t13;
    _1289_t3 = 100;
    _1289_t4 = 100;
    _1289_t2 = (struct struct0) {_1289_t3, _1289_t4};
    _1289_t6 = 200;
    _1289_t7 = 200;
    _1289_t5 = (struct struct0) {_1289_t6, _1289_t7};
    _1289_t1 = (struct struct1) {_1289_t2, _1289_t5};
    _1289_t8 = 100;
    _1289_t9 = _1289_t1._0._0==_1289_t8;
    if (_1289_t9) {
        goto BB1505;
    } else {
        goto BB1510;
    }
BB1505:
    _1289_t10 = 130;
    _1289_t11 = _1289_t1._0._1==_1289_t10;
    if (_1289_t11) {
        goto BB1507;
    } else {
        goto BB1510;
    }
BB1510:
    _1289_t12 = 100;
    _1289_t13 = _1289_t1._0._0==_1289_t12;
    if (_1289_t13) {
        goto BB1511;
    } else {
        goto BB1515;
    }
BB1507:
    _1289_t0 = 4;
    goto BB1509;
BB1511:
    _1289_t14 = 100;
    _1289_t15 = _1289_t1._0._1==_1289_t14;
    if (_1289_t15) {
        goto BB1513;
    } else {
        goto BB1515;
    }
BB1515:
    $lines[$line_idx++] = "tests/integration/pattern/match-product-product.orng:6:39:\n        _               => unreachable\n                                     ^";
    $panic("reached unreachable code\n");
BB1509:
    _1289_$retval = _1289_t0;
    return _1289_$retval;
BB1513:
    _1289_t0 = 170;
    goto BB1509;
}


int main(void) {
  printf("%ld",_1289_main());
  return 0;
}
