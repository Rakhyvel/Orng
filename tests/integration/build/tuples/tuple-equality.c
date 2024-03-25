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
int64_t _1791_main(void);
uint8_t _1796_f(struct struct1 _1796_x, struct struct1 _1796_y);


/* Function definitions */
int64_t _1791_main(void){
    int64_t _1791_t1;
    int64_t _1791_t3;
    double _1791_t4;
    struct struct0 _1791_t2;
    uint32_t _1791_t5;
    struct struct1 _1792_x;
    int64_t _1791_t8;
    int64_t _1791_t10;
    double _1791_t11;
    struct struct0 _1791_t9;
    uint32_t _1791_t12;
    struct struct1 _1792_y;
    function2 _1791_t15;
    uint8_t _1791_t16;
    int64_t _1791_t14;
    int64_t _1791_$retval;
    _1791_t1 = 1;
    _1791_t3 = 2;
    _1791_t4 = 3.4e0;
    _1791_t2 = (struct struct0) {_1791_t3, _1791_t4};
    _1791_t5 = 114;
    _1792_x = (struct struct1) {_1791_t1, _1791_t2, _1791_t5};
    _1791_t8 = 1;
    _1791_t10 = 2;
    _1791_t11 = 3.4e0;
    _1791_t9 = (struct struct0) {_1791_t10, _1791_t11};
    _1791_t12 = 114;
    _1792_y = (struct struct1) {_1791_t8, _1791_t9, _1791_t12};
    _1791_t15 = (function2) _1796_f;
    $lines[$line_idx++] = "tests/integration/tuples/tuple-equality.orng:5:10:\n    if f(x, y) {\n        ^";
    _1791_t16 = _1791_t15(_1792_x, _1792_y);
    $line_idx--;
    if (_1791_t16) {
        goto BB1974;
    } else {
        goto BB1978;
    }
BB1974:
    _1791_t14 = 238;
    goto BB1977;
BB1978:
    _1791_t14 = 832;
    goto BB1977;
BB1977:
    _1791_$retval = _1791_t14;
    return _1791_$retval;
}

uint8_t _1796_f(struct struct1 _1796_x, struct struct1 _1796_y){
    uint8_t _1796_t2;
    uint8_t _1796_t4;
    uint8_t _1796_t5;
    uint8_t _1796_t6;
    uint8_t _1796_t0;
    uint8_t _1796_$retval;
    _1796_t2 = _1796_x._0==_1796_y._0;
    if (_1796_t2) {
        goto BB1966;
    } else {
        goto BB1972;
    }
BB1966:
    _1796_t4 = _1796_x._1._0==_1796_y._1._0;
    if (_1796_t4) {
        goto BB1967;
    } else {
        goto BB1972;
    }
BB1972:
    _1796_t0 = 0;
    goto BB1971;
BB1967:
    _1796_t5 = _1796_x._1._1==_1796_y._1._1;
    if (_1796_t5) {
        goto BB1968;
    } else {
        goto BB1972;
    }
BB1971:
    _1796_$retval = _1796_t0;
    return _1796_$retval;
BB1968:
    _1796_t6 = _1796_x._2==_1796_y._2;
    if (_1796_t6) {
        goto BB1969;
    } else {
        goto BB1972;
    }
BB1969:
    _1796_t0 = 1;
    goto BB1971;
}


int main(void) {
  printf("%ld",_1791_main());
  return 0;
}
