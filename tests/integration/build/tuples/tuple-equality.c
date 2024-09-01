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
int64_t _1835_main(void);
uint8_t _1840_f(struct struct1 _1840_x, struct struct1 _1840_y);


/* Function definitions */
int64_t _1835_main(void){
    int64_t _1835_t1;
    int64_t _1835_t3;
    double _1835_t4;
    struct struct0 _1835_t2;
    uint32_t _1835_t5;
    struct struct1 _1836_x;
    int64_t _1835_t8;
    int64_t _1835_t10;
    double _1835_t11;
    struct struct0 _1835_t9;
    uint32_t _1835_t12;
    struct struct1 _1836_y;
    function2 _1835_t15;
    uint8_t _1835_t16;
    int64_t _1835_t14;
    int64_t _1835_$retval;
    _1835_t1 = 1;
    _1835_t3 = 2;
    _1835_t4 = 3.4e0;
    _1835_t2 = (struct struct0) {_1835_t3, _1835_t4};
    _1835_t5 = 114;
    _1836_x = (struct struct1) {_1835_t1, _1835_t2, _1835_t5};
    _1835_t8 = 1;
    _1835_t10 = 2;
    _1835_t11 = 3.4e0;
    _1835_t9 = (struct struct0) {_1835_t10, _1835_t11};
    _1835_t12 = 114;
    _1836_y = (struct struct1) {_1835_t8, _1835_t9, _1835_t12};
    _1835_t15 = (function2) _1840_f;
    $lines[$line_idx++] = "tests/integration/tuples/tuple-equality.orng:5:10:\n    if f(x, y) {\n        ^";
    _1835_t16 = _1835_t15(_1836_x, _1836_y);
    $line_idx--;
    if (_1835_t16) {
        goto BB2026;
    } else {
        goto BB2030;
    }
BB2026:
    _1835_t14 = 238;
    goto BB2029;
BB2030:
    _1835_t14 = 832;
    goto BB2029;
BB2029:
    _1835_$retval = _1835_t14;
    return _1835_$retval;
}

uint8_t _1840_f(struct struct1 _1840_x, struct struct1 _1840_y){
    uint8_t _1840_t2;
    uint8_t _1840_t4;
    uint8_t _1840_t5;
    uint8_t _1840_t6;
    uint8_t _1840_t0;
    uint8_t _1840_$retval;
    _1840_t2 = _1840_x._0==_1840_y._0;
    if (_1840_t2) {
        goto BB2018;
    } else {
        goto BB2024;
    }
BB2018:
    _1840_t4 = _1840_x._1._0==_1840_y._1._0;
    if (_1840_t4) {
        goto BB2019;
    } else {
        goto BB2024;
    }
BB2024:
    _1840_t0 = 0;
    goto BB2023;
BB2019:
    _1840_t5 = _1840_x._1._1==_1840_y._1._1;
    if (_1840_t5) {
        goto BB2020;
    } else {
        goto BB2024;
    }
BB2023:
    _1840_$retval = _1840_t0;
    return _1840_$retval;
BB2020:
    _1840_t6 = _1840_x._2==_1840_y._2;
    if (_1840_t6) {
        goto BB2021;
    } else {
        goto BB2024;
    }
BB2021:
    _1840_t0 = 1;
    goto BB2023;
}


int main(void) {
  printf("%ld",_1835_main());
  return 0;
}
