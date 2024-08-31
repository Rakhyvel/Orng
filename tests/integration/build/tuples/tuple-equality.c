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
int64_t _1796_main(void);
uint8_t _1801_f(struct struct1 _1801_x, struct struct1 _1801_y);


/* Function definitions */
int64_t _1796_main(void){
    int64_t _1796_t1;
    int64_t _1796_t3;
    double _1796_t4;
    struct struct0 _1796_t2;
    uint32_t _1796_t5;
    struct struct1 _1797_x;
    int64_t _1796_t8;
    int64_t _1796_t10;
    double _1796_t11;
    struct struct0 _1796_t9;
    uint32_t _1796_t12;
    struct struct1 _1797_y;
    function2 _1796_t15;
    uint8_t _1796_t16;
    int64_t _1796_t14;
    int64_t _1796_$retval;
    _1796_t1 = 1;
    _1796_t3 = 2;
    _1796_t4 = 3.4e0;
    _1796_t2 = (struct struct0) {_1796_t3, _1796_t4};
    _1796_t5 = 114;
    _1797_x = (struct struct1) {_1796_t1, _1796_t2, _1796_t5};
    _1796_t8 = 1;
    _1796_t10 = 2;
    _1796_t11 = 3.4e0;
    _1796_t9 = (struct struct0) {_1796_t10, _1796_t11};
    _1796_t12 = 114;
    _1797_y = (struct struct1) {_1796_t8, _1796_t9, _1796_t12};
    _1796_t15 = (function2) _1801_f;
    $lines[$line_idx++] = "tests/integration/tuples/tuple-equality.orng:5:10:\n    if f(x, y) {\n        ^";
    _1796_t16 = _1796_t15(_1797_x, _1797_y);
    $line_idx--;
    if (_1796_t16) {
        goto BB1978;
    } else {
        goto BB1982;
    }
BB1978:
    _1796_t14 = 238;
    goto BB1981;
BB1982:
    _1796_t14 = 832;
    goto BB1981;
BB1981:
    _1796_$retval = _1796_t14;
    return _1796_$retval;
}

uint8_t _1801_f(struct struct1 _1801_x, struct struct1 _1801_y){
    uint8_t _1801_t2;
    uint8_t _1801_t4;
    uint8_t _1801_t5;
    uint8_t _1801_t6;
    uint8_t _1801_t0;
    uint8_t _1801_$retval;
    _1801_t2 = _1801_x._0==_1801_y._0;
    if (_1801_t2) {
        goto BB1970;
    } else {
        goto BB1976;
    }
BB1970:
    _1801_t4 = _1801_x._1._0==_1801_y._1._0;
    if (_1801_t4) {
        goto BB1971;
    } else {
        goto BB1976;
    }
BB1976:
    _1801_t0 = 0;
    goto BB1975;
BB1971:
    _1801_t5 = _1801_x._1._1==_1801_y._1._1;
    if (_1801_t5) {
        goto BB1972;
    } else {
        goto BB1976;
    }
BB1975:
    _1801_$retval = _1801_t0;
    return _1801_$retval;
BB1972:
    _1801_t6 = _1801_x._2==_1801_y._2;
    if (_1801_t6) {
        goto BB1973;
    } else {
        goto BB1976;
    }
BB1973:
    _1801_t0 = 1;
    goto BB1975;
}


int main(void) {
  printf("%ld",_1796_main());
  return 0;
}
