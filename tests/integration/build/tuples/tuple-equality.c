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
int64_t _59_main(void);
uint8_t _64_f(struct1 _64_x,struct1 _64_y);

/* Function definitions */
int64_t _59_main(void) {
    int64_t _59_t1;
    int64_t _59_t3;
    double _59_t4;
    struct0 _59_t2;
    uint32_t _59_t5;
    struct1 _60_x;
    int64_t _59_t7;
    int64_t _59_t9;
    double _59_t10;
    struct0 _59_t8;
    uint32_t _59_t11;
    struct1 _60_y;
    function2 _59_t13;
    uint8_t _59_t14;
    int64_t _59_t12;
    int64_t _59_$retval;
    _59_t1 = 1;
    _59_t3 = 2;
    _59_t4 = 3.4e+00;
    _59_t2 = (struct0) {_59_t3, _59_t4};
    _59_t5 = 114;
    _60_x = (struct1) {_59_t1, _59_t2, _59_t5};
    _59_t7 = 1;
    _59_t9 = 2;
    _59_t10 = 3.4e+00;
    _59_t8 = (struct0) {_59_t9, _59_t10};
    _59_t11 = 114;
    _60_y = (struct1) {_59_t7, _59_t8, _59_t11};
    _59_t13 = _64_f;
    $lines[$line_idx++] = "tests/integration/tuples/tuple-equality.orng:5:10:\n    if f(x, y) {\n        ^";
    _59_t14 = _59_t13(_60_x, _60_y);
    $line_idx--;
    if (_59_t14) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _59_t12 = 238;
    goto BB4;
BB5:
    _59_t12 = 832;
    goto BB4;
BB4:
    _59_$retval = _59_t12;
    return _59_$retval;
}

uint8_t _64_f(struct1 _64_x,struct1 _64_y) {
    uint8_t _64_t2;
    uint8_t _64_t4;
    uint8_t _64_t5;
    uint8_t _64_t6;
    uint8_t _64_t0;
    uint8_t _64_$retval;
    _64_t2 = _64_x._0 == _64_y._0;
    if (_64_t2) {
        goto BB1;
    } else {
        goto BB7;
    }
BB1:
    _64_t4 = _64_x._1._0 == _64_y._1._0;
    if (_64_t4) {
        goto BB2;
    } else {
        goto BB7;
    }
BB7:
    _64_t0 = 0;
    goto BB6;
BB2:
    _64_t5 = _64_x._1._1 == _64_y._1._1;
    if (_64_t5) {
        goto BB3;
    } else {
        goto BB7;
    }
BB6:
    _64_$retval = _64_t0;
    return _64_$retval;
BB3:
    _64_t6 = _64_x._2 == _64_y._2;
    if (_64_t6) {
        goto BB4;
    } else {
        goto BB7;
    }
BB4:
    _64_t0 = 1;
    goto BB6;
}

int main(void) {
  printf("%ld",_59_main());
  return 0;
}
