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
int64_t _1255_main(void);


/* Function definitions */
int64_t _1255_main(void){
    int64_t _1255_t3;
    int64_t _1255_t4;
    struct struct0 _1255_t2;
    int64_t _1255_t6;
    int64_t _1255_t7;
    struct struct0 _1255_t5;
    struct struct1 _1255_t1;
    int64_t _1255_t8;
    uint8_t _1255_t9;
    int64_t _1255_t10;
    uint8_t _1255_t11;
    int64_t _1255_t0;
    int64_t _1255_t14;
    uint8_t _1255_t15;
    int64_t _1255_$retval;
    int64_t _1255_t12;
    uint8_t _1255_t13;
    _1255_t3 = 100;
    _1255_t4 = 100;
    _1255_t2 = (struct struct0) {_1255_t3, _1255_t4};
    _1255_t6 = 200;
    _1255_t7 = 200;
    _1255_t5 = (struct struct0) {_1255_t6, _1255_t7};
    _1255_t1 = (struct struct1) {_1255_t2, _1255_t5};
    _1255_t8 = 100;
    _1255_t9 = _1255_t1._0._0==_1255_t8;
    if (_1255_t9) {
        goto BB1452;
    } else {
        goto BB1457;
    }
BB1452:
    _1255_t10 = 130;
    _1255_t11 = _1255_t1._0._1==_1255_t10;
    if (_1255_t11) {
        goto BB1454;
    } else {
        goto BB1457;
    }
BB1457:
    _1255_t12 = 100;
    _1255_t13 = _1255_t1._0._0==_1255_t12;
    if (_1255_t13) {
        goto BB1458;
    } else {
        goto BB1462;
    }
BB1454:
    _1255_t0 = 4;
    goto BB1456;
BB1458:
    _1255_t14 = 100;
    _1255_t15 = _1255_t1._0._1==_1255_t14;
    if (_1255_t15) {
        goto BB1460;
    } else {
        goto BB1462;
    }
BB1462:
    $lines[$line_idx++] = "tests/integration/pattern/match-product-product.orng:6:39:\n        _               => unreachable\n                                     ^";
    $panic("reached unreachable code\n");
BB1456:
    _1255_$retval = _1255_t0;
    return _1255_$retval;
BB1460:
    _1255_t0 = 170;
    goto BB1456;
}


int main(void) {
  printf("%ld",_1255_main());
  return 0;
}
