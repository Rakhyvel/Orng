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
int64_t _1421_main(void);
int64_t _1423_sum(struct struct1 _1423_xs);


/* Function definitions */
int64_t _1421_main(void){
    function0 _1421_t0;
    int64_t _1421_t4;
    int64_t _1421_t5;
    int64_t _1421_t6;
    struct struct2 _1421_t3;
    int64_t _1421_t7;
    int64_t _1421_t8;
    int64_t* _1421_t9;
    int64_t _1421_t10;
    struct struct1 _1421_t2;
    int64_t _1421_t1;
    int64_t _1421_$retval;
    _1421_t0 = (function0) _1423_sum;
    _1421_t4 = 200;
    _1421_t5 = 0;
    _1421_t6 = 8;
    _1421_t3 = (struct struct2) {_1421_t4, _1421_t5, _1421_t6};
    _1421_t7 = 0;
    _1421_t8 = 3;
    $bounds_check(_1421_t7, _1421_t8, "tests/integration/slices/slice-literal.orng:3:16:\n    sum([](200, 0, 8)) // Slice of product literal\n              ^");
    _1421_t9 = ((int64_t*)&_1421_t3 + _1421_t7);
    _1421_t10 = 3;
    _1421_t2 = (struct struct1) {_1421_t9, _1421_t10};
    $lines[$line_idx++] = "tests/integration/slices/slice-literal.orng:3:9:\n    sum([](200, 0, 8)) // Slice of product literal\n       ^";
    _1421_t1 = _1421_t0(_1421_t2);
    $line_idx--;
    _1421_$retval = _1421_t1;
    return _1421_$retval;
}

int64_t _1423_sum(struct struct1 _1423_xs){
    int64_t _1423_t1;
    uint8_t _1423_t3;
    int64_t _1423_t10;
    int64_t* _1423_t11;
    struct struct1 _1423_t12;
    int64_t _1423_t7;
    int64_t _1423_t0;
    int64_t _1423_$retval;
    int64_t _1423_t5;
    function0 _1423_t6;
    int64_t _1423_t8;
    uint8_t _1423_t9;
    _1423_t1 = 0;
    _1423_t3 = _1423_xs._1==_1423_t1;
    if (_1423_t3) {
        goto BB1667;
    } else {
        goto BB1671;
    }
BB1667:
    _1423_t0 = 0;
    goto BB1670;
BB1671:
    _1423_t5 = 0;
    _1423_t6 = (function0) _1423_sum;
    _1423_t8 = 1;
    _1423_t9 = _1423_t8>_1423_xs._1;
    if (_1423_t9) {
        goto BB1672;
    } else {
        goto BB1673;
    }
BB1670:
    _1423_$retval = _1423_t0;
    return _1423_$retval;
BB1672:
    $lines[$line_idx++] = "tests/integration/slices/slice-literal.orng:10:24:\n        xs[0] + sum(xs[1..])\n                      ^";
    $panic("subslice lower bound is greater than upper bound\n");
BB1673:
    _1423_t10 = $sub_int64_t(_1423_xs._1, _1423_t8, "tests/integration/slices/slice-literal.orng:10:24:\n        xs[0] + sum(xs[1..])\n                      ^");
    _1423_t11 = _1423_xs._0+_1423_t8;
    _1423_t12 = (struct struct1) {_1423_t11, _1423_t10};
    $lines[$line_idx++] = "tests/integration/slices/slice-literal.orng:10:21:\n        xs[0] + sum(xs[1..])\n                   ^";
    _1423_t7 = _1423_t6(_1423_t12);
    $line_idx--;
    $bounds_check(_1423_t5, _1423_xs._1, "tests/integration/slices/slice-literal.orng:10:16:\n        xs[0] + sum(xs[1..])\n              ^");
    _1423_t0 = $add_int64_t(*((int64_t*)_1423_xs._0 + _1423_t5), _1423_t7, "tests/integration/slices/slice-literal.orng:10:16:\n        xs[0] + sum(xs[1..])\n              ^");
    goto BB1670;
}


int main(void) {
  printf("%ld",_1421_main());
  return 0;
}
