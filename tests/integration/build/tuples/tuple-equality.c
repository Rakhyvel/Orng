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
int64_t _1091_main(void);
uint8_t _1096_f(struct1 _1096_x,struct1 _1096_y);

/* Function definitions */
int64_t _1091_main(void) {
    int64_t _1091_t1;
    int64_t _1091_t3;
    double _1091_t4;
    struct0 _1091_t2;
    uint32_t _1091_t5;
    struct1 _1092_x;
    int64_t _1091_t7;
    int64_t _1091_t9;
    double _1091_t10;
    struct0 _1091_t8;
    uint32_t _1091_t11;
    struct1 _1092_y;
    function2 _1091_t13;
    uint8_t _1091_t14;
    int64_t _1091_t12;
    int64_t _1091_$retval;
    _1091_t1 = 1;
    _1091_t3 = 2;
    _1091_t4 = 3.4e+00;
    _1091_t2 = (struct0) {_1091_t3, _1091_t4};
    _1091_t5 = 114;
    _1092_x = (struct1) {_1091_t1, _1091_t2, _1091_t5};
    _1091_t7 = 1;
    _1091_t9 = 2;
    _1091_t10 = 3.4e+00;
    _1091_t8 = (struct0) {_1091_t9, _1091_t10};
    _1091_t11 = 114;
    _1092_y = (struct1) {_1091_t7, _1091_t8, _1091_t11};
    _1091_t13 = _1096_f;
    $lines[$line_idx++] = "tests/integration/tuples/tuple-equality.orng:5:10:\n    if f(x, y) {\n        ^";
    _1091_t14 = _1091_t13(_1092_x, _1092_y);
    $line_idx--;
    if (_1091_t14) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _1091_t12 = 238;
    goto BB4;
BB5:
    _1091_t12 = 832;
    goto BB4;
BB4:
    _1091_$retval = _1091_t12;
    return _1091_$retval;
}

uint8_t _1096_f(struct1 _1096_x,struct1 _1096_y) {
    uint8_t _1096_t2;
    uint8_t _1096_t4;
    uint8_t _1096_t5;
    uint8_t _1096_t6;
    uint8_t _1096_t0;
    uint8_t _1096_$retval;
    _1096_t2 = _1096_x._0 == _1096_y._0;
    if (_1096_t2) {
        goto BB1;
    } else {
        goto BB7;
    }
BB1:
    _1096_t4 = _1096_x._1._0 == _1096_y._1._0;
    if (_1096_t4) {
        goto BB2;
    } else {
        goto BB7;
    }
BB7:
    _1096_t0 = 0;
    goto BB6;
BB2:
    _1096_t5 = _1096_x._1._1 == _1096_y._1._1;
    if (_1096_t5) {
        goto BB3;
    } else {
        goto BB7;
    }
BB6:
    _1096_$retval = _1096_t0;
    return _1096_$retval;
BB3:
    _1096_t6 = _1096_x._2 == _1096_y._2;
    if (_1096_t6) {
        goto BB4;
    } else {
        goto BB7;
    }
BB4:
    _1096_t0 = 1;
    goto BB6;
}

int main(void) {
  printf("%ld",_1091_main());
  return 0;
}
