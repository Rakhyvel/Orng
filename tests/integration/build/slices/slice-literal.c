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
int64_t _1338_main(void);
int64_t _1340_sum(struct struct1 _1340_xs);

/* Function definitions */
int64_t _1338_main(void){
    function0 _1338_t0;
    int64_t _1338_t4;
    int64_t _1338_t5;
    int64_t _1338_t6;
    struct struct2 _1338_t3;
    int64_t _1338_t7;
    int64_t _1338_t8;
    int64_t* _1338_t9;
    int64_t _1338_t10;
    struct struct1 _1338_t2;
    int64_t _1338_t1;
    int64_t _1338_$retval;
    _1338_t0 = _1340_sum;
    _1338_t4 = 200;
    _1338_t5 = 0;
    _1338_t6 = 8;
    _1338_t3 = (struct struct2) {_1338_t4, _1338_t5, _1338_t6};
    _1338_t7 = 0;
    _1338_t8 = 3;
    $bounds_check(_1338_t7, _1338_t8, "tests/integration/slices/slice-literal.orng:3:16:\n    sum([](200, 0, 8)) // Slice of product literal\n              ^");
    _1338_t9 = ((int64_t*)&_1338_t3 + _1338_t7);
    _1338_t10 = 3;
    _1338_t2 = (struct struct1) {_1338_t9, _1338_t10};
    $lines[$line_idx++] = "tests/integration/slices/slice-literal.orng:3:9:\n    sum([](200, 0, 8)) // Slice of product literal\n       ^";
    _1338_t1 = _1338_t0(_1338_t2);
    $line_idx--;
    _1338_$retval = _1338_t1;
    return _1338_$retval;
}

int64_t _1340_sum(struct struct1 _1340_xs){
    int64_t _1340_t1;
    uint8_t _1340_t3;
    int64_t _1340_t10;
    int64_t* _1340_t11;
    struct struct1 _1340_t12;
    int64_t _1340_t7;
    int64_t _1340_t0;
    int64_t _1340_$retval;
    int64_t _1340_t5;
    function0 _1340_t6;
    int64_t _1340_t8;
    uint8_t _1340_t9;
    _1340_t1 = 0;
    _1340_t3 = _1340_xs._1==_1340_t1;
    if (_1340_t3) {
        goto BB1609;
    } else {
        goto BB1613;
    }
BB1609:
    _1340_t0 = 0;
    goto BB1612;
BB1613:
    _1340_t5 = 0;
    _1340_t6 = _1340_sum;
    _1340_t8 = 1;
    _1340_t9 = _1340_t8>_1340_xs._1;
    if (_1340_t9) {
        goto BB1614;
    } else {
        goto BB1615;
    }
BB1612:
    _1340_$retval = _1340_t0;
    return _1340_$retval;
BB1614:
    $lines[$line_idx++] = "tests/integration/slices/slice-literal.orng:10:24:\n        xs[0] + sum(xs[1..])\n                      ^";
    $panic("subslice lower bound is greater than upper bound\n");
BB1615:
    _1340_t10 = $sub_int64_t(_1340_xs._1, _1340_t8, "tests/integration/slices/slice-literal.orng:10:24:\n        xs[0] + sum(xs[1..])\n                      ^");
    _1340_t11 = _1340_xs._0+_1340_t8;
    _1340_t12 = (struct struct1) {_1340_t11, _1340_t10};
    $lines[$line_idx++] = "tests/integration/slices/slice-literal.orng:10:21:\n        xs[0] + sum(xs[1..])\n                   ^";
    _1340_t7 = _1340_t6(_1340_t12);
    $line_idx--;
    $bounds_check(_1340_t5, _1340_xs._1, "tests/integration/slices/slice-literal.orng:10:16:\n        xs[0] + sum(xs[1..])\n              ^");
    _1340_t0 = $add_int64_t(*((int64_t*)_1340_xs._0 + _1340_t5), _1340_t7, "tests/integration/slices/slice-literal.orng:10:16:\n        xs[0] + sum(xs[1..])\n              ^");
    goto BB1612;
}

int main(void) {
  printf("%ld",_1338_main());
  return 0;
}
