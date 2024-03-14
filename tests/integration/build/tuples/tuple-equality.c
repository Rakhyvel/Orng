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
int64_t _1780_main(void);
uint8_t _1785_f(struct struct1 _1785_x, struct struct1 _1785_y);


/* Function definitions */
int64_t _1780_main(void){
    int64_t _1780_t1;
    int64_t _1780_t3;
    double _1780_t4;
    struct struct0 _1780_t2;
    uint32_t _1780_t5;
    struct struct1 _1781_x;
    int64_t _1780_t8;
    int64_t _1780_t10;
    double _1780_t11;
    struct struct0 _1780_t9;
    uint32_t _1780_t12;
    struct struct1 _1781_y;
    function2 _1780_t15;
    uint8_t _1780_t16;
    int64_t _1780_t14;
    int64_t _1780_$retval;
    _1780_t1 = 1;
    _1780_t3 = 2;
    _1780_t4 = 3.4e+00;
    _1780_t2 = (struct struct0) {_1780_t3, _1780_t4};
    _1780_t5 = 114;
    _1781_x = (struct struct1) {_1780_t1, _1780_t2, _1780_t5};
    _1780_t8 = 1;
    _1780_t10 = 2;
    _1780_t11 = 3.4e+00;
    _1780_t9 = (struct struct0) {_1780_t10, _1780_t11};
    _1780_t12 = 114;
    _1781_y = (struct struct1) {_1780_t8, _1780_t9, _1780_t12};
    _1780_t15 = (function2) _1785_f;
    $lines[$line_idx++] = "tests/integration/tuples/tuple-equality.orng:5:10:\n    if f(x, y) {\n        ^";
    _1780_t16 = _1780_t15(_1781_x, _1781_y);
    $line_idx--;
    if (_1780_t16) {
        goto BB1998;
    } else {
        goto BB2002;
    }
BB1998:
    _1780_t14 = 238;
    goto BB2001;
BB2002:
    _1780_t14 = 832;
    goto BB2001;
BB2001:
    _1780_$retval = _1780_t14;
    return _1780_$retval;
}

uint8_t _1785_f(struct struct1 _1785_x, struct struct1 _1785_y){
    uint8_t _1785_t2;
    uint8_t _1785_t4;
    uint8_t _1785_t5;
    uint8_t _1785_t6;
    uint8_t _1785_t0;
    uint8_t _1785_$retval;
    _1785_t2 = _1785_x._0==_1785_y._0;
    if (_1785_t2) {
        goto BB1990;
    } else {
        goto BB1996;
    }
BB1990:
    _1785_t4 = _1785_x._1._0==_1785_y._1._0;
    if (_1785_t4) {
        goto BB1991;
    } else {
        goto BB1996;
    }
BB1996:
    _1785_t0 = 0;
    goto BB1995;
BB1991:
    _1785_t5 = _1785_x._1._1==_1785_y._1._1;
    if (_1785_t5) {
        goto BB1992;
    } else {
        goto BB1996;
    }
BB1995:
    _1785_$retval = _1785_t0;
    return _1785_$retval;
BB1992:
    _1785_t6 = _1785_x._2==_1785_y._2;
    if (_1785_t6) {
        goto BB1993;
    } else {
        goto BB1996;
    }
BB1993:
    _1785_t0 = 1;
    goto BB1995;
}


int main(void) {
  printf("%ld",_1780_main());
  return 0;
}
