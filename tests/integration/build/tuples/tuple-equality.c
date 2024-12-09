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
int64_t _1926_main(void);
uint8_t _1931_f(struct struct1 _1931_x, struct struct1 _1931_y);


/* Function definitions */
int64_t _1926_main(void){
    int64_t _1926_t1;
    int64_t _1926_t3;
    double _1926_t4;
    struct struct0 _1926_t2;
    uint32_t _1926_t5;
    struct struct1 _1927_x;
    int64_t _1926_t8;
    int64_t _1926_t10;
    double _1926_t11;
    struct struct0 _1926_t9;
    uint32_t _1926_t12;
    struct struct1 _1927_y;
    function2 _1926_t15;
    uint8_t _1926_t16;
    int64_t _1926_t14;
    int64_t _1926_$retval;
    _1926_t1 = 1;
    _1926_t3 = 2;
    _1926_t4 = 3.4e0;
    _1926_t2 = (struct struct0) {_1926_t3, _1926_t4};
    _1926_t5 = 114;
    _1927_x = (struct struct1) {_1926_t1, _1926_t2, _1926_t5};
    _1926_t8 = 1;
    _1926_t10 = 2;
    _1926_t11 = 3.4e0;
    _1926_t9 = (struct struct0) {_1926_t10, _1926_t11};
    _1926_t12 = 114;
    _1927_y = (struct struct1) {_1926_t8, _1926_t9, _1926_t12};
    _1926_t15 = (function2) _1931_f;
    $lines[$line_idx++] = "tests/integration/tuples/tuple-equality.orng:5:10:\n    if f(x, y) {\n        ^";
    _1926_t16 = _1926_t15(_1927_x, _1927_y);
    $line_idx--;
    if (_1926_t16) {
        goto BB2084;
    } else {
        goto BB2088;
    }
BB2084:
    _1926_t14 = 238;
    goto BB2087;
BB2088:
    _1926_t14 = 832;
    goto BB2087;
BB2087:
    _1926_$retval = _1926_t14;
    return _1926_$retval;
}

uint8_t _1931_f(struct struct1 _1931_x, struct struct1 _1931_y){
    uint8_t _1931_t2;
    uint8_t _1931_t4;
    uint8_t _1931_t5;
    uint8_t _1931_t6;
    uint8_t _1931_t0;
    uint8_t _1931_$retval;
    _1931_t2 = _1931_x._0==_1931_y._0;
    if (_1931_t2) {
        goto BB2076;
    } else {
        goto BB2082;
    }
BB2076:
    _1931_t4 = _1931_x._1._0==_1931_y._1._0;
    if (_1931_t4) {
        goto BB2077;
    } else {
        goto BB2082;
    }
BB2082:
    _1931_t0 = 0;
    goto BB2081;
BB2077:
    _1931_t5 = _1931_x._1._1==_1931_y._1._1;
    if (_1931_t5) {
        goto BB2078;
    } else {
        goto BB2082;
    }
BB2081:
    _1931_$retval = _1931_t0;
    return _1931_$retval;
BB2078:
    _1931_t6 = _1931_x._2==_1931_y._2;
    if (_1931_t6) {
        goto BB2079;
    } else {
        goto BB2082;
    }
BB2079:
    _1931_t0 = 1;
    goto BB2081;
}


int main(void) {
  printf("%ld",_1926_main());
  return 0;
}
