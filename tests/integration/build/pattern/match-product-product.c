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
int64_t _1363_main(void);


/* Function definitions */
int64_t _1363_main(void){
    int64_t _1363_t3;
    int64_t _1363_t4;
    struct struct0 _1363_t2;
    int64_t _1363_t6;
    int64_t _1363_t7;
    struct struct0 _1363_t5;
    struct struct1 _1363_t1;
    int64_t _1363_t8;
    uint8_t _1363_t9;
    int64_t _1363_t10;
    uint8_t _1363_t11;
    int64_t _1363_t0;
    int64_t _1363_t14;
    uint8_t _1363_t15;
    int64_t _1363_$retval;
    int64_t _1363_t12;
    uint8_t _1363_t13;
    _1363_t3 = 100;
    _1363_t4 = 100;
    _1363_t2 = (struct struct0) {_1363_t3, _1363_t4};
    _1363_t6 = 200;
    _1363_t7 = 200;
    _1363_t5 = (struct struct0) {_1363_t6, _1363_t7};
    _1363_t1 = (struct struct1) {_1363_t2, _1363_t5};
    _1363_t8 = 100;
    _1363_t9 = _1363_t1._0._0==_1363_t8;
    if (_1363_t9) {
        goto BB1567;
    } else {
        goto BB1572;
    }
BB1567:
    _1363_t10 = 130;
    _1363_t11 = _1363_t1._0._1==_1363_t10;
    if (_1363_t11) {
        goto BB1569;
    } else {
        goto BB1572;
    }
BB1572:
    _1363_t12 = 100;
    _1363_t13 = _1363_t1._0._0==_1363_t12;
    if (_1363_t13) {
        goto BB1573;
    } else {
        goto BB1577;
    }
BB1569:
    _1363_t0 = 4;
    goto BB1571;
BB1573:
    _1363_t14 = 100;
    _1363_t15 = _1363_t1._0._1==_1363_t14;
    if (_1363_t15) {
        goto BB1575;
    } else {
        goto BB1577;
    }
BB1577:
    $lines[$line_idx++] = "tests/integration/pattern/match-product-product.orng:6:39:\n        _               => unreachable\n                                     ^";
    $panic("reached unreachable code\n");
BB1571:
    _1363_$retval = _1363_t0;
    return _1363_$retval;
BB1575:
    _1363_t0 = 170;
    goto BB1571;
}


int main(void) {
  printf("%ld",_1363_main());
  return 0;
}
