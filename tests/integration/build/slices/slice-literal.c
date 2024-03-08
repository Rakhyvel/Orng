/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward struct, union, and function declarations */
struct struct1;
struct struct2;

/* Struct, union, and function definitions */
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
int64_t _1380_main(void);
int64_t _1382_sum(struct struct1 _1382_xs);


/* Function definitions */
int64_t _1380_main(void){
    function0 _1380_t0;
    int64_t _1380_t4;
    int64_t _1380_t5;
    int64_t _1380_t6;
    struct struct2 _1380_t3;
    int64_t _1380_t7;
    int64_t _1380_t8;
    int64_t* _1380_t9;
    int64_t _1380_t10;
    struct struct1 _1380_t2;
    int64_t _1380_t1;
    int64_t _1380_$retval;
    _1380_t0 = (function0) _1382_sum;
    _1380_t4 = 200;
    _1380_t5 = 0;
    _1380_t6 = 8;
    _1380_t3 = (struct struct2) {_1380_t4, _1380_t5, _1380_t6};
    _1380_t7 = 0;
    _1380_t8 = 3;
    $bounds_check(_1380_t7, _1380_t8, "tests/integration/slices/slice-literal.orng:3:16:\n    sum([](200, 0, 8)) // Slice of product literal\n              ^");
    _1380_t9 = ((int64_t*)&_1380_t3 + _1380_t7);
    _1380_t10 = 3;
    _1380_t2 = (struct struct1) {_1380_t9, _1380_t10};
    $lines[$line_idx++] = "tests/integration/slices/slice-literal.orng:3:9:\n    sum([](200, 0, 8)) // Slice of product literal\n       ^";
    _1380_t1 = _1380_t0(_1380_t2);
    $line_idx--;
    _1380_$retval = _1380_t1;
    return _1380_$retval;
}

int64_t _1382_sum(struct struct1 _1382_xs){
    int64_t _1382_t1;
    uint8_t _1382_t3;
    int64_t _1382_t10;
    int64_t* _1382_t11;
    struct struct1 _1382_t12;
    int64_t _1382_t7;
    int64_t _1382_t0;
    int64_t _1382_$retval;
    int64_t _1382_t5;
    function0 _1382_t6;
    int64_t _1382_t8;
    uint8_t _1382_t9;
    _1382_t1 = 0;
    _1382_t3 = _1382_xs._1==_1382_t1;
    if (_1382_t3) {
        goto BB1647;
    } else {
        goto BB1651;
    }
BB1647:
    _1382_t0 = 0;
    goto BB1650;
BB1651:
    _1382_t5 = 0;
    _1382_t6 = (function0) _1382_sum;
    _1382_t8 = 1;
    _1382_t9 = _1382_t8>_1382_xs._1;
    if (_1382_t9) {
        goto BB1652;
    } else {
        goto BB1653;
    }
BB1650:
    _1382_$retval = _1382_t0;
    return _1382_$retval;
BB1652:
    $lines[$line_idx++] = "tests/integration/slices/slice-literal.orng:10:24:\n        xs[0] + sum(xs[1..])\n                      ^";
    $panic("subslice lower bound is greater than upper bound\n");
BB1653:
    _1382_t10 = $sub_int64_t(_1382_xs._1, _1382_t8, "tests/integration/slices/slice-literal.orng:10:24:\n        xs[0] + sum(xs[1..])\n                      ^");
    _1382_t11 = _1382_xs._0+_1382_t8;
    _1382_t12 = (struct struct1) {_1382_t11, _1382_t10};
    $lines[$line_idx++] = "tests/integration/slices/slice-literal.orng:10:21:\n        xs[0] + sum(xs[1..])\n                   ^";
    _1382_t7 = _1382_t6(_1382_t12);
    $line_idx--;
    $bounds_check(_1382_t5, _1382_xs._1, "tests/integration/slices/slice-literal.orng:10:16:\n        xs[0] + sum(xs[1..])\n              ^");
    _1382_t0 = $add_int64_t(*((int64_t*)_1382_xs._0 + _1382_t5), _1382_t7, "tests/integration/slices/slice-literal.orng:10:16:\n        xs[0] + sum(xs[1..])\n              ^");
    goto BB1650;
}


int main(void) {
  printf("%ld",_1380_main());
  return 0;
}
