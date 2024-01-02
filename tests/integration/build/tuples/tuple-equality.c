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
int64_t _1552_main(void);
uint8_t _1557_f(struct struct1 _1557_x, struct struct1 _1557_y);

/* Function definitions */
int64_t _1552_main(void){
    int64_t _1552_t1;
    int64_t _1552_t3;
    double _1552_t4;
    struct struct0 _1552_t2;
    uint32_t _1552_t5;
    struct struct1 _1553_x;
    int64_t _1552_t7;
    int64_t _1552_t9;
    double _1552_t10;
    struct struct0 _1552_t8;
    uint32_t _1552_t11;
    struct struct1 _1553_y;
    function2 _1552_t13;
    uint8_t _1552_t14;
    int64_t _1552_t12;
    int64_t _1552_$retval;
    _1552_t1 = 1;
    _1552_t3 = 2;
    _1552_t4 = 3.4e+00;
    _1552_t2 = (struct struct0) {_1552_t3, _1552_t4};
    _1552_t5 = 114;
    _1553_x = (struct struct1) {_1552_t1, _1552_t2, _1552_t5};
    _1552_t7 = 1;
    _1552_t9 = 2;
    _1552_t10 = 3.4e+00;
    _1552_t8 = (struct struct0) {_1552_t9, _1552_t10};
    _1552_t11 = 114;
    _1553_y = (struct struct1) {_1552_t7, _1552_t8, _1552_t11};
    _1552_t13 = _1557_f;
    $lines[$line_idx++] = "tests/integration/tuples/tuple-equality.orng:5:10:\n    if f(x, y) {\n        ^";
    _1552_t14 = _1552_t13(_1553_x, _1553_y);
    $line_idx--;
    if (_1552_t14) {
        goto BB1809;
    } else {
        goto BB1813;
    }
BB1809:
    _1552_t12 = 238;
    goto BB1812;
BB1813:
    _1552_t12 = 832;
    goto BB1812;
BB1812:
    _1552_$retval = _1552_t12;
    return _1552_$retval;
}

uint8_t _1557_f(struct struct1 _1557_x, struct struct1 _1557_y){
    uint8_t _1557_t2;
    uint8_t _1557_t4;
    uint8_t _1557_t5;
    uint8_t _1557_t6;
    uint8_t _1557_t0;
    uint8_t _1557_$retval;
    _1557_t2 = _1557_x._0==_1557_y._0;
    if (_1557_t2) {
        goto BB1801;
    } else {
        goto BB1807;
    }
BB1801:
    _1557_t4 = _1557_x._1._0==_1557_y._1._0;
    if (_1557_t4) {
        goto BB1802;
    } else {
        goto BB1807;
    }
BB1807:
    _1557_t0 = 0;
    goto BB1806;
BB1802:
    _1557_t5 = _1557_x._1._1==_1557_y._1._1;
    if (_1557_t5) {
        goto BB1803;
    } else {
        goto BB1807;
    }
BB1806:
    _1557_$retval = _1557_t0;
    return _1557_$retval;
BB1803:
    _1557_t6 = _1557_x._2==_1557_y._2;
    if (_1557_t6) {
        goto BB1804;
    } else {
        goto BB1807;
    }
BB1804:
    _1557_t0 = 1;
    goto BB1806;
}

int main(void) {
  printf("%ld",_1552_main());
  return 0;
}
