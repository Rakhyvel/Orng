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
int64_t _39_main(void);
int64_t _41_sum(struct1 _41_xs);

/* Function definitions */
int64_t _39_main(void) {
    function0 _39_t0;
    int64_t _39_t3;
    int64_t _39_t5;
    int64_t _39_t6;
    int64_t _39_t7;
    struct2 _39_t4;
    int64_t* _39_t8;
    int64_t _39_t9;
    struct1 _39_t2;
    int64_t _39_t1;
    int64_t _39_$retval;
    _39_t0 = _41_sum;
    _39_t3 = 0;
    _39_t5 = 200;
    _39_t6 = 0;
    _39_t7 = 8;
    _39_t4 = (struct2) {_39_t5, _39_t6, _39_t7};
    _39_t8 = ((int64_t*)&_39_t4 + _39_t3);
    _39_t9 = 3;
    _39_t2 = (struct1) {_39_t8, _39_t9};
    $lines[$line_idx++] = "tests/integration/slices/slice-literal.orng:3:9:\n    sum([](200, 0, 8)) // Slice of product literal\n       ^";
    _39_t1 = _39_t0(_39_t2);
    $line_idx--;
    _39_$retval = _39_t1;
    return _39_$retval;
}

int64_t _41_sum(struct1 _41_xs) {
    int64_t _41_t1;
    uint8_t _41_t3;
    int64_t _41_t10;
    int64_t* _41_t11;
    struct1 _41_t12;
    int64_t _41_t7;
    int64_t _41_t0;
    int64_t _41_$retval;
    int64_t _41_t5;
    function0 _41_t6;
    int64_t _41_t8;
    uint8_t _41_t9;
    _41_t1 = 0;
    _41_t3 = _41_xs._1 == _41_t1;
    if (_41_t3) {
        goto BB3;
    } else {
        goto BB7;
    }
BB3:
    _41_t0 = 0;
    goto BB6;
BB7:
    _41_t5 = 0;
    _41_t6 = _41_sum;
    _41_t8 = 1;
    _41_t9 = _41_t8 > _41_xs._1;
    if (_41_t9) {
        goto BB8;
    } else {
        goto BB9;
    }
BB6:
    _41_$retval = _41_t0;
    return _41_$retval;
BB8:
    $lines[$line_idx++] = "tests/integration/slices/slice-literal.orng:10:24:\n        xs[0] + sum(xs[1..])\n                      ^";
    $panic("subslice lower bound is greater than upper bound\n");
BB9:
    _41_t10 = $sub_int64_t(_41_xs._1, _41_t8, "tests/integration/slices/slice-literal.orng:10:24:\n        xs[0] + sum(xs[1..])\n                      ^");
    _41_t11 = _41_xs._0 + _41_t8;
    _41_t12 = (struct1) {_41_t11, _41_t10};
    $lines[$line_idx++] = "tests/integration/slices/slice-literal.orng:10:21:\n        xs[0] + sum(xs[1..])\n                   ^";
    _41_t7 = _41_t6(_41_t12);
    $line_idx--;
    _41_t0 = $add_int64_t(*((int64_t*)_41_xs._0 + _41_t5), _41_t7, "tests/integration/slices/slice-literal.orng:10:16:\n        xs[0] + sum(xs[1..])\n              ^");
    goto BB6;
}

int main(void) {
  printf("%ld",_39_main());
  return 0;
}
