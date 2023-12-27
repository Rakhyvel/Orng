/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef struct {
        int64_t _0;
        double _1;
} struct0;

typedef struct {
        int64_t _0;
        struct0 _1;
        uint32_t _2;
} struct1;

typedef struct {
        struct1 _0;
        struct1 _1;
} struct3;

typedef uint8_t(*function2)(struct1, struct1);

/* Function forward definitions */
int64_t _1519_main(void);
uint8_t _1524_f(struct1 _1524_x,struct1 _1524_y);

/* Function definitions */
int64_t _1519_main(void){
    int64_t _1519_t1;
    int64_t _1519_t3;
    double _1519_t4;
    struct0 _1519_t2;
    uint32_t _1519_t5;
    struct1 _1520_x;
    int64_t _1519_t7;
    int64_t _1519_t9;
    double _1519_t10;
    struct0 _1519_t8;
    uint32_t _1519_t11;
    struct1 _1520_y;
    function2 _1519_t13;
    uint8_t _1519_t14;
    int64_t _1519_t12;
    int64_t _1519_$retval;
    _1519_t1 = 1;
    _1519_t3 = 2;
    _1519_t4 = 3.4e+00;
    _1519_t2 = (struct0) {_1519_t3, _1519_t4};
    _1519_t5 = 114;
    _1520_x = (struct1) {_1519_t1, _1519_t2, _1519_t5};
    _1519_t7 = 1;
    _1519_t9 = 2;
    _1519_t10 = 3.4e+00;
    _1519_t8 = (struct0) {_1519_t9, _1519_t10};
    _1519_t11 = 114;
    _1520_y = (struct1) {_1519_t7, _1519_t8, _1519_t11};
    _1519_t13 = _1524_f;
    $lines[$line_idx++] = "tests/integration/tuples/tuple-equality.orng:5:10:\n    if f(x, y) {\n        ^";
    _1519_t14 = _1519_t13(_1520_x, _1520_y);
    $line_idx--;
    if (_1519_t14) {
        goto BB1816;
    } else {
        goto BB1820;
    }
BB1816:
    _1519_t12 = 238;
    goto BB1819;
BB1820:
    _1519_t12 = 832;
    goto BB1819;
BB1819:
    _1519_$retval = _1519_t12;
    return _1519_$retval;
}

uint8_t _1524_f(struct1 _1524_x,struct1 _1524_y){
    uint8_t _1524_t2;
    uint8_t _1524_t4;
    uint8_t _1524_t5;
    uint8_t _1524_t6;
    uint8_t _1524_t0;
    uint8_t _1524_$retval;
    _1524_t2 = _1524_x._0==_1524_y._0;
    if (_1524_t2) {
        goto BB1808;
    } else {
        goto BB1814;
    }
BB1808:
    _1524_t4 = _1524_x._1._0==_1524_y._1._0;
    if (_1524_t4) {
        goto BB1809;
    } else {
        goto BB1814;
    }
BB1814:
    _1524_t0 = 0;
    goto BB1813;
BB1809:
    _1524_t5 = _1524_x._1._1==_1524_y._1._1;
    if (_1524_t5) {
        goto BB1810;
    } else {
        goto BB1814;
    }
BB1813:
    _1524_$retval = _1524_t0;
    return _1524_$retval;
BB1810:
    _1524_t6 = _1524_x._2==_1524_y._2;
    if (_1524_t6) {
        goto BB1811;
    } else {
        goto BB1814;
    }
BB1811:
    _1524_t0 = 1;
    goto BB1813;
}

int main(void) {
  printf("%ld",_1519_main());
  return 0;
}
