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
int64_t _1700_main(void);
uint8_t _1705_f(struct struct1 _1705_x, struct struct1 _1705_y);


/* Function definitions */
int64_t _1700_main(void){
    int64_t _1700_t1;
    int64_t _1700_t3;
    double _1700_t4;
    struct struct0 _1700_t2;
    uint32_t _1700_t5;
    struct struct1 _1701_x;
    int64_t _1700_t7;
    int64_t _1700_t9;
    double _1700_t10;
    struct struct0 _1700_t8;
    uint32_t _1700_t11;
    struct struct1 _1701_y;
    function2 _1700_t13;
    uint8_t _1700_t14;
    int64_t _1700_t12;
    int64_t _1700_$retval;
    _1700_t1 = 1;
    _1700_t3 = 2;
    _1700_t4 = 3.4e+00;
    _1700_t2 = (struct struct0) {_1700_t3, _1700_t4};
    _1700_t5 = 114;
    _1701_x = (struct struct1) {_1700_t1, _1700_t2, _1700_t5};
    _1700_t7 = 1;
    _1700_t9 = 2;
    _1700_t10 = 3.4e+00;
    _1700_t8 = (struct struct0) {_1700_t9, _1700_t10};
    _1700_t11 = 114;
    _1701_y = (struct struct1) {_1700_t7, _1700_t8, _1700_t11};
    _1700_t13 = _1705_f;
    $lines[$line_idx++] = "tests/integration/tuples/tuple-equality.orng:5:10:\n    if f(x, y) {\n        ^";
    _1700_t14 = _1700_t13(_1701_x, _1701_y);
    $line_idx--;
    if (_1700_t14) {
        goto BB1934;
    } else {
        goto BB1938;
    }
BB1934:
    _1700_t12 = 238;
    goto BB1937;
BB1938:
    _1700_t12 = 832;
    goto BB1937;
BB1937:
    _1700_$retval = _1700_t12;
    return _1700_$retval;
}

uint8_t _1705_f(struct struct1 _1705_x, struct struct1 _1705_y){
    uint8_t _1705_t2;
    uint8_t _1705_t4;
    uint8_t _1705_t5;
    uint8_t _1705_t6;
    uint8_t _1705_t0;
    uint8_t _1705_$retval;
    _1705_t2 = _1705_x._0==_1705_y._0;
    if (_1705_t2) {
        goto BB1926;
    } else {
        goto BB1932;
    }
BB1926:
    _1705_t4 = _1705_x._1._0==_1705_y._1._0;
    if (_1705_t4) {
        goto BB1927;
    } else {
        goto BB1932;
    }
BB1932:
    _1705_t0 = 0;
    goto BB1931;
BB1927:
    _1705_t5 = _1705_x._1._1==_1705_y._1._1;
    if (_1705_t5) {
        goto BB1928;
    } else {
        goto BB1932;
    }
BB1931:
    _1705_$retval = _1705_t0;
    return _1705_$retval;
BB1928:
    _1705_t6 = _1705_x._2==_1705_y._2;
    if (_1705_t6) {
        goto BB1929;
    } else {
        goto BB1932;
    }
BB1929:
    _1705_t0 = 1;
    goto BB1931;
}


int main(void) {
  printf("%ld",_1700_main());
  return 0;
}
