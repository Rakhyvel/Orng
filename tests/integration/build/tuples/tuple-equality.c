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
int64_t _1913_main(void);
uint8_t _1918_f(struct struct1 _1918_x, struct struct1 _1918_y);


/* Function definitions */
int64_t _1913_main(void){
    int64_t _1913_t1;
    int64_t _1913_t3;
    double _1913_t4;
    struct struct0 _1913_t2;
    uint32_t _1913_t5;
    struct struct1 _1914_x;
    int64_t _1913_t8;
    int64_t _1913_t10;
    double _1913_t11;
    struct struct0 _1913_t9;
    uint32_t _1913_t12;
    struct struct1 _1914_y;
    function2 _1913_t15;
    uint8_t _1913_t16;
    int64_t _1913_t14;
    int64_t _1913_$retval;
    _1913_t1 = 1;
    _1913_t3 = 2;
    _1913_t4 = 3.4e0;
    _1913_t2 = (struct struct0) {_1913_t3, _1913_t4};
    _1913_t5 = 114;
    _1914_x = (struct struct1) {_1913_t1, _1913_t2, _1913_t5};
    _1913_t8 = 1;
    _1913_t10 = 2;
    _1913_t11 = 3.4e0;
    _1913_t9 = (struct struct0) {_1913_t10, _1913_t11};
    _1913_t12 = 114;
    _1914_y = (struct struct1) {_1913_t8, _1913_t9, _1913_t12};
    _1913_t15 = (function2) _1918_f;
    $lines[$line_idx++] = "tests/integration/tuples/tuple-equality.orng:5:10:\n    if f(x, y) {\n        ^";
    _1913_t16 = _1913_t15(_1914_x, _1914_y);
    $line_idx--;
    if (_1913_t16) {
        goto BB2071;
    } else {
        goto BB2075;
    }
BB2071:
    _1913_t14 = 238;
    goto BB2074;
BB2075:
    _1913_t14 = 832;
    goto BB2074;
BB2074:
    _1913_$retval = _1913_t14;
    return _1913_$retval;
}

uint8_t _1918_f(struct struct1 _1918_x, struct struct1 _1918_y){
    uint8_t _1918_t2;
    uint8_t _1918_t4;
    uint8_t _1918_t5;
    uint8_t _1918_t6;
    uint8_t _1918_t0;
    uint8_t _1918_$retval;
    _1918_t2 = _1918_x._0==_1918_y._0;
    if (_1918_t2) {
        goto BB2063;
    } else {
        goto BB2069;
    }
BB2063:
    _1918_t4 = _1918_x._1._0==_1918_y._1._0;
    if (_1918_t4) {
        goto BB2064;
    } else {
        goto BB2069;
    }
BB2069:
    _1918_t0 = 0;
    goto BB2068;
BB2064:
    _1918_t5 = _1918_x._1._1==_1918_y._1._1;
    if (_1918_t5) {
        goto BB2065;
    } else {
        goto BB2069;
    }
BB2068:
    _1918_$retval = _1918_t0;
    return _1918_$retval;
BB2065:
    _1918_t6 = _1918_x._2==_1918_y._2;
    if (_1918_t6) {
        goto BB2066;
    } else {
        goto BB2069;
    }
BB2066:
    _1918_t0 = 1;
    goto BB2068;
}


int main(void) {
  printf("%ld",_1913_main());
  return 0;
}
