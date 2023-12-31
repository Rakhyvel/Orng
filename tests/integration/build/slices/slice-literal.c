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
int64_t _1330_main(void);
int64_t _1332_sum(struct struct1 _1332_xs);

/* Function definitions */
int64_t _1330_main(void){
    function0 _1330_t0;
    int64_t _1330_t4;
    int64_t _1330_t5;
    int64_t _1330_t6;
    struct struct2 _1330_t3;
    int64_t _1330_t7;
    int64_t _1330_t8;
    int64_t* _1330_t9;
    int64_t _1330_t10;
    struct struct1 _1330_t2;
    int64_t _1330_t1;
    int64_t _1330_$retval;
    _1330_t0 = _1332_sum;
    _1330_t4 = 200;
    _1330_t5 = 0;
    _1330_t6 = 8;
    _1330_t3 = (struct struct2) {_1330_t4, _1330_t5, _1330_t6};
    _1330_t7 = 0;
    _1330_t8 = 3;
    $bounds_check(_1330_t7, _1330_t8, "tests/integration/slices/slice-literal.orng:3:16:\n    sum([](200, 0, 8)) // Slice of product literal\n              ^");
    _1330_t9 = ((int64_t*)&_1330_t3 + _1330_t7);
    _1330_t10 = 3;
    _1330_t2 = (struct struct1) {_1330_t9, _1330_t10};
    $lines[$line_idx++] = "tests/integration/slices/slice-literal.orng:3:9:\n    sum([](200, 0, 8)) // Slice of product literal\n       ^";
    _1330_t1 = _1330_t0(_1330_t2);
    $line_idx--;
    _1330_$retval = _1330_t1;
    return _1330_$retval;
}

int64_t _1332_sum(struct struct1 _1332_xs){
    int64_t _1332_t1;
    uint8_t _1332_t3;
    int64_t _1332_t10;
    int64_t* _1332_t11;
    struct struct1 _1332_t12;
    int64_t _1332_t7;
    int64_t _1332_t0;
    int64_t _1332_$retval;
    int64_t _1332_t5;
    function0 _1332_t6;
    int64_t _1332_t8;
    uint8_t _1332_t9;
    _1332_t1 = 0;
    _1332_t3 = _1332_xs._1==_1332_t1;
    if (_1332_t3) {
        goto BB1613;
    } else {
        goto BB1617;
    }
BB1613:
    _1332_t0 = 0;
    goto BB1616;
BB1617:
    _1332_t5 = 0;
    _1332_t6 = _1332_sum;
    _1332_t8 = 1;
    _1332_t9 = _1332_t8>_1332_xs._1;
    if (_1332_t9) {
        goto BB1618;
    } else {
        goto BB1619;
    }
BB1616:
    _1332_$retval = _1332_t0;
    return _1332_$retval;
BB1618:
    $lines[$line_idx++] = "tests/integration/slices/slice-literal.orng:10:24:\n        xs[0] + sum(xs[1..])\n                      ^";
    $panic("subslice lower bound is greater than upper bound\n");
BB1619:
    _1332_t10 = $sub_int64_t(_1332_xs._1, _1332_t8, "tests/integration/slices/slice-literal.orng:10:24:\n        xs[0] + sum(xs[1..])\n                      ^");
    _1332_t11 = _1332_xs._0+_1332_t8;
    _1332_t12 = (struct struct1) {_1332_t11, _1332_t10};
    $lines[$line_idx++] = "tests/integration/slices/slice-literal.orng:10:21:\n        xs[0] + sum(xs[1..])\n                   ^";
    _1332_t7 = _1332_t6(_1332_t12);
    $line_idx--;
    $bounds_check(_1332_t5, _1332_xs._1, "tests/integration/slices/slice-literal.orng:10:16:\n        xs[0] + sum(xs[1..])\n              ^");
    _1332_t0 = $add_int64_t(*((int64_t*)_1332_xs._0 + _1332_t5), _1332_t7, "tests/integration/slices/slice-literal.orng:10:16:\n        xs[0] + sum(xs[1..])\n              ^");
    goto BB1616;
}

int main(void) {
  printf("%ld",_1330_main());
  return 0;
}
