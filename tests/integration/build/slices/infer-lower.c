/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward struct, union, and function declarations */
struct struct0;
struct struct1;

/* Struct, union, and function definitions */
struct struct0 {
    int64_t _0;
    int64_t _1;
    int64_t _2;
    int64_t _3;
    int64_t _4;
    int64_t _5;
};

struct struct1 {
    int64_t* _0;
    int64_t _1;
};

typedef int64_t(*function2)(struct struct1);

/* Function forward definitions */
int64_t _1448_main(void);
int64_t _1450_sum_up(struct struct1 _1450_xs);


/* Function definitions */
int64_t _1448_main(void){
    int64_t _1448_t1;
    int64_t _1448_t2;
    int64_t _1448_t3;
    int64_t _1448_t4;
    int64_t _1448_t5;
    int64_t _1448_t6;
    struct struct0 _1449_x;
    int64_t _1448_t9;
    int64_t _1448_t10;
    int64_t* _1448_t11;
    int64_t _1448_t12;
    struct struct1 _1449_y;
    int64_t _1448_t17;
    int64_t* _1448_t18;
    struct struct1 _1449_z;
    function2 _1448_t21;
    int64_t _1448_t22;
    int64_t _1448_$retval;
    _1448_t1 = 100;
    _1448_t2 = 8;
    _1448_t3 = 2;
    _1448_t4 = 4;
    _1448_t5 = 35;
    _1448_t6 = 6;
    _1449_x = (struct struct0) {_1448_t1, _1448_t2, _1448_t3, _1448_t4, _1448_t5, _1448_t6};
    _1448_t9 = 0;
    _1448_t10 = 6;
    $bounds_check(_1448_t9, _1448_t10, "tests/integration/slices/infer-lower.orng:4:19:\n    let y = [mut]x\n                 ^");
    _1448_t11 = ((int64_t*)&_1449_x + _1448_t9);
    _1448_t12 = 6;
    _1449_y = (struct struct1) {_1448_t11, _1448_t12};
    _1448_t17 = 3;
    _1448_t18 = _1449_y._0;
    _1449_z = (struct struct1) {_1448_t18, _1448_t17};
    _1448_t21 = (function2) _1450_sum_up;
    $lines[$line_idx++] = "tests/integration/slices/infer-lower.orng:6:12:\n    sum_up(z)\n          ^";
    _1448_t22 = _1448_t21(_1449_z);
    $line_idx--;
    _1448_$retval = _1448_t22;
    return _1448_$retval;
}

int64_t _1450_sum_up(struct struct1 _1450_xs){
    int64_t _1451_sum;
    int64_t _1452_i;
    uint8_t _1450_t5;
    int64_t _1450_t7;
    int64_t _1450_$retval;
    _1451_sum = 0;
    _1452_i = 0;
    goto BB1683;
BB1683:
    _1450_t5 = _1452_i<_1450_xs._1;
    if (_1450_t5) {
        goto BB1684;
    } else {
        goto BB1689;
    }
BB1684:
    $bounds_check(_1452_i, _1450_xs._1, "tests/integration/slices/infer-lower.orng:12:15:\n        sum += xs[i]\n             ^");
    _1451_sum = $add_int64_t(_1451_sum, *((int64_t*)_1450_xs._0 + _1452_i), "tests/integration/slices/infer-lower.orng:12:15:\n        sum += xs[i]\n             ^");
    _1450_t7 = 1;
    _1452_i = $add_int64_t(_1452_i, _1450_t7, "tests/integration/slices/infer-lower.orng:11:50:\n    while let mut i: Int = 0; i < xs.length; i += 1 {\n                                                ^");
    goto BB1683;
BB1689:
    _1450_$retval = _1451_sum;
    return _1450_$retval;
}


int main(void) {
  printf("%ld",_1448_main());
  return 0;
}
