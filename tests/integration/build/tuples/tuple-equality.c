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
int64_t _1893_main(void);
uint8_t _1898_f(struct struct1 _1898_x, struct struct1 _1898_y);


/* Function definitions */
int64_t _1893_main(void){
    int64_t _1893_t1;
    int64_t _1893_t3;
    double _1893_t4;
    struct struct0 _1893_t2;
    uint32_t _1893_t5;
    struct struct1 _1894_x;
    int64_t _1893_t8;
    int64_t _1893_t10;
    double _1893_t11;
    struct struct0 _1893_t9;
    uint32_t _1893_t12;
    struct struct1 _1894_y;
    function2 _1893_t15;
    uint8_t _1893_t16;
    int64_t _1893_t14;
    int64_t _1893_$retval;
    _1893_t1 = 1;
    _1893_t3 = 2;
    _1893_t4 = 3.4e0;
    _1893_t2 = (struct struct0) {_1893_t3, _1893_t4};
    _1893_t5 = 114;
    _1894_x = (struct struct1) {_1893_t1, _1893_t2, _1893_t5};
    _1893_t8 = 1;
    _1893_t10 = 2;
    _1893_t11 = 3.4e0;
    _1893_t9 = (struct struct0) {_1893_t10, _1893_t11};
    _1893_t12 = 114;
    _1894_y = (struct struct1) {_1893_t8, _1893_t9, _1893_t12};
    _1893_t15 = (function2) _1898_f;
    $lines[$line_idx++] = "tests/integration/tuples/tuple-equality.orng:5:10:\n    if f(x, y) {\n        ^";
    _1893_t16 = _1893_t15(_1894_x, _1894_y);
    $line_idx--;
    if (_1893_t16) {
        goto BB2053;
    } else {
        goto BB2057;
    }
BB2053:
    _1893_t14 = 238;
    goto BB2056;
BB2057:
    _1893_t14 = 832;
    goto BB2056;
BB2056:
    _1893_$retval = _1893_t14;
    return _1893_$retval;
}

uint8_t _1898_f(struct struct1 _1898_x, struct struct1 _1898_y){
    uint8_t _1898_t2;
    uint8_t _1898_t4;
    uint8_t _1898_t5;
    uint8_t _1898_t6;
    uint8_t _1898_t0;
    uint8_t _1898_$retval;
    _1898_t2 = _1898_x._0==_1898_y._0;
    if (_1898_t2) {
        goto BB2045;
    } else {
        goto BB2051;
    }
BB2045:
    _1898_t4 = _1898_x._1._0==_1898_y._1._0;
    if (_1898_t4) {
        goto BB2046;
    } else {
        goto BB2051;
    }
BB2051:
    _1898_t0 = 0;
    goto BB2050;
BB2046:
    _1898_t5 = _1898_x._1._1==_1898_y._1._1;
    if (_1898_t5) {
        goto BB2047;
    } else {
        goto BB2051;
    }
BB2050:
    _1898_$retval = _1898_t0;
    return _1898_$retval;
BB2047:
    _1898_t6 = _1898_x._2==_1898_y._2;
    if (_1898_t6) {
        goto BB2048;
    } else {
        goto BB2051;
    }
BB2048:
    _1898_t0 = 1;
    goto BB2050;
}


int main(void) {
  printf("%ld",_1893_main());
  return 0;
}
