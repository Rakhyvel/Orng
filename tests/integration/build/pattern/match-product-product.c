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
int64_t _1264_main(void);


/* Function definitions */
int64_t _1264_main(void){
    int64_t _1264_t3;
    int64_t _1264_t4;
    struct struct0 _1264_t2;
    int64_t _1264_t6;
    int64_t _1264_t7;
    struct struct0 _1264_t5;
    struct struct1 _1264_t1;
    int64_t _1264_t8;
    uint8_t _1264_t9;
    int64_t _1264_t10;
    uint8_t _1264_t11;
    int64_t _1264_t0;
    int64_t _1264_t14;
    uint8_t _1264_t15;
    int64_t _1264_$retval;
    int64_t _1264_t12;
    uint8_t _1264_t13;
    _1264_t3 = 100;
    _1264_t4 = 100;
    _1264_t2 = (struct struct0) {_1264_t3, _1264_t4};
    _1264_t6 = 200;
    _1264_t7 = 200;
    _1264_t5 = (struct struct0) {_1264_t6, _1264_t7};
    _1264_t1 = (struct struct1) {_1264_t2, _1264_t5};
    _1264_t8 = 100;
    _1264_t9 = _1264_t1._0._0==_1264_t8;
    if (_1264_t9) {
        goto BB1458;
    } else {
        goto BB1463;
    }
BB1458:
    _1264_t10 = 130;
    _1264_t11 = _1264_t1._0._1==_1264_t10;
    if (_1264_t11) {
        goto BB1460;
    } else {
        goto BB1463;
    }
BB1463:
    _1264_t12 = 100;
    _1264_t13 = _1264_t1._0._0==_1264_t12;
    if (_1264_t13) {
        goto BB1464;
    } else {
        goto BB1468;
    }
BB1460:
    _1264_t0 = 4;
    goto BB1462;
BB1464:
    _1264_t14 = 100;
    _1264_t15 = _1264_t1._0._1==_1264_t14;
    if (_1264_t15) {
        goto BB1466;
    } else {
        goto BB1468;
    }
BB1468:
    $lines[$line_idx++] = "tests/integration/pattern/match-product-product.orng:6:39:\n        _               => unreachable\n                                     ^";
    $panic("reached unreachable code\n");
BB1462:
    _1264_$retval = _1264_t0;
    return _1264_$retval;
BB1466:
    _1264_t0 = 170;
    goto BB1462;
}


int main(void) {
  printf("%ld",_1264_main());
  return 0;
}
