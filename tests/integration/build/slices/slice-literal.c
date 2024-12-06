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
int64_t _1442_main(void);
int64_t _1444_sum(struct struct1 _1444_xs);


/* Function definitions */
int64_t _1442_main(void){
    function0 _1442_t0;
    int64_t _1442_t4;
    int64_t _1442_t5;
    int64_t _1442_t6;
    struct struct2 _1442_t3;
    int64_t _1442_t7;
    int64_t _1442_t8;
    int64_t* _1442_t9;
    int64_t _1442_t10;
    struct struct1 _1442_t2;
    int64_t _1442_t1;
    int64_t _1442_$retval;
    _1442_t0 = (function0) _1444_sum;
    _1442_t4 = 200;
    _1442_t5 = 0;
    _1442_t6 = 8;
    _1442_t3 = (struct struct2) {_1442_t4, _1442_t5, _1442_t6};
    _1442_t7 = 0;
    _1442_t8 = 3;
    $bounds_check(_1442_t7, _1442_t8, "tests/integration/slices/slice-literal.orng:3:16:\n    sum([](200, 0, 8)) // Slice of product literal\n              ^");
    _1442_t9 = ((int64_t*)&_1442_t3 + _1442_t7);
    _1442_t10 = 3;
    _1442_t2 = (struct struct1) {_1442_t9, _1442_t10};
    $lines[$line_idx++] = "tests/integration/slices/slice-literal.orng:3:9:\n    sum([](200, 0, 8)) // Slice of product literal\n       ^";
    _1442_t1 = _1442_t0(_1442_t2);
    $line_idx--;
    _1442_$retval = _1442_t1;
    return _1442_$retval;
}

int64_t _1444_sum(struct struct1 _1444_xs){
    int64_t _1444_t1;
    uint8_t _1444_t3;
    int64_t _1444_t10;
    int64_t* _1444_t11;
    struct struct1 _1444_t12;
    int64_t _1444_t7;
    int64_t _1444_t0;
    int64_t _1444_$retval;
    int64_t _1444_t5;
    function0 _1444_t6;
    int64_t _1444_t8;
    uint8_t _1444_t9;
    _1444_t1 = 0;
    _1444_t3 = _1444_xs._1==_1444_t1;
    if (_1444_t3) {
        goto BB1684;
    } else {
        goto BB1688;
    }
BB1684:
    _1444_t0 = 0;
    goto BB1687;
BB1688:
    _1444_t5 = 0;
    _1444_t6 = (function0) _1444_sum;
    _1444_t8 = 1;
    _1444_t9 = _1444_t8>_1444_xs._1;
    if (_1444_t9) {
        goto BB1689;
    } else {
        goto BB1690;
    }
BB1687:
    _1444_$retval = _1444_t0;
    return _1444_$retval;
BB1689:
    $lines[$line_idx++] = "tests/integration/slices/slice-literal.orng:10:24:\n        xs[0] + sum(xs[1..])\n                      ^";
    $panic("subslice lower bound is greater than upper bound\n");
BB1690:
    _1444_t10 = $sub_int64_t(_1444_xs._1, _1444_t8, "tests/integration/slices/slice-literal.orng:10:24:\n        xs[0] + sum(xs[1..])\n                      ^");
    _1444_t11 = _1444_xs._0+_1444_t8;
    _1444_t12 = (struct struct1) {_1444_t11, _1444_t10};
    $lines[$line_idx++] = "tests/integration/slices/slice-literal.orng:10:21:\n        xs[0] + sum(xs[1..])\n                   ^";
    _1444_t7 = _1444_t6(_1444_t12);
    $line_idx--;
    $bounds_check(_1444_t5, _1444_xs._1, "tests/integration/slices/slice-literal.orng:10:16:\n        xs[0] + sum(xs[1..])\n              ^");
    _1444_t0 = $add_int64_t(*((int64_t*)_1444_xs._0 + _1444_t5), _1444_t7, "tests/integration/slices/slice-literal.orng:10:16:\n        xs[0] + sum(xs[1..])\n              ^");
    goto BB1687;
}


int main(void) {
  printf("%ld",_1442_main());
  return 0;
}
