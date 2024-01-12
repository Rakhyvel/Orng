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
int64_t _1348_main(void);
int64_t _1350_sum(struct struct1 _1350_xs);

/* Function definitions */
int64_t _1348_main(void){
    function0 _1348_t0;
    int64_t _1348_t4;
    int64_t _1348_t5;
    int64_t _1348_t6;
    struct struct2 _1348_t3;
    int64_t _1348_t7;
    int64_t _1348_t8;
    int64_t* _1348_t9;
    int64_t _1348_t10;
    struct struct1 _1348_t2;
    int64_t _1348_t1;
    int64_t _1348_$retval;
    _1348_t0 = _1350_sum;
    _1348_t4 = 200;
    _1348_t5 = 0;
    _1348_t6 = 8;
    _1348_t3 = (struct struct2) {_1348_t4, _1348_t5, _1348_t6};
    _1348_t7 = 0;
    _1348_t8 = 3;
    $bounds_check(_1348_t7, _1348_t8, "tests/integration/slices/slice-literal.orng:3:16:\n    sum([](200, 0, 8)) // Slice of product literal\n              ^");
    _1348_t9 = ((int64_t*)&_1348_t3 + _1348_t7);
    _1348_t10 = 3;
    _1348_t2 = (struct struct1) {_1348_t9, _1348_t10};
    $lines[$line_idx++] = "tests/integration/slices/slice-literal.orng:3:9:\n    sum([](200, 0, 8)) // Slice of product literal\n       ^";
    _1348_t1 = _1348_t0(_1348_t2);
    $line_idx--;
    _1348_$retval = _1348_t1;
    return _1348_$retval;
}

int64_t _1350_sum(struct struct1 _1350_xs){
    int64_t _1350_t1;
    uint8_t _1350_t3;
    int64_t _1350_t10;
    int64_t* _1350_t11;
    struct struct1 _1350_t12;
    int64_t _1350_t7;
    int64_t _1350_t0;
    int64_t _1350_$retval;
    int64_t _1350_t5;
    function0 _1350_t6;
    int64_t _1350_t8;
    uint8_t _1350_t9;
    _1350_t1 = 0;
    _1350_t3 = _1350_xs._1==_1350_t1;
    if (_1350_t3) {
        goto BB1621;
    } else {
        goto BB1625;
    }
BB1621:
    _1350_t0 = 0;
    goto BB1624;
BB1625:
    _1350_t5 = 0;
    _1350_t6 = _1350_sum;
    _1350_t8 = 1;
    _1350_t9 = _1350_t8>_1350_xs._1;
    if (_1350_t9) {
        goto BB1626;
    } else {
        goto BB1627;
    }
BB1624:
    _1350_$retval = _1350_t0;
    return _1350_$retval;
BB1626:
    $lines[$line_idx++] = "tests/integration/slices/slice-literal.orng:10:24:\n        xs[0] + sum(xs[1..])\n                      ^";
    $panic("subslice lower bound is greater than upper bound\n");
BB1627:
    _1350_t10 = $sub_int64_t(_1350_xs._1, _1350_t8, "tests/integration/slices/slice-literal.orng:10:24:\n        xs[0] + sum(xs[1..])\n                      ^");
    _1350_t11 = _1350_xs._0+_1350_t8;
    _1350_t12 = (struct struct1) {_1350_t11, _1350_t10};
    $lines[$line_idx++] = "tests/integration/slices/slice-literal.orng:10:21:\n        xs[0] + sum(xs[1..])\n                   ^";
    _1350_t7 = _1350_t6(_1350_t12);
    $line_idx--;
    $bounds_check(_1350_t5, _1350_xs._1, "tests/integration/slices/slice-literal.orng:10:16:\n        xs[0] + sum(xs[1..])\n              ^");
    _1350_t0 = $add_int64_t(*((int64_t*)_1350_xs._0 + _1350_t5), _1350_t7, "tests/integration/slices/slice-literal.orng:10:16:\n        xs[0] + sum(xs[1..])\n              ^");
    goto BB1624;
}

int main(void) {
  printf("%ld",_1348_main());
  return 0;
}
