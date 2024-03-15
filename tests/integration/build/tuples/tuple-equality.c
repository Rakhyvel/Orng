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
int64_t _1746_main(void);
uint8_t _1751_f(struct struct1 _1751_x, struct struct1 _1751_y);


/* Function definitions */
int64_t _1746_main(void){
    int64_t _1746_t1;
    int64_t _1746_t3;
    double _1746_t4;
    struct struct0 _1746_t2;
    uint32_t _1746_t5;
    struct struct1 _1747_x;
    int64_t _1746_t8;
    int64_t _1746_t10;
    double _1746_t11;
    struct struct0 _1746_t9;
    uint32_t _1746_t12;
    struct struct1 _1747_y;
    function2 _1746_t15;
    uint8_t _1746_t16;
    int64_t _1746_t14;
    int64_t _1746_$retval;
    _1746_t1 = 1;
    _1746_t3 = 2;
    _1746_t4 = 3.4e0;
    _1746_t2 = (struct struct0) {_1746_t3, _1746_t4};
    _1746_t5 = 114;
    _1747_x = (struct struct1) {_1746_t1, _1746_t2, _1746_t5};
    _1746_t8 = 1;
    _1746_t10 = 2;
    _1746_t11 = 3.4e0;
    _1746_t9 = (struct struct0) {_1746_t10, _1746_t11};
    _1746_t12 = 114;
    _1747_y = (struct struct1) {_1746_t8, _1746_t9, _1746_t12};
    _1746_t15 = (function2) _1751_f;
    $lines[$line_idx++] = "tests/integration/tuples/tuple-equality.orng:5:10:\n    if f(x, y) {\n        ^";
    _1746_t16 = _1746_t15(_1747_x, _1747_y);
    $line_idx--;
    if (_1746_t16) {
        goto BB1945;
    } else {
        goto BB1949;
    }
BB1945:
    _1746_t14 = 238;
    goto BB1948;
BB1949:
    _1746_t14 = 832;
    goto BB1948;
BB1948:
    _1746_$retval = _1746_t14;
    return _1746_$retval;
}

uint8_t _1751_f(struct struct1 _1751_x, struct struct1 _1751_y){
    uint8_t _1751_t2;
    uint8_t _1751_t4;
    uint8_t _1751_t5;
    uint8_t _1751_t6;
    uint8_t _1751_t0;
    uint8_t _1751_$retval;
    _1751_t2 = _1751_x._0==_1751_y._0;
    if (_1751_t2) {
        goto BB1937;
    } else {
        goto BB1943;
    }
BB1937:
    _1751_t4 = _1751_x._1._0==_1751_y._1._0;
    if (_1751_t4) {
        goto BB1938;
    } else {
        goto BB1943;
    }
BB1943:
    _1751_t0 = 0;
    goto BB1942;
BB1938:
    _1751_t5 = _1751_x._1._1==_1751_y._1._1;
    if (_1751_t5) {
        goto BB1939;
    } else {
        goto BB1943;
    }
BB1942:
    _1751_$retval = _1751_t0;
    return _1751_$retval;
BB1939:
    _1751_t6 = _1751_x._2==_1751_y._2;
    if (_1751_t6) {
        goto BB1940;
    } else {
        goto BB1943;
    }
BB1940:
    _1751_t0 = 1;
    goto BB1942;
}


int main(void) {
  printf("%ld",_1746_main());
  return 0;
}
