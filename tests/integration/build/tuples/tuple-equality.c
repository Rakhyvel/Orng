/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward struct, union, and function declarations */
struct struct0;
struct struct1;
struct struct3;

/* Struct, union, and function definitions */
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
int64_t _1629_main(void);
uint8_t _1634_f(struct struct1 _1634_x, struct struct1 _1634_y);


/* Function definitions */
int64_t _1629_main(void){
    int64_t _1629_t1;
    int64_t _1629_t3;
    double _1629_t4;
    struct struct0 _1629_t2;
    uint32_t _1629_t5;
    struct struct1 _1630_x;
    int64_t _1629_t7;
    int64_t _1629_t9;
    double _1629_t10;
    struct struct0 _1629_t8;
    uint32_t _1629_t11;
    struct struct1 _1630_y;
    function2 _1629_t13;
    uint8_t _1629_t14;
    int64_t _1629_t12;
    int64_t _1629_$retval;
    _1629_t1 = 1;
    _1629_t3 = 2;
    _1629_t4 = 3.4e+00;
    _1629_t2 = (struct struct0) {_1629_t3, _1629_t4};
    _1629_t5 = 114;
    _1630_x = (struct struct1) {_1629_t1, _1629_t2, _1629_t5};
    _1629_t7 = 1;
    _1629_t9 = 2;
    _1629_t10 = 3.4e+00;
    _1629_t8 = (struct struct0) {_1629_t9, _1629_t10};
    _1629_t11 = 114;
    _1630_y = (struct struct1) {_1629_t7, _1629_t8, _1629_t11};
    _1629_t13 = _1634_f;
    $lines[$line_idx++] = "tests/integration/tuples/tuple-equality.orng:5:10:\n    if f(x, y) {\n        ^";
    _1629_t14 = _1629_t13(_1630_x, _1630_y);
    $line_idx--;
    if (_1629_t14) {
        goto BB1872;
    } else {
        goto BB1876;
    }
BB1872:
    _1629_t12 = 238;
    goto BB1875;
BB1876:
    _1629_t12 = 832;
    goto BB1875;
BB1875:
    _1629_$retval = _1629_t12;
    return _1629_$retval;
}

uint8_t _1634_f(struct struct1 _1634_x, struct struct1 _1634_y){
    uint8_t _1634_t2;
    uint8_t _1634_t4;
    uint8_t _1634_t5;
    uint8_t _1634_t6;
    uint8_t _1634_t0;
    uint8_t _1634_$retval;
    _1634_t2 = _1634_x._0==_1634_y._0;
    if (_1634_t2) {
        goto BB1864;
    } else {
        goto BB1870;
    }
BB1864:
    _1634_t4 = _1634_x._1._0==_1634_y._1._0;
    if (_1634_t4) {
        goto BB1865;
    } else {
        goto BB1870;
    }
BB1870:
    _1634_t0 = 0;
    goto BB1869;
BB1865:
    _1634_t5 = _1634_x._1._1==_1634_y._1._1;
    if (_1634_t5) {
        goto BB1866;
    } else {
        goto BB1870;
    }
BB1869:
    _1634_$retval = _1634_t0;
    return _1634_$retval;
BB1866:
    _1634_t6 = _1634_x._2==_1634_y._2;
    if (_1634_t6) {
        goto BB1867;
    } else {
        goto BB1870;
    }
BB1867:
    _1634_t0 = 1;
    goto BB1869;
}


int main(void) {
  printf("%ld",_1629_main());
  return 0;
}
