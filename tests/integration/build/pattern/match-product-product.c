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
    _1220_t9 = _1220_t1._0._0==_1220_t8;
    if (_1220_t9) {
        goto BB1480;
    } else {
        goto BB1485;
    }
BB1480:
    _1220_t10 = 130;
    _1220_t11 = _1220_t1._0._1==_1220_t10;
    if (_1220_t11) {
        goto BB1482;
    } else {
        goto BB1485;
    }
BB1485:
    _1220_t12 = 100;
    _1220_t13 = _1220_t1._0._0==_1220_t12;
    if (_1220_t13) {
        goto BB1486;
    } else {
        goto BB1490;
    }
BB1482:
    _1220_t0 = 4;
    goto BB1484;
BB1486:
    _1220_t14 = 100;
    _1220_t15 = _1220_t1._0._1==_1220_t14;
    if (_1220_t15) {
        goto BB1488;
    } else {
        goto BB1490;
    }
BB1490:
    $lines[$line_idx++] = "tests/integration/pattern/match-product-product.orng:6:28:\n        else => unreachable\n                          ^";
    $panic("reached unreachable code\n");
BB1484:
    _1220_$retval = _1220_t0;
    return _1220_$retval;
BB1488:
    _1220_t0 = 170;
    goto BB1484;
}

int main(void) {
  printf("%ld",_1220_main());
  return 0;
}
