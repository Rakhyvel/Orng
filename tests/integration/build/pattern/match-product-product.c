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
int64_t _1259_main(void);


/* Function definitions */
int64_t _1259_main(void){
    int64_t _1259_t3;
    int64_t _1259_t4;
    struct struct0 _1259_t2;
    int64_t _1259_t6;
    int64_t _1259_t7;
    struct struct0 _1259_t5;
    struct struct1 _1259_t1;
    int64_t _1259_t8;
    uint8_t _1259_t9;
    int64_t _1259_t10;
    uint8_t _1259_t11;
    int64_t _1259_t0;
    int64_t _1259_t14;
    uint8_t _1259_t15;
    int64_t _1259_$retval;
    int64_t _1259_t12;
    uint8_t _1259_t13;
    _1259_t3 = 100;
    _1259_t4 = 100;
    _1259_t2 = (struct struct0) {_1259_t3, _1259_t4};
    _1259_t6 = 200;
    _1259_t7 = 200;
    _1259_t5 = (struct struct0) {_1259_t6, _1259_t7};
    _1259_t1 = (struct struct1) {_1259_t2, _1259_t5};
    _1259_t8 = 100;
    _1259_t9 = _1259_t1._0._0==_1259_t8;
    if (_1259_t9) {
        goto BB1489;
    } else {
        goto BB1494;
    }
BB1489:
    _1259_t10 = 130;
    _1259_t11 = _1259_t1._0._1==_1259_t10;
    if (_1259_t11) {
        goto BB1491;
    } else {
        goto BB1494;
    }
BB1494:
    _1259_t12 = 100;
    _1259_t13 = _1259_t1._0._0==_1259_t12;
    if (_1259_t13) {
        goto BB1495;
    } else {
        goto BB1499;
    }
BB1491:
    _1259_t0 = 4;
    goto BB1493;
BB1495:
    _1259_t14 = 100;
    _1259_t15 = _1259_t1._0._1==_1259_t14;
    if (_1259_t15) {
        goto BB1497;
    } else {
        goto BB1499;
    }
BB1499:
    $lines[$line_idx++] = "tests/integration/pattern/match-product-product.orng:6:39:\n        _               => unreachable\n                                     ^";
    $panic("reached unreachable code\n");
BB1493:
    _1259_$retval = _1259_t0;
    return _1259_$retval;
BB1497:
    _1259_t0 = 170;
    goto BB1493;
}


int main(void) {
  printf("%ld",_1259_main());
  return 0;
}
