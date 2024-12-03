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
int64_t _1901_main(void);
uint8_t _1906_f(struct struct1 _1906_x, struct struct1 _1906_y);


/* Function definitions */
int64_t _1901_main(void){
    int64_t _1901_t1;
    int64_t _1901_t3;
    double _1901_t4;
    struct struct0 _1901_t2;
    uint32_t _1901_t5;
    struct struct1 _1902_x;
    int64_t _1901_t8;
    int64_t _1901_t10;
    double _1901_t11;
    struct struct0 _1901_t9;
    uint32_t _1901_t12;
    struct struct1 _1902_y;
    function2 _1901_t15;
    uint8_t _1901_t16;
    int64_t _1901_t14;
    int64_t _1901_$retval;
    _1901_t1 = 1;
    _1901_t3 = 2;
    _1901_t4 = 3.4e0;
    _1901_t2 = (struct struct0) {_1901_t3, _1901_t4};
    _1901_t5 = 114;
    _1902_x = (struct struct1) {_1901_t1, _1901_t2, _1901_t5};
    _1901_t8 = 1;
    _1901_t10 = 2;
    _1901_t11 = 3.4e0;
    _1901_t9 = (struct struct0) {_1901_t10, _1901_t11};
    _1901_t12 = 114;
    _1902_y = (struct struct1) {_1901_t8, _1901_t9, _1901_t12};
    _1901_t15 = (function2) _1906_f;
    $lines[$line_idx++] = "tests/integration/tuples/tuple-equality.orng:5:10:\n    if f(x, y) {\n        ^";
    _1901_t16 = _1901_t15(_1902_x, _1902_y);
    $line_idx--;
    if (_1901_t16) {
        goto BB2059;
    } else {
        goto BB2063;
    }
BB2059:
    _1901_t14 = 238;
    goto BB2062;
BB2063:
    _1901_t14 = 832;
    goto BB2062;
BB2062:
    _1901_$retval = _1901_t14;
    return _1901_$retval;
}

uint8_t _1906_f(struct struct1 _1906_x, struct struct1 _1906_y){
    uint8_t _1906_t2;
    uint8_t _1906_t4;
    uint8_t _1906_t5;
    uint8_t _1906_t6;
    uint8_t _1906_t0;
    uint8_t _1906_$retval;
    _1906_t2 = _1906_x._0==_1906_y._0;
    if (_1906_t2) {
        goto BB2051;
    } else {
        goto BB2057;
    }
BB2051:
    _1906_t4 = _1906_x._1._0==_1906_y._1._0;
    if (_1906_t4) {
        goto BB2052;
    } else {
        goto BB2057;
    }
BB2057:
    _1906_t0 = 0;
    goto BB2056;
BB2052:
    _1906_t5 = _1906_x._1._1==_1906_y._1._1;
    if (_1906_t5) {
        goto BB2053;
    } else {
        goto BB2057;
    }
BB2056:
    _1906_$retval = _1906_t0;
    return _1906_$retval;
BB2053:
    _1906_t6 = _1906_x._2==_1906_y._2;
    if (_1906_t6) {
        goto BB2054;
    } else {
        goto BB2057;
    }
BB2054:
    _1906_t0 = 1;
    goto BB2056;
}


int main(void) {
  printf("%ld",_1901_main());
  return 0;
}
