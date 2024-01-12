/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward typedefs */
struct struct0;
struct struct1;

/* Typedefs */
struct struct0 {
    int64_t _0;
    int64_t _1;
};

struct struct1 {
    struct struct0 _0;
    struct struct0 _1;
};

/* Function forward definitions */
int64_t _1254_main(void);

/* Function definitions */
int64_t _1254_main(void){
    int64_t _1254_t3;
    int64_t _1254_t4;
    struct struct0 _1254_t2;
    int64_t _1254_t6;
    int64_t _1254_t7;
    struct struct0 _1254_t5;
    struct struct1 _1254_t1;
    int64_t _1254_t8;
    uint8_t _1254_t9;
    int64_t _1254_t10;
    uint8_t _1254_t11;
    int64_t _1254_t0;
    int64_t _1254_t14;
    uint8_t _1254_t15;
    int64_t _1254_$retval;
    int64_t _1254_t12;
    uint8_t _1254_t13;
    _1254_t3 = 100;
    _1254_t4 = 100;
    _1254_t2 = (struct struct0) {_1254_t3, _1254_t4};
    _1254_t6 = 200;
    _1254_t7 = 200;
    _1254_t5 = (struct struct0) {_1254_t6, _1254_t7};
    _1254_t1 = (struct struct1) {_1254_t2, _1254_t5};
    _1254_t8 = 100;
    _1254_t9 = _1254_t1._0._0==_1254_t8;
    if (_1254_t9) {
        goto BB1485;
    } else {
        goto BB1490;
    }
BB1485:
    _1254_t10 = 130;
    _1254_t11 = _1254_t1._0._1==_1254_t10;
    if (_1254_t11) {
        goto BB1487;
    } else {
        goto BB1490;
    }
BB1490:
    _1254_t12 = 100;
    _1254_t13 = _1254_t1._0._0==_1254_t12;
    if (_1254_t13) {
        goto BB1491;
    } else {
        goto BB1495;
    }
BB1487:
    _1254_t0 = 4;
    goto BB1489;
BB1491:
    _1254_t14 = 100;
    _1254_t15 = _1254_t1._0._1==_1254_t14;
    if (_1254_t15) {
        goto BB1493;
    } else {
        goto BB1495;
    }
BB1495:
    $lines[$line_idx++] = "tests/integration/pattern/match-product-product.orng:6:39:\n        _               => unreachable\n                                     ^";
    $panic("reached unreachable code\n");
BB1489:
    _1254_$retval = _1254_t0;
    return _1254_$retval;
BB1493:
    _1254_t0 = 170;
    goto BB1489;
}

int main(void) {
  printf("%ld",_1254_main());
  return 0;
}
