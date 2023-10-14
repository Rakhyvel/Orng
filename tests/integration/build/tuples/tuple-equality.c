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

/* Function forward definitions */
int64_t _1_main(void);
uint8_t _6_f(struct1 _6_x,struct1 _6_y);

/* Function definitions */
int64_t _1_main(void) {
    struct0 _1_t2;
    struct1 _2_x;
    struct0 _1_t8;
    struct1 _2_y;
    int64_t _1_t12;
    int64_t _1_$retval;
    _1_t2 = (struct0) {2, 3.4e+00};
    _2_x = (struct1) {1, _1_t2, 114};
    _1_t8 = (struct0) {2, 3.4e+00};
    _2_y = (struct1) {1, _1_t8, 114};
    $lines[$line_idx++] = "tests/integration/tuples/tuple-equality.orng:5:10:\n    if f(x, y) {\n        ^";
    $line_idx--;
    if (_6_f(_2_x, _2_y)) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _1_t12 = 238;
    goto BB4;
BB5:
    _1_t12 = 832;
BB4:
    _1_$retval = _1_t12;
    return _1_$retval;
}

uint8_t _6_f(struct1 _6_x,struct1 _6_y) {
    struct0 _6_t5;
    struct0 _6_t6;
    uint8_t _6_t0;
    uint8_t _6_$retval;
    if (_6_x._0 == _6_y._0) {
        goto BB1;
    } else {
        goto BB7;
    }
BB1:
    _6_t5 = _6_x._1;
    _6_t6 = _6_y._1;
    if (_6_x._1._0 == _6_y._1._0) {
        goto BB2;
    }
BB7:
    _6_t0 = 0;
    goto BB6;
BB2:
    if (_6_t5._1 == _6_t6._1) {
        goto BB3;
    } else {
        goto BB7;
    }
BB6:
    _6_$retval = _6_t0;
    return _6_$retval;
BB3:
    if (_6_x._2 == _6_y._2) {
        goto BB4;
    } else {
        goto BB7;
    }
BB4:
    _6_t0 = 1;
    goto BB6;
}

int main(void)
{
  printf("%ld",_1_main());
  return 0;
}
