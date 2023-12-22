/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef struct {
    int64_t _0;
    int64_t _1;
} struct0;

typedef struct {
    struct0 _0;
    struct0 _1;
} struct1;

/* Function forward definitions */
int64_t _1220_main(void);

/* Function definitions */
int64_t _1220_main(void){
    int64_t _1220_t3;
    int64_t _1220_t4;
    struct0 _1220_t2;
    int64_t _1220_t6;
    int64_t _1220_t7;
    struct0 _1220_t5;
    struct1 _1220_t1;
    int64_t _1220_t8;
    uint8_t _1220_t9;
    int64_t _1220_t10;
    uint8_t _1220_t11;
    int64_t _1220_t0;
    int64_t _1220_t14;
    uint8_t _1220_t15;
    int64_t _1220_$retval;
    int64_t _1220_t12;
    uint8_t _1220_t13;
    _1220_t3 = 100;
    _1220_t4 = 100;
    _1220_t2 = (struct0) {_1220_t3, _1220_t4};
    _1220_t6 = 200;
    _1220_t7 = 200;
    _1220_t5 = (struct0) {_1220_t6, _1220_t7};
    _1220_t1 = (struct1) {_1220_t2, _1220_t5};
    _1220_t8 = 100;
    _1220_t9 = _1220_t1._0._0 == _1220_t8;
    if (_1220_t9) {
        goto BB1497;
    } else {
        goto BB1502;
    }
BB1497:
    _1220_t10 = 130;
    _1220_t11 = _1220_t1._0._1 == _1220_t10;
    if (_1220_t11) {
        goto BB1499;
    } else {
        goto BB1502;
    }
BB1502:
    _1220_t12 = 100;
    _1220_t13 = _1220_t1._0._0 == _1220_t12;
    if (_1220_t13) {
        goto BB1503;
    } else {
        goto BB1507;
    }
BB1499:
    _1220_t0 = 4;
    goto BB1501;
BB1503:
    _1220_t14 = 100;
    _1220_t15 = _1220_t1._0._1 == _1220_t14;
    if (_1220_t15) {
        goto BB1505;
    } else {
        goto BB1507;
    }
BB1507:
    $lines[$line_idx++] = "tests/integration/pattern/match-product-product.orng:6:28:\n        else => unreachable\n                          ^";
    $panic("reached unreachable code\n");
BB1501:
    _1220_$retval = _1220_t0;
    return _1220_$retval;
BB1505:
    _1220_t0 = 170;
    goto BB1501;
}

int main(void) {
  printf("%ld",_1220_main());
  return 0;
}
