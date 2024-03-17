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
int64_t _1758_main(void);
uint8_t _1763_f(struct struct1 _1763_x, struct struct1 _1763_y);


/* Function definitions */
int64_t _1758_main(void){
    int64_t _1758_t1;
    int64_t _1758_t3;
    double _1758_t4;
    struct struct0 _1758_t2;
    uint32_t _1758_t5;
    struct struct1 _1759_x;
    int64_t _1758_t8;
    int64_t _1758_t10;
    double _1758_t11;
    struct struct0 _1758_t9;
    uint32_t _1758_t12;
    struct struct1 _1759_y;
    function2 _1758_t15;
    uint8_t _1758_t16;
    int64_t _1758_t14;
    int64_t _1758_$retval;
    _1758_t1 = 1;
    _1758_t3 = 2;
    _1758_t4 = 3.4e0;
    _1758_t2 = (struct struct0) {_1758_t3, _1758_t4};
    _1758_t5 = 114;
    _1759_x = (struct struct1) {_1758_t1, _1758_t2, _1758_t5};
    _1758_t8 = 1;
    _1758_t10 = 2;
    _1758_t11 = 3.4e0;
    _1758_t9 = (struct struct0) {_1758_t10, _1758_t11};
    _1758_t12 = 114;
    _1759_y = (struct struct1) {_1758_t8, _1758_t9, _1758_t12};
    _1758_t15 = (function2) _1763_f;
    $lines[$line_idx++] = "tests/integration/tuples/tuple-equality.orng:5:10:\n    if f(x, y) {\n        ^";
    _1758_t16 = _1758_t15(_1759_x, _1759_y);
    $line_idx--;
    if (_1758_t16) {
        goto BB1951;
    } else {
        goto BB1955;
    }
BB1951:
    _1758_t14 = 238;
    goto BB1954;
BB1955:
    _1758_t14 = 832;
    goto BB1954;
BB1954:
    _1758_$retval = _1758_t14;
    return _1758_$retval;
}

uint8_t _1763_f(struct struct1 _1763_x, struct struct1 _1763_y){
    uint8_t _1763_t2;
    uint8_t _1763_t4;
    uint8_t _1763_t5;
    uint8_t _1763_t6;
    uint8_t _1763_t0;
    uint8_t _1763_$retval;
    _1763_t2 = _1763_x._0==_1763_y._0;
    if (_1763_t2) {
        goto BB1943;
    } else {
        goto BB1949;
    }
BB1943:
    _1763_t4 = _1763_x._1._0==_1763_y._1._0;
    if (_1763_t4) {
        goto BB1944;
    } else {
        goto BB1949;
    }
BB1949:
    _1763_t0 = 0;
    goto BB1948;
BB1944:
    _1763_t5 = _1763_x._1._1==_1763_y._1._1;
    if (_1763_t5) {
        goto BB1945;
    } else {
        goto BB1949;
    }
BB1948:
    _1763_$retval = _1763_t0;
    return _1763_$retval;
BB1945:
    _1763_t6 = _1763_x._2==_1763_y._2;
    if (_1763_t6) {
        goto BB1946;
    } else {
        goto BB1949;
    }
BB1946:
    _1763_t0 = 1;
    goto BB1948;
}


int main(void) {
  printf("%ld",_1758_main());
  return 0;
}
