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
int64_t _1724_main(void);
uint8_t _1729_f(struct struct1 _1729_x, struct struct1 _1729_y);


/* Function definitions */
int64_t _1724_main(void){
    int64_t _1724_t1;
    int64_t _1724_t3;
    double _1724_t4;
    struct struct0 _1724_t2;
    uint32_t _1724_t5;
    struct struct1 _1725_x;
    int64_t _1724_t7;
    int64_t _1724_t9;
    double _1724_t10;
    struct struct0 _1724_t8;
    uint32_t _1724_t11;
    struct struct1 _1725_y;
    function2 _1724_t13;
    uint8_t _1724_t14;
    int64_t _1724_t12;
    int64_t _1724_$retval;
    _1724_t1 = 1;
    _1724_t3 = 2;
    _1724_t4 = 3.4e+00;
    _1724_t2 = (struct struct0) {_1724_t3, _1724_t4};
    _1724_t5 = 114;
    _1725_x = (struct struct1) {_1724_t1, _1724_t2, _1724_t5};
    _1724_t7 = 1;
    _1724_t9 = 2;
    _1724_t10 = 3.4e+00;
    _1724_t8 = (struct struct0) {_1724_t9, _1724_t10};
    _1724_t11 = 114;
    _1725_y = (struct struct1) {_1724_t7, _1724_t8, _1724_t11};
    _1724_t13 = (function2) _1729_f;
    $lines[$line_idx++] = "tests/integration/tuples/tuple-equality.orng:5:10:\n    if f(x, y) {\n        ^";
    _1724_t14 = _1724_t13(_1725_x, _1725_y);
    $line_idx--;
    if (_1724_t14) {
        goto BB1946;
    } else {
        goto BB1950;
    }
BB1946:
    _1724_t12 = 238;
    goto BB1949;
BB1950:
    _1724_t12 = 832;
    goto BB1949;
BB1949:
    _1724_$retval = _1724_t12;
    return _1724_$retval;
}

uint8_t _1729_f(struct struct1 _1729_x, struct struct1 _1729_y){
    uint8_t _1729_t2;
    uint8_t _1729_t4;
    uint8_t _1729_t5;
    uint8_t _1729_t6;
    uint8_t _1729_t0;
    uint8_t _1729_$retval;
    _1729_t2 = _1729_x._0==_1729_y._0;
    if (_1729_t2) {
        goto BB1938;
    } else {
        goto BB1944;
    }
BB1938:
    _1729_t4 = _1729_x._1._0==_1729_y._1._0;
    if (_1729_t4) {
        goto BB1939;
    } else {
        goto BB1944;
    }
BB1944:
    _1729_t0 = 0;
    goto BB1943;
BB1939:
    _1729_t5 = _1729_x._1._1==_1729_y._1._1;
    if (_1729_t5) {
        goto BB1940;
    } else {
        goto BB1944;
    }
BB1943:
    _1729_$retval = _1729_t0;
    return _1729_$retval;
BB1940:
    _1729_t6 = _1729_x._2==_1729_y._2;
    if (_1729_t6) {
        goto BB1941;
    } else {
        goto BB1944;
    }
BB1941:
    _1729_t0 = 1;
    goto BB1943;
}


int main(void) {
  printf("%ld",_1724_main());
  return 0;
}
