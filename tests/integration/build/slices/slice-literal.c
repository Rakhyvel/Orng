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
int64_t _1011_main(void);
int64_t _1013_sum(struct1 _1013_xs);

/* Function definitions */
int64_t _1011_main(void) {
    function0 _1011_t0;
    int64_t _1011_t3;
    int64_t _1011_t5;
    int64_t _1011_t6;
    int64_t _1011_t7;
    struct2 _1011_t4;
    int64_t* _1011_t8;
    int64_t _1011_t9;
    struct1 _1011_t2;
    int64_t _1011_t1;
    int64_t _1011_$retval;
    _1011_t0 = _1013_sum;
    _1011_t3 = 0;
    _1011_t5 = 200;
    _1011_t6 = 0;
    _1011_t7 = 8;
    _1011_t4 = (struct2) {_1011_t5, _1011_t6, _1011_t7};
    _1011_t8 = ((int64_t*)&_1011_t4 + _1011_t3);
    _1011_t9 = 3;
    _1011_t2 = (struct1) {_1011_t8, _1011_t9};
    $lines[$line_idx++] = "tests/integration/slices/slice-literal.orng:3:9:\n    sum([](200, 0, 8)) // Slice of product literal\n       ^";
    _1011_t1 = _1011_t0(_1011_t2);
    $line_idx--;
    _1011_$retval = _1011_t1;
    return _1011_$retval;
}

int64_t _1013_sum(struct1 _1013_xs) {
    int64_t _1013_t1;
    uint8_t _1013_t3;
    int64_t _1013_t10;
    int64_t* _1013_t11;
    struct1 _1013_t12;
    int64_t _1013_t7;
    int64_t _1013_t0;
    int64_t _1013_$retval;
    int64_t _1013_t5;
    function0 _1013_t6;
    int64_t _1013_t8;
    uint8_t _1013_t9;
    _1013_t1 = 0;
    _1013_t3 = _1013_xs._1 == _1013_t1;
    if (_1013_t3) {
        goto BB3;
    } else {
        goto BB7;
    }
BB3:
    _1013_t0 = 0;
    goto BB6;
BB7:
    _1013_t5 = 0;
    _1013_t6 = _1013_sum;
    _1013_t8 = 1;
    _1013_t9 = _1013_t8 > _1013_xs._1;
    if (_1013_t9) {
        goto BB8;
    } else {
        goto BB9;
    }
BB6:
    _1013_$retval = _1013_t0;
    return _1013_$retval;
BB8:
    $lines[$line_idx++] = "tests/integration/slices/slice-literal.orng:10:24:\n        xs[0] + sum(xs[1..])\n                      ^";
    $panic("subslice lower bound is greater than upper bound\n");
BB9:
    _1013_t10 = $sub_int64_t(_1013_xs._1, _1013_t8, "tests/integration/slices/slice-literal.orng:10:24:\n        xs[0] + sum(xs[1..])\n                      ^");
    _1013_t11 = _1013_xs._0 + _1013_t8;
    _1013_t12 = (struct1) {_1013_t11, _1013_t10};
    $lines[$line_idx++] = "tests/integration/slices/slice-literal.orng:10:21:\n        xs[0] + sum(xs[1..])\n                   ^";
    _1013_t7 = _1013_t6(_1013_t12);
    $line_idx--;
    _1013_t0 = $add_int64_t(*((int64_t*)_1013_xs._0 + _1013_t5), _1013_t7, "tests/integration/slices/slice-literal.orng:10:16:\n        xs[0] + sum(xs[1..])\n              ^");
    goto BB6;
}

int main(void) {
  printf("%ld",_1011_main());
  return 0;
}
