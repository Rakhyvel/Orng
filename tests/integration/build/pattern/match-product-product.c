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
int64_t _1286_main(void);


/* Function definitions */
int64_t _1286_main(void){
    int64_t _1286_t3;
    int64_t _1286_t4;
    struct struct0 _1286_t2;
    int64_t _1286_t6;
    int64_t _1286_t7;
    struct struct0 _1286_t5;
    struct struct1 _1286_t1;
    int64_t _1286_t8;
    uint8_t _1286_t9;
    int64_t _1286_t10;
    uint8_t _1286_t11;
    int64_t _1286_t0;
    int64_t _1286_t14;
    uint8_t _1286_t15;
    int64_t _1286_$retval;
    int64_t _1286_t12;
    uint8_t _1286_t13;
    _1286_t3 = 100;
    _1286_t4 = 100;
    _1286_t2 = (struct struct0) {_1286_t3, _1286_t4};
    _1286_t6 = 200;
    _1286_t7 = 200;
    _1286_t5 = (struct struct0) {_1286_t6, _1286_t7};
    _1286_t1 = (struct struct1) {_1286_t2, _1286_t5};
    _1286_t8 = 100;
    _1286_t9 = _1286_t1._0._0==_1286_t8;
    if (_1286_t9) {
        goto BB1511;
    } else {
        goto BB1516;
    }
BB1511:
    _1286_t10 = 130;
    _1286_t11 = _1286_t1._0._1==_1286_t10;
    if (_1286_t11) {
        goto BB1513;
    } else {
        goto BB1516;
    }
BB1516:
    _1286_t12 = 100;
    _1286_t13 = _1286_t1._0._0==_1286_t12;
    if (_1286_t13) {
        goto BB1517;
    } else {
        goto BB1521;
    }
BB1513:
    _1286_t0 = 4;
    goto BB1515;
BB1517:
    _1286_t14 = 100;
    _1286_t15 = _1286_t1._0._1==_1286_t14;
    if (_1286_t15) {
        goto BB1519;
    } else {
        goto BB1521;
    }
BB1521:
    $lines[$line_idx++] = "tests/integration/pattern/match-product-product.orng:6:39:\n        _               => unreachable\n                                     ^";
    $panic("reached unreachable code\n");
BB1515:
    _1286_$retval = _1286_t0;
    return _1286_$retval;
BB1519:
    _1286_t0 = 170;
    goto BB1515;
}


int main(void) {
  printf("%ld",_1286_main());
  return 0;
}
