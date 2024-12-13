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
int64_t _1943_main(void);
uint8_t _1948_f(struct struct1 _1948_x, struct struct1 _1948_y);


/* Function definitions */
int64_t _1943_main(void){
    int64_t _1943_t1;
    int64_t _1943_t3;
    double _1943_t4;
    struct struct0 _1943_t2;
    uint32_t _1943_t5;
    struct struct1 _1944_x;
    int64_t _1943_t8;
    int64_t _1943_t10;
    double _1943_t11;
    struct struct0 _1943_t9;
    uint32_t _1943_t12;
    struct struct1 _1944_y;
    function2 _1943_t15;
    uint8_t _1943_t16;
    int64_t _1943_t14;
    int64_t _1943_$retval;
    _1943_t1 = 1;
    _1943_t3 = 2;
    _1943_t4 = 3.4e0;
    _1943_t2 = (struct struct0) {_1943_t3, _1943_t4};
    _1943_t5 = 114;
    _1944_x = (struct struct1) {_1943_t1, _1943_t2, _1943_t5};
    _1943_t8 = 1;
    _1943_t10 = 2;
    _1943_t11 = 3.4e0;
    _1943_t9 = (struct struct0) {_1943_t10, _1943_t11};
    _1943_t12 = 114;
    _1944_y = (struct struct1) {_1943_t8, _1943_t9, _1943_t12};
    _1943_t15 = (function2) _1948_f;
    $lines[$line_idx++] = "tests/integration/tuples/tuple-equality.orng:5:10:\n    if f(x, y) {\n        ^";
    _1943_t16 = _1943_t15(_1944_x, _1944_y);
    $line_idx--;
    if (_1943_t16) {
        goto BB2102;
    } else {
        goto BB2106;
    }
BB2102:
    _1943_t14 = 238;
    goto BB2105;
BB2106:
    _1943_t14 = 832;
    goto BB2105;
BB2105:
    _1943_$retval = _1943_t14;
    return _1943_$retval;
}

uint8_t _1948_f(struct struct1 _1948_x, struct struct1 _1948_y){
    uint8_t _1948_t2;
    uint8_t _1948_t4;
    uint8_t _1948_t5;
    uint8_t _1948_t6;
    uint8_t _1948_t0;
    uint8_t _1948_$retval;
    _1948_t2 = _1948_x._0==_1948_y._0;
    if (_1948_t2) {
        goto BB2094;
    } else {
        goto BB2100;
    }
BB2094:
    _1948_t4 = _1948_x._1._0==_1948_y._1._0;
    if (_1948_t4) {
        goto BB2095;
    } else {
        goto BB2100;
    }
BB2100:
    _1948_t0 = 0;
    goto BB2099;
BB2095:
    _1948_t5 = _1948_x._1._1==_1948_y._1._1;
    if (_1948_t5) {
        goto BB2096;
    } else {
        goto BB2100;
    }
BB2099:
    _1948_$retval = _1948_t0;
    return _1948_$retval;
BB2096:
    _1948_t6 = _1948_x._2==_1948_y._2;
    if (_1948_t6) {
        goto BB2097;
    } else {
        goto BB2100;
    }
BB2097:
    _1948_t0 = 1;
    goto BB2099;
}


int main(void) {
  printf("%ld",_1943_main());
  return 0;
}
