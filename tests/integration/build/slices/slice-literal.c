/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef struct {
    int64_t* _0;
    int64_t _1;
} struct1;

typedef int64_t(*function0)(struct1);

typedef struct {
    int64_t _0;
    int64_t _1;
    int64_t _2;
} struct2;

/* Function forward definitions */
int64_t _913_main(void);
int64_t _915_sum(struct1 _915_xs);

/* Function definitions */
int64_t _913_main(void) {
    function0 _913_t0;
    int64_t _913_t3;
    int64_t _913_t5;
    int64_t _913_t6;
    int64_t _913_t7;
    struct2 _913_t4;
    int64_t* _913_t8;
    int64_t _913_t9;
    struct1 _913_t2;
    int64_t _913_t1;
    int64_t _913_$retval;
    _913_t0 = _915_sum;
    _913_t3 = 0;
    _913_t5 = 200;
    _913_t6 = 0;
    _913_t7 = 8;
    _913_t4 = (struct2) {_913_t5, _913_t6, _913_t7};
    _913_t8 = ((int64_t*)&_913_t4 + _913_t3);
    _913_t9 = 3;
    _913_t2 = (struct1) {_913_t8, _913_t9};
    $lines[$line_idx++] = "tests/integration/slices/slice-literal.orng:3:9:\n    sum([](200, 0, 8)) // Slice of product literal\n       ^";
    _913_t1 = _913_t0(_913_t2);
    $line_idx--;
    _913_$retval = _913_t1;
    return _913_$retval;
}

int64_t _915_sum(struct1 _915_xs) {
    int64_t _915_t1;
    uint8_t _915_t3;
    uint8_t _915_t2;
    int64_t _915_t0;
    int64_t _915_t10;
    int64_t* _915_t11;
    struct1 _915_t12;
    int64_t _915_t7;
    int64_t _915_$retval;
    int64_t _915_t5;
    function0 _915_t6;
    int64_t _915_t8;
    uint8_t _915_t9;
    _915_t1 = 0;
    _915_t3 = _915_xs._1 == _915_t1;
    if (_915_t3) {
        goto BB1;
    } else {
        goto BB11;
    }
BB1:
    _915_t2 = 1;
    goto BB2;
BB11:
    _915_t2 = 0;
    goto BB2;
BB2:
    if (_915_t2) {
        goto BB3;
    } else {
        goto BB7;
    }
BB3:
    _915_t0 = 0;
    goto BB6;
BB7:
    _915_t5 = 0;
    _915_t6 = _915_sum;
    _915_t8 = 1;
    _915_t9 = _915_t8 > _915_xs._1;
    if (_915_t9) {
        goto BB8;
    } else {
        goto BB9;
    }
BB6:
    _915_$retval = _915_t0;
    return _915_$retval;
BB8:
    $lines[$line_idx++] = "tests/integration/slices/slice-literal.orng:10:24:\n        xs[0] + sum(xs[1..])\n                      ^";
    $panic("subslice lower bound is greater than upper bound\n");
BB9:
    _915_t10 = $sub_int64_t(_915_xs._1, _915_t8, "tests/integration/slices/slice-literal.orng:10:24:\n        xs[0] + sum(xs[1..])\n                      ^");
    _915_t11 = _915_xs._0 + _915_t8;
    _915_t12 = (struct1) {_915_t11, _915_t10};
    $lines[$line_idx++] = "tests/integration/slices/slice-literal.orng:10:21:\n        xs[0] + sum(xs[1..])\n                   ^";
    _915_t7 = _915_t6(_915_t12);
    $line_idx--;
    _915_t0 = $add_int64_t(*((int64_t*)_915_xs._0 + _915_t5), _915_t7, "tests/integration/slices/slice-literal.orng:10:16:\n        xs[0] + sum(xs[1..])\n              ^");
    goto BB6;
}

int main(void) {
  printf("%ld",_913_main());
  return 0;
}
