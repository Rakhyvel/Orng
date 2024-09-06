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
int64_t _1886_main(void);
uint8_t _1891_f(struct struct1 _1891_x, struct struct1 _1891_y);


/* Function definitions */
int64_t _1886_main(void){
    int64_t _1886_t1;
    int64_t _1886_t3;
    double _1886_t4;
    struct struct0 _1886_t2;
    uint32_t _1886_t5;
    struct struct1 _1887_x;
    int64_t _1886_t8;
    int64_t _1886_t10;
    double _1886_t11;
    struct struct0 _1886_t9;
    uint32_t _1886_t12;
    struct struct1 _1887_y;
    function2 _1886_t15;
    uint8_t _1886_t16;
    int64_t _1886_t14;
    int64_t _1886_$retval;
    _1886_t1 = 1;
    _1886_t3 = 2;
    _1886_t4 = 3.4e0;
    _1886_t2 = (struct struct0) {_1886_t3, _1886_t4};
    _1886_t5 = 114;
    _1887_x = (struct struct1) {_1886_t1, _1886_t2, _1886_t5};
    _1886_t8 = 1;
    _1886_t10 = 2;
    _1886_t11 = 3.4e0;
    _1886_t9 = (struct struct0) {_1886_t10, _1886_t11};
    _1886_t12 = 114;
    _1887_y = (struct struct1) {_1886_t8, _1886_t9, _1886_t12};
    _1886_t15 = (function2) _1891_f;
    $lines[$line_idx++] = "tests/integration/tuples/tuple-equality.orng:5:10:\n    if f(x, y) {\n        ^";
    _1886_t16 = _1886_t15(_1887_x, _1887_y);
    $line_idx--;
    if (_1886_t16) {
        goto BB2051;
    } else {
        goto BB2055;
    }
BB2051:
    _1886_t14 = 238;
    goto BB2054;
BB2055:
    _1886_t14 = 832;
    goto BB2054;
BB2054:
    _1886_$retval = _1886_t14;
    return _1886_$retval;
}

uint8_t _1891_f(struct struct1 _1891_x, struct struct1 _1891_y){
    uint8_t _1891_t2;
    uint8_t _1891_t4;
    uint8_t _1891_t5;
    uint8_t _1891_t6;
    uint8_t _1891_t0;
    uint8_t _1891_$retval;
    _1891_t2 = _1891_x._0==_1891_y._0;
    if (_1891_t2) {
        goto BB2043;
    } else {
        goto BB2049;
    }
BB2043:
    _1891_t4 = _1891_x._1._0==_1891_y._1._0;
    if (_1891_t4) {
        goto BB2044;
    } else {
        goto BB2049;
    }
BB2049:
    _1891_t0 = 0;
    goto BB2048;
BB2044:
    _1891_t5 = _1891_x._1._1==_1891_y._1._1;
    if (_1891_t5) {
        goto BB2045;
    } else {
        goto BB2049;
    }
BB2048:
    _1891_$retval = _1891_t0;
    return _1891_$retval;
BB2045:
    _1891_t6 = _1891_x._2==_1891_y._2;
    if (_1891_t6) {
        goto BB2046;
    } else {
        goto BB2049;
    }
BB2046:
    _1891_t0 = 1;
    goto BB2048;
}


int main(void) {
  printf("%ld",_1886_main());
  return 0;
}
