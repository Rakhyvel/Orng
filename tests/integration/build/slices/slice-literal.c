/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward typedefs */
struct struct1;
struct struct2;

/* Typedefs */
struct struct1 {
    int64_t* _0;
    int64_t _1;
};

typedef int64_t(*function0)(struct struct1);

struct struct2 {
    int64_t _0;
    int64_t _1;
    int64_t _2;
};

/* Function forward definitions */
int64_t _1333_main(void);
int64_t _1335_sum(struct struct1 _1335_xs);

/* Function definitions */
int64_t _1333_main(void){
    function0 _1333_t0;
    int64_t _1333_t4;
    int64_t _1333_t5;
    int64_t _1333_t6;
    struct struct2 _1333_t3;
    int64_t _1333_t7;
    int64_t _1333_t8;
    int64_t* _1333_t9;
    int64_t _1333_t10;
    struct struct1 _1333_t2;
    int64_t _1333_t1;
    int64_t _1333_$retval;
    _1333_t0 = _1335_sum;
    _1333_t4 = 200;
    _1333_t5 = 0;
    _1333_t6 = 8;
    _1333_t3 = (struct struct2) {_1333_t4, _1333_t5, _1333_t6};
    _1333_t7 = 0;
    _1333_t8 = 3;
    $bounds_check(_1333_t7, _1333_t8, "tests/integration/slices/slice-literal.orng:3:16:\n    sum([](200, 0, 8)) // Slice of product literal\n              ^");
    _1333_t9 = ((int64_t*)&_1333_t3 + _1333_t7);
    _1333_t10 = 3;
    _1333_t2 = (struct struct1) {_1333_t9, _1333_t10};
    $lines[$line_idx++] = "tests/integration/slices/slice-literal.orng:3:9:\n    sum([](200, 0, 8)) // Slice of product literal\n       ^";
    _1333_t1 = _1333_t0(_1333_t2);
    $line_idx--;
    _1333_$retval = _1333_t1;
    return _1333_$retval;
}

int64_t _1335_sum(struct struct1 _1335_xs){
    int64_t _1335_t1;
    uint8_t _1335_t3;
    int64_t _1335_t10;
    int64_t* _1335_t11;
    struct struct1 _1335_t12;
    int64_t _1335_t7;
    int64_t _1335_t0;
    int64_t _1335_$retval;
    int64_t _1335_t5;
    function0 _1335_t6;
    int64_t _1335_t8;
    uint8_t _1335_t9;
    _1335_t1 = 0;
    _1335_t3 = _1335_xs._1==_1335_t1;
    if (_1335_t3) {
        goto BB1605;
    } else {
        goto BB1609;
    }
BB1605:
    _1335_t0 = 0;
    goto BB1608;
BB1609:
    _1335_t5 = 0;
    _1335_t6 = _1335_sum;
    _1335_t8 = 1;
    _1335_t9 = _1335_t8>_1335_xs._1;
    if (_1335_t9) {
        goto BB1610;
    } else {
        goto BB1611;
    }
BB1608:
    _1335_$retval = _1335_t0;
    return _1335_$retval;
BB1610:
    $lines[$line_idx++] = "tests/integration/slices/slice-literal.orng:10:24:\n        xs[0] + sum(xs[1..])\n                      ^";
    $panic("subslice lower bound is greater than upper bound\n");
BB1611:
    _1335_t10 = $sub_int64_t(_1335_xs._1, _1335_t8, "tests/integration/slices/slice-literal.orng:10:24:\n        xs[0] + sum(xs[1..])\n                      ^");
    _1335_t11 = _1335_xs._0+_1335_t8;
    _1335_t12 = (struct struct1) {_1335_t11, _1335_t10};
    $lines[$line_idx++] = "tests/integration/slices/slice-literal.orng:10:21:\n        xs[0] + sum(xs[1..])\n                   ^";
    _1335_t7 = _1335_t6(_1335_t12);
    $line_idx--;
    $bounds_check(_1335_t5, _1335_xs._1, "tests/integration/slices/slice-literal.orng:10:16:\n        xs[0] + sum(xs[1..])\n              ^");
    _1335_t0 = $add_int64_t(*((int64_t*)_1335_xs._0 + _1335_t5), _1335_t7, "tests/integration/slices/slice-literal.orng:10:16:\n        xs[0] + sum(xs[1..])\n              ^");
    goto BB1608;
}

int main(void) {
  printf("%ld",_1333_main());
  return 0;
}
