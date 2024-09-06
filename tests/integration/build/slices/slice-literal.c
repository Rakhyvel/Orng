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
int64_t _1428_main(void);
int64_t _1430_sum(struct struct1 _1430_xs);


/* Function definitions */
int64_t _1428_main(void){
    function0 _1428_t0;
    int64_t _1428_t4;
    int64_t _1428_t5;
    int64_t _1428_t6;
    struct struct2 _1428_t3;
    int64_t _1428_t7;
    int64_t _1428_t8;
    int64_t* _1428_t9;
    int64_t _1428_t10;
    struct struct1 _1428_t2;
    int64_t _1428_t1;
    int64_t _1428_$retval;
    _1428_t0 = (function0) _1430_sum;
    _1428_t4 = 200;
    _1428_t5 = 0;
    _1428_t6 = 8;
    _1428_t3 = (struct struct2) {_1428_t4, _1428_t5, _1428_t6};
    _1428_t7 = 0;
    _1428_t8 = 3;
    $bounds_check(_1428_t7, _1428_t8, "tests/integration/slices/slice-literal.orng:3:16:\n    sum([](200, 0, 8)) // Slice of product literal\n              ^");
    _1428_t9 = ((int64_t*)&_1428_t3 + _1428_t7);
    _1428_t10 = 3;
    _1428_t2 = (struct struct1) {_1428_t9, _1428_t10};
    $lines[$line_idx++] = "tests/integration/slices/slice-literal.orng:3:9:\n    sum([](200, 0, 8)) // Slice of product literal\n       ^";
    _1428_t1 = _1428_t0(_1428_t2);
    $line_idx--;
    _1428_$retval = _1428_t1;
    return _1428_$retval;
}

int64_t _1430_sum(struct struct1 _1430_xs){
    int64_t _1430_t1;
    uint8_t _1430_t3;
    int64_t _1430_t10;
    int64_t* _1430_t11;
    struct struct1 _1430_t12;
    int64_t _1430_t7;
    int64_t _1430_t0;
    int64_t _1430_$retval;
    int64_t _1430_t5;
    function0 _1430_t6;
    int64_t _1430_t8;
    uint8_t _1430_t9;
    _1430_t1 = 0;
    _1430_t3 = _1430_xs._1==_1430_t1;
    if (_1430_t3) {
        goto BB1669;
    } else {
        goto BB1673;
    }
BB1669:
    _1430_t0 = 0;
    goto BB1672;
BB1673:
    _1430_t5 = 0;
    _1430_t6 = (function0) _1430_sum;
    _1430_t8 = 1;
    _1430_t9 = _1430_t8>_1430_xs._1;
    if (_1430_t9) {
        goto BB1674;
    } else {
        goto BB1675;
    }
BB1672:
    _1430_$retval = _1430_t0;
    return _1430_$retval;
BB1674:
    $lines[$line_idx++] = "tests/integration/slices/slice-literal.orng:10:24:\n        xs[0] + sum(xs[1..])\n                      ^";
    $panic("subslice lower bound is greater than upper bound\n");
BB1675:
    _1430_t10 = $sub_int64_t(_1430_xs._1, _1430_t8, "tests/integration/slices/slice-literal.orng:10:24:\n        xs[0] + sum(xs[1..])\n                      ^");
    _1430_t11 = _1430_xs._0+_1430_t8;
    _1430_t12 = (struct struct1) {_1430_t11, _1430_t10};
    $lines[$line_idx++] = "tests/integration/slices/slice-literal.orng:10:21:\n        xs[0] + sum(xs[1..])\n                   ^";
    _1430_t7 = _1430_t6(_1430_t12);
    $line_idx--;
    $bounds_check(_1430_t5, _1430_xs._1, "tests/integration/slices/slice-literal.orng:10:16:\n        xs[0] + sum(xs[1..])\n              ^");
    _1430_t0 = $add_int64_t(*((int64_t*)_1430_xs._0 + _1430_t5), _1430_t7, "tests/integration/slices/slice-literal.orng:10:16:\n        xs[0] + sum(xs[1..])\n              ^");
    goto BB1672;
}


int main(void) {
  printf("%ld",_1428_main());
  return 0;
}
