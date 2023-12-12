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
int64_t _1211_main(void);
uint8_t _1216_f(struct1 _1216_x,struct1 _1216_y);

/* Function definitions */
int64_t _1211_main(void) {
    int64_t _1211_t1;
    int64_t _1211_t3;
    double _1211_t4;
    struct0 _1211_t2;
    uint32_t _1211_t5;
    struct1 _1212_x;
    int64_t _1211_t7;
    int64_t _1211_t9;
    double _1211_t10;
    struct0 _1211_t8;
    uint32_t _1211_t11;
    struct1 _1212_y;
    function2 _1211_t13;
    uint8_t _1211_t14;
    int64_t _1211_t12;
    int64_t _1211_$retval;
    _1211_t1 = 1;
    _1211_t3 = 2;
    _1211_t4 = 3.4e+00;
    _1211_t2 = (struct0) {_1211_t3, _1211_t4};
    _1211_t5 = 114;
    _1212_x = (struct1) {_1211_t1, _1211_t2, _1211_t5};
    _1211_t7 = 1;
    _1211_t9 = 2;
    _1211_t10 = 3.4e+00;
    _1211_t8 = (struct0) {_1211_t9, _1211_t10};
    _1211_t11 = 114;
    _1212_y = (struct1) {_1211_t7, _1211_t8, _1211_t11};
    _1211_t13 = _1216_f;
    $lines[$line_idx++] = "tests/integration/tuples/tuple-equality.orng:5:10:\n    if f(x, y) {\n        ^";
    _1211_t14 = _1211_t13(_1212_x, _1212_y);
    $line_idx--;
    if (_1211_t14) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _1211_t12 = 238;
    goto BB4;
BB5:
    _1211_t12 = 832;
    goto BB4;
BB4:
    _1211_$retval = _1211_t12;
    return _1211_$retval;
}

uint8_t _1216_f(struct1 _1216_x,struct1 _1216_y) {
    uint8_t _1216_t2;
    uint8_t _1216_t4;
    uint8_t _1216_t5;
    uint8_t _1216_t6;
    uint8_t _1216_t0;
    uint8_t _1216_$retval;
    _1216_t2 = _1216_x._0 == _1216_y._0;
    if (_1216_t2) {
        goto BB1;
    } else {
        goto BB7;
    }
BB1:
    _1216_t4 = _1216_x._1._0 == _1216_y._1._0;
    if (_1216_t4) {
        goto BB2;
    } else {
        goto BB7;
    }
BB7:
    _1216_t0 = 0;
    goto BB6;
BB2:
    _1216_t5 = _1216_x._1._1 == _1216_y._1._1;
    if (_1216_t5) {
        goto BB3;
    } else {
        goto BB7;
    }
BB6:
    _1216_$retval = _1216_t0;
    return _1216_$retval;
BB3:
    _1216_t6 = _1216_x._2 == _1216_y._2;
    if (_1216_t6) {
        goto BB4;
    } else {
        goto BB7;
    }
BB4:
    _1216_t0 = 1;
    goto BB6;
}

int main(void) {
  printf("%ld",_1211_main());
  return 0;
}
