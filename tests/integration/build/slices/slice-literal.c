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
int64_t _1455_main(void);
int64_t _1457_sum(struct struct1 _1457_xs);


/* Function definitions */
int64_t _1455_main(void){
    function0 _1455_t0;
    int64_t _1455_t4;
    int64_t _1455_t5;
    int64_t _1455_t6;
    struct struct2 _1455_t3;
    int64_t _1455_t7;
    int64_t _1455_t8;
    int64_t* _1455_t9;
    int64_t _1455_t10;
    struct struct1 _1455_t2;
    int64_t _1455_t1;
    int64_t _1455_$retval;
    _1455_t0 = (function0) _1457_sum;
    _1455_t4 = 200;
    _1455_t5 = 0;
    _1455_t6 = 8;
    _1455_t3 = (struct struct2) {_1455_t4, _1455_t5, _1455_t6};
    _1455_t7 = 0;
    _1455_t8 = 3;
    $bounds_check(_1455_t7, _1455_t8, "tests/integration/slices/slice-literal.orng:3:16:\n    sum([](200, 0, 8)) // Slice of product literal\n              ^");
    _1455_t9 = ((int64_t*)&_1455_t3 + _1455_t7);
    _1455_t10 = 3;
    _1455_t2 = (struct struct1) {_1455_t9, _1455_t10};
    $lines[$line_idx++] = "tests/integration/slices/slice-literal.orng:3:9:\n    sum([](200, 0, 8)) // Slice of product literal\n       ^";
    _1455_t1 = _1455_t0(_1455_t2);
    $line_idx--;
    _1455_$retval = _1455_t1;
    return _1455_$retval;
}

int64_t _1457_sum(struct struct1 _1457_xs){
    int64_t _1457_t1;
    uint8_t _1457_t3;
    int64_t _1457_t10;
    int64_t* _1457_t11;
    struct struct1 _1457_t12;
    int64_t _1457_t7;
    int64_t _1457_t0;
    int64_t _1457_$retval;
    int64_t _1457_t5;
    function0 _1457_t6;
    int64_t _1457_t8;
    uint8_t _1457_t9;
    _1457_t1 = 0;
    _1457_t3 = _1457_xs._1==_1457_t1;
    if (_1457_t3) {
        goto BB1697;
    } else {
        goto BB1701;
    }
BB1697:
    _1457_t0 = 0;
    goto BB1700;
BB1701:
    _1457_t5 = 0;
    _1457_t6 = (function0) _1457_sum;
    _1457_t8 = 1;
    _1457_t9 = _1457_t8>_1457_xs._1;
    if (_1457_t9) {
        goto BB1702;
    } else {
        goto BB1703;
    }
BB1700:
    _1457_$retval = _1457_t0;
    return _1457_$retval;
BB1702:
    $lines[$line_idx++] = "tests/integration/slices/slice-literal.orng:10:24:\n        xs[0] + sum(xs[1..])\n                      ^";
    $panic("subslice lower bound is greater than upper bound\n");
BB1703:
    _1457_t10 = $sub_int64_t(_1457_xs._1, _1457_t8, "tests/integration/slices/slice-literal.orng:10:24:\n        xs[0] + sum(xs[1..])\n                      ^");
    _1457_t11 = _1457_xs._0+_1457_t8;
    _1457_t12 = (struct struct1) {_1457_t11, _1457_t10};
    $lines[$line_idx++] = "tests/integration/slices/slice-literal.orng:10:21:\n        xs[0] + sum(xs[1..])\n                   ^";
    _1457_t7 = _1457_t6(_1457_t12);
    $line_idx--;
    $bounds_check(_1457_t5, _1457_xs._1, "tests/integration/slices/slice-literal.orng:10:16:\n        xs[0] + sum(xs[1..])\n              ^");
    _1457_t0 = $add_int64_t(*((int64_t*)_1457_xs._0 + _1457_t5), _1457_t7, "tests/integration/slices/slice-literal.orng:10:16:\n        xs[0] + sum(xs[1..])\n              ^");
    goto BB1700;
}


int main(void) {
  printf("%ld",_1455_main());
  return 0;
}
