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
int64_t _1602_main(void);
uint8_t _1607_f(struct1 _1607_x,struct1 _1607_y);

/* Function definitions */
int64_t _1602_main(void) {
    int64_t _1602_t1;
    int64_t _1602_t3;
    double _1602_t4;
    struct0 _1602_t2;
    uint32_t _1602_t5;
    struct1 _1603_x;
    int64_t _1602_t7;
    int64_t _1602_t9;
    double _1602_t10;
    struct0 _1602_t8;
    uint32_t _1602_t11;
    struct1 _1603_y;
    function2 _1602_t13;
    uint8_t _1602_t14;
    int64_t _1602_t12;
    int64_t _1602_$retval;
    _1602_t1 = 1;
    _1602_t3 = 2;
    _1602_t4 = 3.4e+00;
    _1602_t2 = (struct0) {_1602_t3, _1602_t4};
    _1602_t5 = 114;
    _1603_x = (struct1) {_1602_t1, _1602_t2, _1602_t5};
    _1602_t7 = 1;
    _1602_t9 = 2;
    _1602_t10 = 3.4e+00;
    _1602_t8 = (struct0) {_1602_t9, _1602_t10};
    _1602_t11 = 114;
    _1603_y = (struct1) {_1602_t7, _1602_t8, _1602_t11};
    _1602_t13 = _1607_f;
    $lines[$line_idx++] = "tests/integration/tuples/tuple-equality.orng:5:10:\n    if f(x, y) {\n        ^";
    _1602_t14 = _1602_t13(_1603_x, _1603_y);
    $line_idx--;
    if (_1602_t14) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _1602_t12 = 238;
    goto BB4;
BB5:
    _1602_t12 = 832;
    goto BB4;
BB4:
    _1602_$retval = _1602_t12;
    return _1602_$retval;
}

uint8_t _1607_f(struct1 _1607_x,struct1 _1607_y) {
    uint8_t _1607_t2;
    uint8_t _1607_t4;
    uint8_t _1607_t5;
    uint8_t _1607_t6;
    uint8_t _1607_t0;
    uint8_t _1607_$retval;
    _1607_t2 = _1607_x._0 == _1607_y._0;
    if (_1607_t2) {
        goto BB1;
    } else {
        goto BB7;
    }
BB1:
    _1607_t4 = _1607_x._1._0 == _1607_y._1._0;
    if (_1607_t4) {
        goto BB2;
    } else {
        goto BB7;
    }
BB7:
    _1607_t0 = 0;
    goto BB6;
BB2:
    _1607_t5 = _1607_x._1._1 == _1607_y._1._1;
    if (_1607_t5) {
        goto BB3;
    } else {
        goto BB7;
    }
BB6:
    _1607_$retval = _1607_t0;
    return _1607_$retval;
BB3:
    _1607_t6 = _1607_x._2 == _1607_y._2;
    if (_1607_t6) {
        goto BB4;
    } else {
        goto BB7;
    }
BB4:
    _1607_t0 = 1;
    goto BB6;
}

int main(void) {
  printf("%ld",_1602_main());
  return 0;
}
