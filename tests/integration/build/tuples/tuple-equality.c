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
int64_t _1619_main(void);
uint8_t _1624_f(struct1 _1624_x,struct1 _1624_y);

/* Function definitions */
int64_t _1619_main(void){
    int64_t _1619_t1;
    int64_t _1619_t3;
    double _1619_t4;
    struct0 _1619_t2;
    uint32_t _1619_t5;
    struct1 _1620_x;
    int64_t _1619_t7;
    int64_t _1619_t9;
    double _1619_t10;
    struct0 _1619_t8;
    uint32_t _1619_t11;
    struct1 _1620_y;
    function2 _1619_t13;
    uint8_t _1619_t14;
    int64_t _1619_t12;
    int64_t _1619_$retval;
    _1619_t1 = 1;
    _1619_t3 = 2;
    _1619_t4 = 3.4e+00;
    _1619_t2 = (struct0) {_1619_t3, _1619_t4};
    _1619_t5 = 114;
    _1620_x = (struct1) {_1619_t1, _1619_t2, _1619_t5};
    _1619_t7 = 1;
    _1619_t9 = 2;
    _1619_t10 = 3.4e+00;
    _1619_t8 = (struct0) {_1619_t9, _1619_t10};
    _1619_t11 = 114;
    _1620_y = (struct1) {_1619_t7, _1619_t8, _1619_t11};
    _1619_t13 = _1624_f;
    $lines[$line_idx++] = "tests/integration/tuples/tuple-equality.orng:5:10:\n    if f(x, y) {\n        ^";
    _1619_t14 = _1619_t13(_1620_x, _1620_y);
    $line_idx--;
    if (_1619_t14) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _1619_t12 = 238;
    goto BB4;
BB5:
    _1619_t12 = 832;
    goto BB4;
BB4:
    _1619_$retval = _1619_t12;
    return _1619_$retval;
}

uint8_t _1624_f(struct1 _1624_x,struct1 _1624_y){
    uint8_t _1624_t2;
    uint8_t _1624_t4;
    uint8_t _1624_t5;
    uint8_t _1624_t6;
    uint8_t _1624_t0;
    uint8_t _1624_$retval;
    _1624_t2 = _1624_x._0 == _1624_y._0;
    if (_1624_t2) {
        goto BB1;
    } else {
        goto BB7;
    }
BB1:
    _1624_t4 = _1624_x._1._0 == _1624_y._1._0;
    if (_1624_t4) {
        goto BB2;
    } else {
        goto BB7;
    }
BB7:
    _1624_t0 = 0;
    goto BB6;
BB2:
    _1624_t5 = _1624_x._1._1 == _1624_y._1._1;
    if (_1624_t5) {
        goto BB3;
    } else {
        goto BB7;
    }
BB6:
    _1624_$retval = _1624_t0;
    return _1624_$retval;
BB3:
    _1624_t6 = _1624_x._2 == _1624_y._2;
    if (_1624_t6) {
        goto BB4;
    } else {
        goto BB7;
    }
BB4:
    _1624_t0 = 1;
    goto BB6;
}

int main(void) {
  printf("%ld",_1619_main());
  return 0;
}
