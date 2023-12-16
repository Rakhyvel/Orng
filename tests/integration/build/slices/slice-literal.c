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
int64_t _1295_main(void);
int64_t _1297_sum(struct1 _1297_xs);

/* Function definitions */
int64_t _1295_main(void){
    function0 _1295_t0;
    int64_t _1295_t3;
    int64_t _1295_t5;
    int64_t _1295_t6;
    int64_t _1295_t7;
    struct2 _1295_t4;
    int64_t* _1295_t8;
    int64_t _1295_t9;
    struct1 _1295_t2;
    int64_t _1295_t1;
    int64_t _1295_$retval;
    _1295_t0 = _1297_sum;
    _1295_t3 = 0;
    _1295_t5 = 200;
    _1295_t6 = 0;
    _1295_t7 = 8;
    _1295_t4 = (struct2) {_1295_t5, _1295_t6, _1295_t7};
    _1295_t8 = ((int64_t*)&_1295_t4 + _1295_t3);
    _1295_t9 = 3;
    _1295_t2 = (struct1) {_1295_t8, _1295_t9};
    $lines[$line_idx++] = "tests/integration/slices/slice-literal.orng:3:9:\n    sum([](200, 0, 8)) // Slice of product literal\n       ^";
    _1295_t1 = _1295_t0(_1295_t2);
    $line_idx--;
    _1295_$retval = _1295_t1;
    return _1295_$retval;
}

int64_t _1297_sum(struct1 _1297_xs){
    int64_t _1297_t1;
    uint8_t _1297_t3;
    int64_t _1297_t10;
    int64_t* _1297_t11;
    struct1 _1297_t12;
    int64_t _1297_t7;
    int64_t _1297_t0;
    int64_t _1297_$retval;
    int64_t _1297_t5;
    function0 _1297_t6;
    int64_t _1297_t8;
    uint8_t _1297_t9;
    _1297_t1 = 0;
    _1297_t3 = _1297_xs._1 == _1297_t1;
    if (_1297_t3) {
        goto BB3;
    } else {
        goto BB7;
    }
BB3:
    _1297_t0 = 0;
    goto BB6;
BB7:
    _1297_t5 = 0;
    _1297_t6 = _1297_sum;
    _1297_t8 = 1;
    _1297_t9 = _1297_t8 > _1297_xs._1;
    if (_1297_t9) {
        goto BB8;
    } else {
        goto BB9;
    }
BB6:
    _1297_$retval = _1297_t0;
    return _1297_$retval;
BB8:
    $lines[$line_idx++] = "tests/integration/slices/slice-literal.orng:10:24:\n        xs[0] + sum(xs[1..])\n                      ^";
    $panic("subslice lower bound is greater than upper bound\n");
BB9:
    _1297_t10 = $sub_int64_t(_1297_xs._1, _1297_t8, "tests/integration/slices/slice-literal.orng:10:24:\n        xs[0] + sum(xs[1..])\n                      ^");
    _1297_t11 = _1297_xs._0 + _1297_t8;
    _1297_t12 = (struct1) {_1297_t11, _1297_t10};
    $lines[$line_idx++] = "tests/integration/slices/slice-literal.orng:10:21:\n        xs[0] + sum(xs[1..])\n                   ^";
    _1297_t7 = _1297_t6(_1297_t12);
    $line_idx--;
    _1297_t0 = $add_int64_t(*((int64_t*)_1297_xs._0 + _1297_t5), _1297_t7, "tests/integration/slices/slice-literal.orng:10:16:\n        xs[0] + sum(xs[1..])\n              ^");
    goto BB6;
}

int main(void) {
  printf("%ld",_1295_main());
  return 0;
}
