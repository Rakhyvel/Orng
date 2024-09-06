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
int64_t _1846_main(void);
uint8_t _1851_f(struct struct1 _1851_x, struct struct1 _1851_y);


/* Function definitions */
int64_t _1846_main(void){
    int64_t _1846_t1;
    int64_t _1846_t3;
    double _1846_t4;
    struct struct0 _1846_t2;
    uint32_t _1846_t5;
    struct struct1 _1847_x;
    int64_t _1846_t8;
    int64_t _1846_t10;
    double _1846_t11;
    struct struct0 _1846_t9;
    uint32_t _1846_t12;
    struct struct1 _1847_y;
    function2 _1846_t15;
    uint8_t _1846_t16;
    int64_t _1846_t14;
    int64_t _1846_$retval;
    _1846_t1 = 1;
    _1846_t3 = 2;
    _1846_t4 = 3.4e0;
    _1846_t2 = (struct struct0) {_1846_t3, _1846_t4};
    _1846_t5 = 114;
    _1847_x = (struct struct1) {_1846_t1, _1846_t2, _1846_t5};
    _1846_t8 = 1;
    _1846_t10 = 2;
    _1846_t11 = 3.4e0;
    _1846_t9 = (struct struct0) {_1846_t10, _1846_t11};
    _1846_t12 = 114;
    _1847_y = (struct struct1) {_1846_t8, _1846_t9, _1846_t12};
    _1846_t15 = (function2) _1851_f;
    $lines[$line_idx++] = "tests/integration/tuples/tuple-equality.orng:5:10:\n    if f(x, y) {\n        ^";
    _1846_t16 = _1846_t15(_1847_x, _1847_y);
    $line_idx--;
    if (_1846_t16) {
        goto BB2037;
    } else {
        goto BB2041;
    }
BB2037:
    _1846_t14 = 238;
    goto BB2040;
BB2041:
    _1846_t14 = 832;
    goto BB2040;
BB2040:
    _1846_$retval = _1846_t14;
    return _1846_$retval;
}

uint8_t _1851_f(struct struct1 _1851_x, struct struct1 _1851_y){
    uint8_t _1851_t2;
    uint8_t _1851_t4;
    uint8_t _1851_t5;
    uint8_t _1851_t6;
    uint8_t _1851_t0;
    uint8_t _1851_$retval;
    _1851_t2 = _1851_x._0==_1851_y._0;
    if (_1851_t2) {
        goto BB2029;
    } else {
        goto BB2035;
    }
BB2029:
    _1851_t4 = _1851_x._1._0==_1851_y._1._0;
    if (_1851_t4) {
        goto BB2030;
    } else {
        goto BB2035;
    }
BB2035:
    _1851_t0 = 0;
    goto BB2034;
BB2030:
    _1851_t5 = _1851_x._1._1==_1851_y._1._1;
    if (_1851_t5) {
        goto BB2031;
    } else {
        goto BB2035;
    }
BB2034:
    _1851_$retval = _1851_t0;
    return _1851_$retval;
BB2031:
    _1851_t6 = _1851_x._2==_1851_y._2;
    if (_1851_t6) {
        goto BB2032;
    } else {
        goto BB2035;
    }
BB2032:
    _1851_t0 = 1;
    goto BB2034;
}


int main(void) {
  printf("%ld",_1846_main());
  return 0;
}
