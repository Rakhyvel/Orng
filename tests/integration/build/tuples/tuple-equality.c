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
int64_t _1549_main(void);
uint8_t _1554_f(struct struct1 _1554_x, struct struct1 _1554_y);

/* Function definitions */
int64_t _1549_main(void){
    int64_t _1549_t1;
    int64_t _1549_t3;
    double _1549_t4;
    struct struct0 _1549_t2;
    uint32_t _1549_t5;
    struct struct1 _1550_x;
    int64_t _1549_t7;
    int64_t _1549_t9;
    double _1549_t10;
    struct struct0 _1549_t8;
    uint32_t _1549_t11;
    struct struct1 _1550_y;
    function2 _1549_t13;
    uint8_t _1549_t14;
    int64_t _1549_t12;
    int64_t _1549_$retval;
    _1549_t1 = 1;
    _1549_t3 = 2;
    _1549_t4 = 3.4e+00;
    _1549_t2 = (struct struct0) {_1549_t3, _1549_t4};
    _1549_t5 = 114;
    _1550_x = (struct struct1) {_1549_t1, _1549_t2, _1549_t5};
    _1549_t7 = 1;
    _1549_t9 = 2;
    _1549_t10 = 3.4e+00;
    _1549_t8 = (struct struct0) {_1549_t9, _1549_t10};
    _1549_t11 = 114;
    _1550_y = (struct struct1) {_1549_t7, _1549_t8, _1549_t11};
    _1549_t13 = _1554_f;
    $lines[$line_idx++] = "tests/integration/tuples/tuple-equality.orng:5:10:\n    if f(x, y) {\n        ^";
    _1549_t14 = _1549_t13(_1550_x, _1550_y);
    $line_idx--;
    if (_1549_t14) {
        goto BB1817;
    } else {
        goto BB1821;
    }
BB1817:
    _1549_t12 = 238;
    goto BB1820;
BB1821:
    _1549_t12 = 832;
    goto BB1820;
BB1820:
    _1549_$retval = _1549_t12;
    return _1549_$retval;
}

uint8_t _1554_f(struct struct1 _1554_x, struct struct1 _1554_y){
    uint8_t _1554_t2;
    uint8_t _1554_t4;
    uint8_t _1554_t5;
    uint8_t _1554_t6;
    uint8_t _1554_t0;
    uint8_t _1554_$retval;
    _1554_t2 = _1554_x._0==_1554_y._0;
    if (_1554_t2) {
        goto BB1809;
    } else {
        goto BB1815;
    }
BB1809:
    _1554_t4 = _1554_x._1._0==_1554_y._1._0;
    if (_1554_t4) {
        goto BB1810;
    } else {
        goto BB1815;
    }
BB1815:
    _1554_t0 = 0;
    goto BB1814;
BB1810:
    _1554_t5 = _1554_x._1._1==_1554_y._1._1;
    if (_1554_t5) {
        goto BB1811;
    } else {
        goto BB1815;
    }
BB1814:
    _1554_$retval = _1554_t0;
    return _1554_$retval;
BB1811:
    _1554_t6 = _1554_x._2==_1554_y._2;
    if (_1554_t6) {
        goto BB1812;
    } else {
        goto BB1815;
    }
BB1812:
    _1554_t0 = 1;
    goto BB1814;
}

int main(void) {
  printf("%ld",_1549_main());
  return 0;
}
