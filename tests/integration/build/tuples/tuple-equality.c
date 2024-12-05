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
int64_t _1907_main(void);
uint8_t _1912_f(struct struct1 _1912_x, struct struct1 _1912_y);


/* Function definitions */
int64_t _1907_main(void){
    int64_t _1907_t1;
    int64_t _1907_t3;
    double _1907_t4;
    struct struct0 _1907_t2;
    uint32_t _1907_t5;
    struct struct1 _1908_x;
    int64_t _1907_t8;
    int64_t _1907_t10;
    double _1907_t11;
    struct struct0 _1907_t9;
    uint32_t _1907_t12;
    struct struct1 _1908_y;
    function2 _1907_t15;
    uint8_t _1907_t16;
    int64_t _1907_t14;
    int64_t _1907_$retval;
    _1907_t1 = 1;
    _1907_t3 = 2;
    _1907_t4 = 3.4e0;
    _1907_t2 = (struct struct0) {_1907_t3, _1907_t4};
    _1907_t5 = 114;
    _1908_x = (struct struct1) {_1907_t1, _1907_t2, _1907_t5};
    _1907_t8 = 1;
    _1907_t10 = 2;
    _1907_t11 = 3.4e0;
    _1907_t9 = (struct struct0) {_1907_t10, _1907_t11};
    _1907_t12 = 114;
    _1908_y = (struct struct1) {_1907_t8, _1907_t9, _1907_t12};
    _1907_t15 = (function2) _1912_f;
    $lines[$line_idx++] = "tests/integration/tuples/tuple-equality.orng:5:10:\n    if f(x, y) {\n        ^";
    _1907_t16 = _1907_t15(_1908_x, _1908_y);
    $line_idx--;
    if (_1907_t16) {
        goto BB2062;
    } else {
        goto BB2066;
    }
BB2062:
    _1907_t14 = 238;
    goto BB2065;
BB2066:
    _1907_t14 = 832;
    goto BB2065;
BB2065:
    _1907_$retval = _1907_t14;
    return _1907_$retval;
}

uint8_t _1912_f(struct struct1 _1912_x, struct struct1 _1912_y){
    uint8_t _1912_t2;
    uint8_t _1912_t4;
    uint8_t _1912_t5;
    uint8_t _1912_t6;
    uint8_t _1912_t0;
    uint8_t _1912_$retval;
    _1912_t2 = _1912_x._0==_1912_y._0;
    if (_1912_t2) {
        goto BB2054;
    } else {
        goto BB2060;
    }
BB2054:
    _1912_t4 = _1912_x._1._0==_1912_y._1._0;
    if (_1912_t4) {
        goto BB2055;
    } else {
        goto BB2060;
    }
BB2060:
    _1912_t0 = 0;
    goto BB2059;
BB2055:
    _1912_t5 = _1912_x._1._1==_1912_y._1._1;
    if (_1912_t5) {
        goto BB2056;
    } else {
        goto BB2060;
    }
BB2059:
    _1912_$retval = _1912_t0;
    return _1912_$retval;
BB2056:
    _1912_t6 = _1912_x._2==_1912_y._2;
    if (_1912_t6) {
        goto BB2057;
    } else {
        goto BB2060;
    }
BB2057:
    _1912_t0 = 1;
    goto BB2059;
}


int main(void) {
  printf("%ld",_1907_main());
  return 0;
}
