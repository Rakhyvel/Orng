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
int64_t _1404_main(void);
int64_t _1406_sum_up(struct struct1 _1406_xs);


/* Function definitions */
int64_t _1404_main(void){
    int64_t _1404_t1;
    int64_t _1404_t2;
    int64_t _1404_t3;
    int64_t _1404_t4;
    int64_t _1404_t5;
    int64_t _1404_t6;
    struct struct0 _1405_x;
    int64_t _1404_t9;
    int64_t _1404_t10;
    int64_t* _1404_t11;
    int64_t _1404_t12;
    struct struct1 _1405_y;
    int64_t _1404_t17;
    int64_t* _1404_t18;
    struct struct1 _1405_z;
    function2 _1404_t21;
    int64_t _1404_t22;
    int64_t _1404_$retval;
    _1404_t1 = 100;
    _1404_t2 = 8;
    _1404_t3 = 2;
    _1404_t4 = 4;
    _1404_t5 = 35;
    _1404_t6 = 6;
    _1405_x = (struct struct0) {_1404_t1, _1404_t2, _1404_t3, _1404_t4, _1404_t5, _1404_t6};
    _1404_t9 = 0;
    _1404_t10 = 6;
    $bounds_check(_1404_t9, _1404_t10, "tests/integration/slices/infer-lower.orng:4:19:\n    let y = [mut]x\n                 ^");
    _1404_t11 = ((int64_t*)&_1405_x + _1404_t9);
    _1404_t12 = 6;
    _1405_y = (struct struct1) {_1404_t11, _1404_t12};
    _1404_t17 = 3;
    _1404_t18 = _1405_y._0;
    _1405_z = (struct struct1) {_1404_t18, _1404_t17};
    _1404_t21 = (function2) _1406_sum_up;
    $lines[$line_idx++] = "tests/integration/slices/infer-lower.orng:6:12:\n    sum_up(z)\n          ^";
    _1404_t22 = _1404_t21(_1405_z);
    $line_idx--;
    _1404_$retval = _1404_t22;
    return _1404_$retval;
}

int64_t _1406_sum_up(struct struct1 _1406_xs){
    int64_t _1407_sum;
    int64_t _1408_i;
    uint8_t _1406_t5;
    int64_t _1406_t7;
    int64_t _1406_$retval;
    _1407_sum = 0;
    _1408_i = 0;
    goto BB1637;
BB1637:
    _1406_t5 = _1408_i<_1406_xs._1;
    if (_1406_t5) {
        goto BB1638;
    } else {
        goto BB1643;
    }
BB1638:
    $bounds_check(_1408_i, _1406_xs._1, "tests/integration/slices/infer-lower.orng:12:15:\n        sum += xs[i]\n             ^");
    _1407_sum = $add_int64_t(_1407_sum, *((int64_t*)_1406_xs._0 + _1408_i), "tests/integration/slices/infer-lower.orng:12:15:\n        sum += xs[i]\n             ^");
    _1406_t7 = 1;
    _1408_i = $add_int64_t(_1408_i, _1406_t7, "tests/integration/slices/infer-lower.orng:11:50:\n    while let mut i: Int = 0; i < xs.length; i += 1 {\n                                                ^");
    goto BB1637;
BB1643:
    _1406_$retval = _1407_sum;
    return _1406_$retval;
}


int main(void) {
  printf("%ld",_1404_main());
  return 0;
}
