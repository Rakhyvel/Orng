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
int64_t _1854_main(void);
uint8_t _1859_f(struct struct1 _1859_x, struct struct1 _1859_y);


/* Function definitions */
int64_t _1854_main(void){
    int64_t _1854_t1;
    int64_t _1854_t3;
    double _1854_t4;
    struct struct0 _1854_t2;
    uint32_t _1854_t5;
    struct struct1 _1855_x;
    int64_t _1854_t8;
    int64_t _1854_t10;
    double _1854_t11;
    struct struct0 _1854_t9;
    uint32_t _1854_t12;
    struct struct1 _1855_y;
    function2 _1854_t15;
    uint8_t _1854_t16;
    int64_t _1854_t14;
    int64_t _1854_$retval;
    _1854_t1 = 1;
    _1854_t3 = 2;
    _1854_t4 = 3.4e0;
    _1854_t2 = (struct struct0) {_1854_t3, _1854_t4};
    _1854_t5 = 114;
    _1855_x = (struct struct1) {_1854_t1, _1854_t2, _1854_t5};
    _1854_t8 = 1;
    _1854_t10 = 2;
    _1854_t11 = 3.4e0;
    _1854_t9 = (struct struct0) {_1854_t10, _1854_t11};
    _1854_t12 = 114;
    _1855_y = (struct struct1) {_1854_t8, _1854_t9, _1854_t12};
    _1854_t15 = (function2) _1859_f;
    $lines[$line_idx++] = "tests/integration/tuples/tuple-equality.orng:5:10:\n    if f(x, y) {\n        ^";
    _1854_t16 = _1854_t15(_1855_x, _1855_y);
    $line_idx--;
    if (_1854_t16) {
        goto BB2047;
    } else {
        goto BB2051;
    }
BB2047:
    _1854_t14 = 238;
    goto BB2050;
BB2051:
    _1854_t14 = 832;
    goto BB2050;
BB2050:
    _1854_$retval = _1854_t14;
    return _1854_$retval;
}

uint8_t _1859_f(struct struct1 _1859_x, struct struct1 _1859_y){
    uint8_t _1859_t2;
    uint8_t _1859_t4;
    uint8_t _1859_t5;
    uint8_t _1859_t6;
    uint8_t _1859_t0;
    uint8_t _1859_$retval;
    _1859_t2 = _1859_x._0==_1859_y._0;
    if (_1859_t2) {
        goto BB2039;
    } else {
        goto BB2045;
    }
BB2039:
    _1859_t4 = _1859_x._1._0==_1859_y._1._0;
    if (_1859_t4) {
        goto BB2040;
    } else {
        goto BB2045;
    }
BB2045:
    _1859_t0 = 0;
    goto BB2044;
BB2040:
    _1859_t5 = _1859_x._1._1==_1859_y._1._1;
    if (_1859_t5) {
        goto BB2041;
    } else {
        goto BB2045;
    }
BB2044:
    _1859_$retval = _1859_t0;
    return _1859_$retval;
BB2041:
    _1859_t6 = _1859_x._2==_1859_y._2;
    if (_1859_t6) {
        goto BB2042;
    } else {
        goto BB2045;
    }
BB2042:
    _1859_t0 = 1;
    goto BB2044;
}


int main(void) {
  printf("%ld",_1854_main());
  return 0;
}
