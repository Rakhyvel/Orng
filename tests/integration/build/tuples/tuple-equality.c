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
int64_t _1782_main(void);
uint8_t _1787_f(struct struct1 _1787_x, struct struct1 _1787_y);


/* Function definitions */
int64_t _1782_main(void){
    int64_t _1782_t1;
    int64_t _1782_t3;
    double _1782_t4;
    struct struct0 _1782_t2;
    uint32_t _1782_t5;
    struct struct1 _1783_x;
    int64_t _1782_t8;
    int64_t _1782_t10;
    double _1782_t11;
    struct struct0 _1782_t9;
    uint32_t _1782_t12;
    struct struct1 _1783_y;
    function2 _1782_t15;
    uint8_t _1782_t16;
    int64_t _1782_t14;
    int64_t _1782_$retval;
    _1782_t1 = 1;
    _1782_t3 = 2;
    _1782_t4 = 3.4e0;
    _1782_t2 = (struct struct0) {_1782_t3, _1782_t4};
    _1782_t5 = 114;
    _1783_x = (struct struct1) {_1782_t1, _1782_t2, _1782_t5};
    _1782_t8 = 1;
    _1782_t10 = 2;
    _1782_t11 = 3.4e0;
    _1782_t9 = (struct struct0) {_1782_t10, _1782_t11};
    _1782_t12 = 114;
    _1783_y = (struct struct1) {_1782_t8, _1782_t9, _1782_t12};
    _1782_t15 = (function2) _1787_f;
    $lines[$line_idx++] = "tests/integration/tuples/tuple-equality.orng:5:10:\n    if f(x, y) {\n        ^";
    _1782_t16 = _1782_t15(_1783_x, _1783_y);
    $line_idx--;
    if (_1782_t16) {
        goto BB1968;
    } else {
        goto BB1972;
    }
BB1968:
    _1782_t14 = 238;
    goto BB1971;
BB1972:
    _1782_t14 = 832;
    goto BB1971;
BB1971:
    _1782_$retval = _1782_t14;
    return _1782_$retval;
}

uint8_t _1787_f(struct struct1 _1787_x, struct struct1 _1787_y){
    uint8_t _1787_t2;
    uint8_t _1787_t4;
    uint8_t _1787_t5;
    uint8_t _1787_t6;
    uint8_t _1787_t0;
    uint8_t _1787_$retval;
    _1787_t2 = _1787_x._0==_1787_y._0;
    if (_1787_t2) {
        goto BB1960;
    } else {
        goto BB1966;
    }
BB1960:
    _1787_t4 = _1787_x._1._0==_1787_y._1._0;
    if (_1787_t4) {
        goto BB1961;
    } else {
        goto BB1966;
    }
BB1966:
    _1787_t0 = 0;
    goto BB1965;
BB1961:
    _1787_t5 = _1787_x._1._1==_1787_y._1._1;
    if (_1787_t5) {
        goto BB1962;
    } else {
        goto BB1966;
    }
BB1965:
    _1787_$retval = _1787_t0;
    return _1787_$retval;
BB1962:
    _1787_t6 = _1787_x._2==_1787_y._2;
    if (_1787_t6) {
        goto BB1963;
    } else {
        goto BB1966;
    }
BB1963:
    _1787_t0 = 1;
    goto BB1965;
}


int main(void) {
  printf("%ld",_1782_main());
  return 0;
}
