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
int64_t _1470_main(void);
int64_t _1472_sum(struct struct1 _1472_xs);


/* Function definitions */
int64_t _1470_main(void){
    function0 _1470_t0;
    int64_t _1470_t4;
    int64_t _1470_t5;
    int64_t _1470_t6;
    struct struct2 _1470_t3;
    int64_t _1470_t7;
    int64_t _1470_t8;
    int64_t* _1470_t9;
    int64_t _1470_t10;
    struct struct1 _1470_t2;
    int64_t _1470_t1;
    int64_t _1470_$retval;
    _1470_t0 = (function0) _1472_sum;
    _1470_t4 = 200;
    _1470_t5 = 0;
    _1470_t6 = 8;
    _1470_t3 = (struct struct2) {_1470_t4, _1470_t5, _1470_t6};
    _1470_t7 = 0;
    _1470_t8 = 3;
    $bounds_check(_1470_t7, _1470_t8, "tests/integration/slices/slice-literal.orng:3:16:\n    sum([](200, 0, 8)) // Slice of product literal\n              ^");
    _1470_t9 = ((int64_t*)&_1470_t3 + _1470_t7);
    _1470_t10 = 3;
    _1470_t2 = (struct struct1) {_1470_t9, _1470_t10};
    $lines[$line_idx++] = "tests/integration/slices/slice-literal.orng:3:9:\n    sum([](200, 0, 8)) // Slice of product literal\n       ^";
    _1470_t1 = _1470_t0(_1470_t2);
    $line_idx--;
    _1470_$retval = _1470_t1;
    return _1470_$retval;
}

int64_t _1472_sum(struct struct1 _1472_xs){
    int64_t _1472_t1;
    uint8_t _1472_t3;
    int64_t _1472_t10;
    int64_t* _1472_t11;
    struct struct1 _1472_t12;
    int64_t _1472_t7;
    int64_t _1472_t0;
    int64_t _1472_$retval;
    int64_t _1472_t5;
    function0 _1472_t6;
    int64_t _1472_t8;
    uint8_t _1472_t9;
    _1472_t1 = 0;
    _1472_t3 = _1472_xs._1==_1472_t1;
    if (_1472_t3) {
        goto BB1713;
    } else {
        goto BB1717;
    }
BB1713:
    _1472_t0 = 0;
    goto BB1716;
BB1717:
    _1472_t5 = 0;
    _1472_t6 = (function0) _1472_sum;
    _1472_t8 = 1;
    _1472_t9 = _1472_t8>_1472_xs._1;
    if (_1472_t9) {
        goto BB1718;
    } else {
        goto BB1719;
    }
BB1716:
    _1472_$retval = _1472_t0;
    return _1472_$retval;
BB1718:
    $lines[$line_idx++] = "tests/integration/slices/slice-literal.orng:10:24:\n        xs[0] + sum(xs[1..])\n                      ^";
    $panic("subslice lower bound is greater than upper bound\n");
BB1719:
    _1472_t10 = $sub_int64_t(_1472_xs._1, _1472_t8, "tests/integration/slices/slice-literal.orng:10:24:\n        xs[0] + sum(xs[1..])\n                      ^");
    _1472_t11 = _1472_xs._0+_1472_t8;
    _1472_t12 = (struct struct1) {_1472_t11, _1472_t10};
    $lines[$line_idx++] = "tests/integration/slices/slice-literal.orng:10:21:\n        xs[0] + sum(xs[1..])\n                   ^";
    _1472_t7 = _1472_t6(_1472_t12);
    $line_idx--;
    $bounds_check(_1472_t5, _1472_xs._1, "tests/integration/slices/slice-literal.orng:10:16:\n        xs[0] + sum(xs[1..])\n              ^");
    _1472_t0 = $add_int64_t(*((int64_t*)_1472_xs._0 + _1472_t5), _1472_t7, "tests/integration/slices/slice-literal.orng:10:16:\n        xs[0] + sum(xs[1..])\n              ^");
    goto BB1716;
}


int main(void) {
  printf("%ld",_1470_main());
  return 0;
}
