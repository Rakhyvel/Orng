/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward typedefs */
struct struct0;
struct struct1;
struct struct3;

/* Typedefs */
struct struct0 {
    int64_t _0;
    double _1;
};

struct struct1 {
    int64_t _0;
    struct struct0 _1;
    uint32_t _2;
};

struct struct3 {
    struct struct1 _0;
    struct struct1 _1;
};

typedef uint8_t(*function2)(struct struct1, struct struct1);

/* Function forward definitions */
int64_t _1585_main(void);
uint8_t _1590_f(struct struct1 _1590_x, struct struct1 _1590_y);

/* Function definitions */
int64_t _1585_main(void){
    int64_t _1585_t1;
    int64_t _1585_t3;
    double _1585_t4;
    struct struct0 _1585_t2;
    uint32_t _1585_t5;
    struct struct1 _1586_x;
    int64_t _1585_t7;
    int64_t _1585_t9;
    double _1585_t10;
    struct struct0 _1585_t8;
    uint32_t _1585_t11;
    struct struct1 _1586_y;
    function2 _1585_t13;
    uint8_t _1585_t14;
    int64_t _1585_t12;
    int64_t _1585_$retval;
    _1585_t1 = 1;
    _1585_t3 = 2;
    _1585_t4 = 3.4e+00;
    _1585_t2 = (struct struct0) {_1585_t3, _1585_t4};
    _1585_t5 = 114;
    _1586_x = (struct struct1) {_1585_t1, _1585_t2, _1585_t5};
    _1585_t7 = 1;
    _1585_t9 = 2;
    _1585_t10 = 3.4e+00;
    _1585_t8 = (struct struct0) {_1585_t9, _1585_t10};
    _1585_t11 = 114;
    _1586_y = (struct struct1) {_1585_t7, _1585_t8, _1585_t11};
    _1585_t13 = _1590_f;
    $lines[$line_idx++] = "tests/integration/tuples/tuple-equality.orng:5:10:\n    if f(x, y) {\n        ^";
    _1585_t14 = _1585_t13(_1586_x, _1586_y);
    $line_idx--;
    if (_1585_t14) {
        goto BB1832;
    } else {
        goto BB1836;
    }
BB1832:
    _1585_t12 = 238;
    goto BB1835;
BB1836:
    _1585_t12 = 832;
    goto BB1835;
BB1835:
    _1585_$retval = _1585_t12;
    return _1585_$retval;
}

uint8_t _1590_f(struct struct1 _1590_x, struct struct1 _1590_y){
    uint8_t _1590_t2;
    uint8_t _1590_t4;
    uint8_t _1590_t5;
    uint8_t _1590_t6;
    uint8_t _1590_t0;
    uint8_t _1590_$retval;
    _1590_t2 = _1590_x._0==_1590_y._0;
    if (_1590_t2) {
        goto BB1824;
    } else {
        goto BB1830;
    }
BB1824:
    _1590_t4 = _1590_x._1._0==_1590_y._1._0;
    if (_1590_t4) {
        goto BB1825;
    } else {
        goto BB1830;
    }
BB1830:
    _1590_t0 = 0;
    goto BB1829;
BB1825:
    _1590_t5 = _1590_x._1._1==_1590_y._1._1;
    if (_1590_t5) {
        goto BB1826;
    } else {
        goto BB1830;
    }
BB1829:
    _1590_$retval = _1590_t0;
    return _1590_$retval;
BB1826:
    _1590_t6 = _1590_x._2==_1590_y._2;
    if (_1590_t6) {
        goto BB1827;
    } else {
        goto BB1830;
    }
BB1827:
    _1590_t0 = 1;
    goto BB1829;
}

int main(void) {
  printf("%ld",_1585_main());
  return 0;
}
