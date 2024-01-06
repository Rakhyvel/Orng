/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward typedefs */
struct struct0;
struct struct1;
struct struct3;

/* Typedefs */
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
int64_t _1557_main(void);
uint8_t _1562_f(struct struct1 _1562_x, struct struct1 _1562_y);

/* Function definitions */
int64_t _1557_main(void){
    int64_t _1557_t1;
    int64_t _1557_t3;
    double _1557_t4;
    struct struct0 _1557_t2;
    uint32_t _1557_t5;
    struct struct1 _1558_x;
    int64_t _1557_t7;
    int64_t _1557_t9;
    double _1557_t10;
    struct struct0 _1557_t8;
    uint32_t _1557_t11;
    struct struct1 _1558_y;
    function2 _1557_t13;
    uint8_t _1557_t14;
    int64_t _1557_t12;
    int64_t _1557_$retval;
    _1557_t1 = 1;
    _1557_t3 = 2;
    _1557_t4 = 3.4e+00;
    _1557_t2 = (struct struct0) {_1557_t3, _1557_t4};
    _1557_t5 = 114;
    _1558_x = (struct struct1) {_1557_t1, _1557_t2, _1557_t5};
    _1557_t7 = 1;
    _1557_t9 = 2;
    _1557_t10 = 3.4e+00;
    _1557_t8 = (struct struct0) {_1557_t9, _1557_t10};
    _1557_t11 = 114;
    _1558_y = (struct struct1) {_1557_t7, _1557_t8, _1557_t11};
    _1557_t13 = _1562_f;
    $lines[$line_idx++] = "tests/integration/tuples/tuple-equality.orng:5:10:\n    if f(x, y) {\n        ^";
    _1557_t14 = _1557_t13(_1558_x, _1558_y);
    $line_idx--;
    if (_1557_t14) {
        goto BB1813;
    } else {
        goto BB1817;
    }
BB1813:
    _1557_t12 = 238;
    goto BB1816;
BB1817:
    _1557_t12 = 832;
    goto BB1816;
BB1816:
    _1557_$retval = _1557_t12;
    return _1557_$retval;
}

uint8_t _1562_f(struct struct1 _1562_x, struct struct1 _1562_y){
    uint8_t _1562_t2;
    uint8_t _1562_t4;
    uint8_t _1562_t5;
    uint8_t _1562_t6;
    uint8_t _1562_t0;
    uint8_t _1562_$retval;
    _1562_t2 = _1562_x._0==_1562_y._0;
    if (_1562_t2) {
        goto BB1805;
    } else {
        goto BB1811;
    }
BB1805:
    _1562_t4 = _1562_x._1._0==_1562_y._1._0;
    if (_1562_t4) {
        goto BB1806;
    } else {
        goto BB1811;
    }
BB1811:
    _1562_t0 = 0;
    goto BB1810;
BB1806:
    _1562_t5 = _1562_x._1._1==_1562_y._1._1;
    if (_1562_t5) {
        goto BB1807;
    } else {
        goto BB1811;
    }
BB1810:
    _1562_$retval = _1562_t0;
    return _1562_$retval;
BB1807:
    _1562_t6 = _1562_x._2==_1562_y._2;
    if (_1562_t6) {
        goto BB1808;
    } else {
        goto BB1811;
    }
BB1808:
    _1562_t0 = 1;
    goto BB1810;
}

int main(void) {
  printf("%ld",_1557_main());
  return 0;
}
