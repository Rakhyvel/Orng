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
int64_t _1160_main(void);
uint8_t _1165_f(struct1 _1165_x,struct1 _1165_y);

/* Function definitions */
int64_t _1160_main(void) {
    int64_t _1160_t1;
    int64_t _1160_t3;
    double _1160_t4;
    struct0 _1160_t2;
    uint32_t _1160_t5;
    struct1 _1161_x;
    int64_t _1160_t7;
    int64_t _1160_t9;
    double _1160_t10;
    struct0 _1160_t8;
    uint32_t _1160_t11;
    struct1 _1161_y;
    function2 _1160_t13;
    uint8_t _1160_t14;
    int64_t _1160_t12;
    int64_t _1160_$retval;
    _1160_t1 = 1;
    _1160_t3 = 2;
    _1160_t4 = 3.4e+00;
    _1160_t2 = (struct0) {_1160_t3, _1160_t4};
    _1160_t5 = 114;
    _1161_x = (struct1) {_1160_t1, _1160_t2, _1160_t5};
    _1160_t7 = 1;
    _1160_t9 = 2;
    _1160_t10 = 3.4e+00;
    _1160_t8 = (struct0) {_1160_t9, _1160_t10};
    _1160_t11 = 114;
    _1161_y = (struct1) {_1160_t7, _1160_t8, _1160_t11};
    _1160_t13 = _1165_f;
    $lines[$line_idx++] = "tests/integration/tuples/tuple-equality.orng:5:10:\n    if f(x, y) {\n        ^";
    _1160_t14 = _1160_t13(_1161_x, _1161_y);
    $line_idx--;
    if (_1160_t14) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _1160_t12 = 238;
    goto BB4;
BB5:
    _1160_t12 = 832;
    goto BB4;
BB4:
    _1160_$retval = _1160_t12;
    return _1160_$retval;
}

uint8_t _1165_f(struct1 _1165_x,struct1 _1165_y) {
    uint8_t _1165_t2;
    uint8_t _1165_t4;
    uint8_t _1165_t5;
    uint8_t _1165_t6;
    uint8_t _1165_t0;
    uint8_t _1165_$retval;
    _1165_t2 = _1165_x._0 == _1165_y._0;
    if (_1165_t2) {
        goto BB1;
    } else {
        goto BB7;
    }
BB1:
    _1165_t4 = _1165_x._1._0 == _1165_y._1._0;
    if (_1165_t4) {
        goto BB2;
    } else {
        goto BB7;
    }
BB7:
    _1165_t0 = 0;
    goto BB6;
BB2:
    _1165_t5 = _1165_x._1._1 == _1165_y._1._1;
    if (_1165_t5) {
        goto BB3;
    } else {
        goto BB7;
    }
BB6:
    _1165_$retval = _1165_t0;
    return _1165_$retval;
BB3:
    _1165_t6 = _1165_x._2 == _1165_y._2;
    if (_1165_t6) {
        goto BB4;
    } else {
        goto BB7;
    }
BB4:
    _1165_t0 = 1;
    goto BB6;
}

int main(void) {
  printf("%ld",_1160_main());
  return 0;
}
