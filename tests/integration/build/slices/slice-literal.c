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
int64_t _1472_main(void);
int64_t _1474_sum(struct struct1 _1474_xs);


/* Function definitions */
int64_t _1472_main(void){
    function0 _1472_t0;
    int64_t _1472_t4;
    int64_t _1472_t5;
    int64_t _1472_t6;
    struct struct2 _1472_t3;
    int64_t _1472_t7;
    int64_t _1472_t8;
    int64_t* _1472_t9;
    int64_t _1472_t10;
    struct struct1 _1472_t2;
    int64_t _1472_t1;
    int64_t _1472_$retval;
    _1472_t0 = (function0) _1474_sum;
    _1472_t4 = 200;
    _1472_t5 = 0;
    _1472_t6 = 8;
    _1472_t3 = (struct struct2) {_1472_t4, _1472_t5, _1472_t6};
    _1472_t7 = 0;
    _1472_t8 = 3;
    $bounds_check(_1472_t7, _1472_t8, "tests/integration/slices/slice-literal.orng:3:16:\n    sum([](200, 0, 8)) // Slice of product literal\n              ^");
    _1472_t9 = ((int64_t*)&_1472_t3 + _1472_t7);
    _1472_t10 = 3;
    _1472_t2 = (struct struct1) {_1472_t9, _1472_t10};
    $lines[$line_idx++] = "tests/integration/slices/slice-literal.orng:3:9:\n    sum([](200, 0, 8)) // Slice of product literal\n       ^";
    _1472_t1 = _1472_t0(_1472_t2);
    $line_idx--;
    _1472_$retval = _1472_t1;
    return _1472_$retval;
}

int64_t _1474_sum(struct struct1 _1474_xs){
    int64_t _1474_t1;
    uint8_t _1474_t3;
    int64_t _1474_t10;
    int64_t* _1474_t11;
    struct struct1 _1474_t12;
    int64_t _1474_t7;
    int64_t _1474_t0;
    int64_t _1474_$retval;
    int64_t _1474_t5;
    function0 _1474_t6;
    int64_t _1474_t8;
    uint8_t _1474_t9;
    _1474_t1 = 0;
    _1474_t3 = _1474_xs._1==_1474_t1;
    if (_1474_t3) {
        goto BB1715;
    } else {
        goto BB1719;
    }
BB1715:
    _1474_t0 = 0;
    goto BB1718;
BB1719:
    _1474_t5 = 0;
    _1474_t6 = (function0) _1474_sum;
    _1474_t8 = 1;
    _1474_t9 = _1474_t8>_1474_xs._1;
    if (_1474_t9) {
        goto BB1720;
    } else {
        goto BB1721;
    }
BB1718:
    _1474_$retval = _1474_t0;
    return _1474_$retval;
BB1720:
    $lines[$line_idx++] = "tests/integration/slices/slice-literal.orng:10:24:\n        xs[0] + sum(xs[1..])\n                      ^";
    $panic("subslice lower bound is greater than upper bound\n");
BB1721:
    _1474_t10 = $sub_int64_t(_1474_xs._1, _1474_t8, "tests/integration/slices/slice-literal.orng:10:24:\n        xs[0] + sum(xs[1..])\n                      ^");
    _1474_t11 = _1474_xs._0+_1474_t8;
    _1474_t12 = (struct struct1) {_1474_t11, _1474_t10};
    $lines[$line_idx++] = "tests/integration/slices/slice-literal.orng:10:21:\n        xs[0] + sum(xs[1..])\n                   ^";
    _1474_t7 = _1474_t6(_1474_t12);
    $line_idx--;
    $bounds_check(_1474_t5, _1474_xs._1, "tests/integration/slices/slice-literal.orng:10:16:\n        xs[0] + sum(xs[1..])\n              ^");
    _1474_t0 = $add_int64_t(*((int64_t*)_1474_xs._0 + _1474_t5), _1474_t7, "tests/integration/slices/slice-literal.orng:10:16:\n        xs[0] + sum(xs[1..])\n              ^");
    goto BB1718;
}


int main(void) {
  printf("%ld",_1472_main());
  return 0;
}
