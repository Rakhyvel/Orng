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
int64_t _1921_main(void);
uint8_t _1926_f(struct struct1 _1926_x, struct struct1 _1926_y);


/* Function definitions */
int64_t _1921_main(void){
    int64_t _1921_t1;
    int64_t _1921_t3;
    double _1921_t4;
    struct struct0 _1921_t2;
    uint32_t _1921_t5;
    struct struct1 _1922_x;
    int64_t _1921_t8;
    int64_t _1921_t10;
    double _1921_t11;
    struct struct0 _1921_t9;
    uint32_t _1921_t12;
    struct struct1 _1922_y;
    function2 _1921_t15;
    uint8_t _1921_t16;
    int64_t _1921_t14;
    int64_t _1921_$retval;
    _1921_t1 = 1;
    _1921_t3 = 2;
    _1921_t4 = 3.4e0;
    _1921_t2 = (struct struct0) {_1921_t3, _1921_t4};
    _1921_t5 = 114;
    _1922_x = (struct struct1) {_1921_t1, _1921_t2, _1921_t5};
    _1921_t8 = 1;
    _1921_t10 = 2;
    _1921_t11 = 3.4e0;
    _1921_t9 = (struct struct0) {_1921_t10, _1921_t11};
    _1921_t12 = 114;
    _1922_y = (struct struct1) {_1921_t8, _1921_t9, _1921_t12};
    _1921_t15 = (function2) _1926_f;
    $lines[$line_idx++] = "tests/integration/tuples/tuple-equality.orng:5:10:\n    if f(x, y) {\n        ^";
    _1921_t16 = _1921_t15(_1922_x, _1922_y);
    $line_idx--;
    if (_1921_t16) {
        goto BB2081;
    } else {
        goto BB2085;
    }
BB2081:
    _1921_t14 = 238;
    goto BB2084;
BB2085:
    _1921_t14 = 832;
    goto BB2084;
BB2084:
    _1921_$retval = _1921_t14;
    return _1921_$retval;
}

uint8_t _1926_f(struct struct1 _1926_x, struct struct1 _1926_y){
    uint8_t _1926_t2;
    uint8_t _1926_t4;
    uint8_t _1926_t5;
    uint8_t _1926_t6;
    uint8_t _1926_t0;
    uint8_t _1926_$retval;
    _1926_t2 = _1926_x._0==_1926_y._0;
    if (_1926_t2) {
        goto BB2073;
    } else {
        goto BB2079;
    }
BB2073:
    _1926_t4 = _1926_x._1._0==_1926_y._1._0;
    if (_1926_t4) {
        goto BB2074;
    } else {
        goto BB2079;
    }
BB2079:
    _1926_t0 = 0;
    goto BB2078;
BB2074:
    _1926_t5 = _1926_x._1._1==_1926_y._1._1;
    if (_1926_t5) {
        goto BB2075;
    } else {
        goto BB2079;
    }
BB2078:
    _1926_$retval = _1926_t0;
    return _1926_$retval;
BB2075:
    _1926_t6 = _1926_x._2==_1926_y._2;
    if (_1926_t6) {
        goto BB2076;
    } else {
        goto BB2079;
    }
BB2076:
    _1926_t0 = 1;
    goto BB2078;
}


int main(void) {
  printf("%ld",_1921_main());
  return 0;
}
