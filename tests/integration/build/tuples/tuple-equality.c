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
int64_t _56_main(void);
uint8_t _61_f(struct1 _61_x,struct1 _61_y);

/* Function definitions */
int64_t _56_main(void) {
    int64_t _56_t1;
    int64_t _56_t3;
    double _56_t4;
    struct0 _56_t2;
    uint32_t _56_t5;
    struct1 _57_x;
    int64_t _56_t7;
    int64_t _56_t9;
    double _56_t10;
    struct0 _56_t8;
    uint32_t _56_t11;
    struct1 _57_y;
    function2 _56_t13;
    uint8_t _56_t14;
    int64_t _56_t12;
    int64_t _56_$retval;
    _56_t1 = 1;
    _56_t3 = 2;
    _56_t4 = 3.4e+00;
    _56_t2 = (struct0) {_56_t3, _56_t4};
    _56_t5 = 114;
    _57_x = (struct1) {_56_t1, _56_t2, _56_t5};
    _56_t7 = 1;
    _56_t9 = 2;
    _56_t10 = 3.4e+00;
    _56_t8 = (struct0) {_56_t9, _56_t10};
    _56_t11 = 114;
    _57_y = (struct1) {_56_t7, _56_t8, _56_t11};
    _56_t13 = _61_f;
    $lines[$line_idx++] = "tests/integration/tuples/tuple-equality.orng:5:10:\n    if f(x, y) {\n        ^";
    _56_t14 = _56_t13(_57_x, _57_y);
    $line_idx--;
    if (_56_t14) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _56_t12 = 238;
    goto BB4;
BB5:
    _56_t12 = 832;
    goto BB4;
BB4:
    _56_$retval = _56_t12;
    return _56_$retval;
}

uint8_t _61_f(struct1 _61_x,struct1 _61_y) {
    uint8_t _61_t2;
    uint8_t _61_t4;
    uint8_t _61_t5;
    uint8_t _61_t6;
    uint8_t _61_t0;
    uint8_t _61_$retval;
    _61_t2 = _61_x._0 == _61_y._0;
    if (_61_t2) {
        goto BB1;
    } else {
        goto BB7;
    }
BB1:
    _61_t4 = _61_x._1._0 == _61_y._1._0;
    if (_61_t4) {
        goto BB2;
    } else {
        goto BB7;
    }
BB7:
    _61_t0 = 0;
    goto BB6;
BB2:
    _61_t5 = _61_x._1._1 == _61_y._1._1;
    if (_61_t5) {
        goto BB3;
    } else {
        goto BB7;
    }
BB6:
    _61_$retval = _61_t0;
    return _61_$retval;
BB3:
    _61_t6 = _61_x._2 == _61_y._2;
    if (_61_t6) {
        goto BB4;
    } else {
        goto BB7;
    }
BB4:
    _61_t0 = 1;
    goto BB6;
}

int main(void) {
  printf("%ld",_56_main());
  return 0;
}
