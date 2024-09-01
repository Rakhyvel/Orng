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
int64_t _1308_main(void);


/* Function definitions */
int64_t _1308_main(void){
    int64_t _1308_t3;
    int64_t _1308_t4;
    struct struct0 _1308_t2;
    int64_t _1308_t6;
    int64_t _1308_t7;
    struct struct0 _1308_t5;
    struct struct1 _1308_t1;
    int64_t _1308_t8;
    uint8_t _1308_t9;
    int64_t _1308_t10;
    uint8_t _1308_t11;
    int64_t _1308_t0;
    int64_t _1308_t14;
    uint8_t _1308_t15;
    int64_t _1308_$retval;
    int64_t _1308_t12;
    uint8_t _1308_t13;
    _1308_t3 = 100;
    _1308_t4 = 100;
    _1308_t2 = (struct struct0) {_1308_t3, _1308_t4};
    _1308_t6 = 200;
    _1308_t7 = 200;
    _1308_t5 = (struct struct0) {_1308_t6, _1308_t7};
    _1308_t1 = (struct struct1) {_1308_t2, _1308_t5};
    _1308_t8 = 100;
    _1308_t9 = _1308_t1._0._0==_1308_t8;
    if (_1308_t9) {
        goto BB1510;
    } else {
        goto BB1515;
    }
BB1510:
    _1308_t10 = 130;
    _1308_t11 = _1308_t1._0._1==_1308_t10;
    if (_1308_t11) {
        goto BB1512;
    } else {
        goto BB1515;
    }
BB1515:
    _1308_t12 = 100;
    _1308_t13 = _1308_t1._0._0==_1308_t12;
    if (_1308_t13) {
        goto BB1516;
    } else {
        goto BB1520;
    }
BB1512:
    _1308_t0 = 4;
    goto BB1514;
BB1516:
    _1308_t14 = 100;
    _1308_t15 = _1308_t1._0._1==_1308_t14;
    if (_1308_t15) {
        goto BB1518;
    } else {
        goto BB1520;
    }
BB1520:
    $lines[$line_idx++] = "tests/integration/pattern/match-product-product.orng:6:39:\n        _               => unreachable\n                                     ^";
    $panic("reached unreachable code\n");
BB1514:
    _1308_$retval = _1308_t0;
    return _1308_$retval;
BB1518:
    _1308_t0 = 170;
    goto BB1514;
}


int main(void) {
  printf("%ld",_1308_main());
  return 0;
}
