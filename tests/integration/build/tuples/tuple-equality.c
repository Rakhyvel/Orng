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
int64_t _1544_main(void);
uint8_t _1549_f(struct1 _1549_x, struct1 _1549_y);

/* Function definitions */
int64_t _1544_main(void){
    int64_t _1544_t1;
    int64_t _1544_t3;
    double _1544_t4;
    struct0 _1544_t2;
    uint32_t _1544_t5;
    struct1 _1545_x;
    int64_t _1544_t7;
    int64_t _1544_t9;
    double _1544_t10;
    struct0 _1544_t8;
    uint32_t _1544_t11;
    struct1 _1545_y;
    function2 _1544_t13;
    uint8_t _1544_t14;
    int64_t _1544_t12;
    int64_t _1544_$retval;
    _1544_t1 = 1;
    _1544_t3 = 2;
    _1544_t4 = 3.4e+00;
    _1544_t2 = (struct0) {_1544_t3, _1544_t4};
    _1544_t5 = 114;
    _1545_x = (struct1) {_1544_t1, _1544_t2, _1544_t5};
    _1544_t7 = 1;
    _1544_t9 = 2;
    _1544_t10 = 3.4e+00;
    _1544_t8 = (struct0) {_1544_t9, _1544_t10};
    _1544_t11 = 114;
    _1545_y = (struct1) {_1544_t7, _1544_t8, _1544_t11};
    _1544_t13 = _1549_f;
    $lines[$line_idx++] = "tests/integration/tuples/tuple-equality.orng:5:10:\n    if f(x, y) {\n        ^";
    _1544_t14 = _1544_t13(_1545_x, _1545_y);
    $line_idx--;
    if (_1544_t14) {
        goto BB1813;
    } else {
        goto BB1817;
    }
BB1813:
    _1544_t12 = 238;
    goto BB1816;
BB1817:
    _1544_t12 = 832;
    goto BB1816;
BB1816:
    _1544_$retval = _1544_t12;
    return _1544_$retval;
}

uint8_t _1549_f(struct1 _1549_x, struct1 _1549_y){
    uint8_t _1549_t2;
    uint8_t _1549_t4;
    uint8_t _1549_t5;
    uint8_t _1549_t6;
    uint8_t _1549_t0;
    uint8_t _1549_$retval;
    _1549_t2 = _1549_x._0==_1549_y._0;
    if (_1549_t2) {
        goto BB1805;
    } else {
        goto BB1811;
    }
BB1805:
    _1549_t4 = _1549_x._1._0==_1549_y._1._0;
    if (_1549_t4) {
        goto BB1806;
    } else {
        goto BB1811;
    }
BB1811:
    _1549_t0 = 0;
    goto BB1810;
BB1806:
    _1549_t5 = _1549_x._1._1==_1549_y._1._1;
    if (_1549_t5) {
        goto BB1807;
    } else {
        goto BB1811;
    }
BB1810:
    _1549_$retval = _1549_t0;
    return _1549_$retval;
BB1807:
    _1549_t6 = _1549_x._2==_1549_y._2;
    if (_1549_t6) {
        goto BB1808;
    } else {
        goto BB1811;
    }
BB1808:
    _1549_t0 = 1;
    goto BB1810;
}

int main(void) {
  printf("%ld",_1544_main());
  return 0;
}
