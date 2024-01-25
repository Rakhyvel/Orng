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
int64_t _1656_main(void);
uint8_t _1661_f(struct struct1 _1661_x, struct struct1 _1661_y);


/* Function definitions */
int64_t _1656_main(void){
    int64_t _1656_t1;
    int64_t _1656_t3;
    double _1656_t4;
    struct struct0 _1656_t2;
    uint32_t _1656_t5;
    struct struct1 _1657_x;
    int64_t _1656_t7;
    int64_t _1656_t9;
    double _1656_t10;
    struct struct0 _1656_t8;
    uint32_t _1656_t11;
    struct struct1 _1657_y;
    function2 _1656_t13;
    uint8_t _1656_t14;
    int64_t _1656_t12;
    int64_t _1656_$retval;
    _1656_t1 = 1;
    _1656_t3 = 2;
    _1656_t4 = 3.4e+00;
    _1656_t2 = (struct struct0) {_1656_t3, _1656_t4};
    _1656_t5 = 114;
    _1657_x = (struct struct1) {_1656_t1, _1656_t2, _1656_t5};
    _1656_t7 = 1;
    _1656_t9 = 2;
    _1656_t10 = 3.4e+00;
    _1656_t8 = (struct struct0) {_1656_t9, _1656_t10};
    _1656_t11 = 114;
    _1657_y = (struct struct1) {_1656_t7, _1656_t8, _1656_t11};
    _1656_t13 = _1661_f;
    $lines[$line_idx++] = "tests/integration/tuples/tuple-equality.orng:5:10:\n    if f(x, y) {\n        ^";
    _1656_t14 = _1656_t13(_1657_x, _1657_y);
    $line_idx--;
    if (_1656_t14) {
        goto BB1894;
    } else {
        goto BB1898;
    }
BB1894:
    _1656_t12 = 238;
    goto BB1897;
BB1898:
    _1656_t12 = 832;
    goto BB1897;
BB1897:
    _1656_$retval = _1656_t12;
    return _1656_$retval;
}

uint8_t _1661_f(struct struct1 _1661_x, struct struct1 _1661_y){
    uint8_t _1661_t2;
    uint8_t _1661_t4;
    uint8_t _1661_t5;
    uint8_t _1661_t6;
    uint8_t _1661_t0;
    uint8_t _1661_$retval;
    _1661_t2 = _1661_x._0==_1661_y._0;
    if (_1661_t2) {
        goto BB1886;
    } else {
        goto BB1892;
    }
BB1886:
    _1661_t4 = _1661_x._1._0==_1661_y._1._0;
    if (_1661_t4) {
        goto BB1887;
    } else {
        goto BB1892;
    }
BB1892:
    _1661_t0 = 0;
    goto BB1891;
BB1887:
    _1661_t5 = _1661_x._1._1==_1661_y._1._1;
    if (_1661_t5) {
        goto BB1888;
    } else {
        goto BB1892;
    }
BB1891:
    _1661_$retval = _1661_t0;
    return _1661_$retval;
BB1888:
    _1661_t6 = _1661_x._2==_1661_y._2;
    if (_1661_t6) {
        goto BB1889;
    } else {
        goto BB1892;
    }
BB1889:
    _1661_t0 = 1;
    goto BB1891;
}


int main(void) {
  printf("%ld",_1656_main());
  return 0;
}
