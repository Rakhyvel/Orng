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
int64_t _1406_main(void);
int64_t _1408_sum_up(struct struct1 _1408_xs);


/* Function definitions */
int64_t _1406_main(void){
    int64_t _1406_t1;
    int64_t _1406_t2;
    int64_t _1406_t3;
    int64_t _1406_t4;
    int64_t _1406_t5;
    int64_t _1406_t6;
    struct struct0 _1407_x;
    int64_t _1406_t9;
    int64_t _1406_t10;
    int64_t* _1406_t11;
    int64_t _1406_t12;
    struct struct1 _1407_y;
    int64_t _1406_t17;
    int64_t* _1406_t18;
    struct struct1 _1407_z;
    function2 _1406_t21;
    int64_t _1406_t22;
    int64_t _1406_$retval;
    _1406_t1 = 100;
    _1406_t2 = 8;
    _1406_t3 = 2;
    _1406_t4 = 4;
    _1406_t5 = 35;
    _1406_t6 = 6;
    _1407_x = (struct struct0) {_1406_t1, _1406_t2, _1406_t3, _1406_t4, _1406_t5, _1406_t6};
    _1406_t9 = 0;
    _1406_t10 = 6;
    $bounds_check(_1406_t9, _1406_t10, "tests/integration/slices/infer-lower.orng:4:19:\n    let y = [mut]x\n                 ^");
    _1406_t11 = ((int64_t*)&_1407_x + _1406_t9);
    _1406_t12 = 6;
    _1407_y = (struct struct1) {_1406_t11, _1406_t12};
    _1406_t17 = 3;
    _1406_t18 = _1407_y._0;
    _1407_z = (struct struct1) {_1406_t18, _1406_t17};
    _1406_t21 = (function2) _1408_sum_up;
    $lines[$line_idx++] = "tests/integration/slices/infer-lower.orng:6:12:\n    sum_up(z)\n          ^";
    _1406_t22 = _1406_t21(_1407_z);
    $line_idx--;
    _1406_$retval = _1406_t22;
    return _1406_$retval;
}

int64_t _1408_sum_up(struct struct1 _1408_xs){
    int64_t _1409_sum;
    int64_t _1410_i;
    uint8_t _1408_t5;
    int64_t _1408_t7;
    int64_t _1408_$retval;
    _1409_sum = 0;
    _1410_i = 0;
    goto BB1639;
BB1639:
    _1408_t5 = _1410_i<_1408_xs._1;
    if (_1408_t5) {
        goto BB1640;
    } else {
        goto BB1645;
    }
BB1640:
    $bounds_check(_1410_i, _1408_xs._1, "tests/integration/slices/infer-lower.orng:12:15:\n        sum += xs[i]\n             ^");
    _1409_sum = $add_int64_t(_1409_sum, *((int64_t*)_1408_xs._0 + _1410_i), "tests/integration/slices/infer-lower.orng:12:15:\n        sum += xs[i]\n             ^");
    _1408_t7 = 1;
    _1410_i = $add_int64_t(_1410_i, _1408_t7, "tests/integration/slices/infer-lower.orng:11:50:\n    while let mut i: Int = 0; i < xs.length; i += 1 {\n                                                ^");
    goto BB1639;
BB1645:
    _1408_$retval = _1409_sum;
    return _1408_$retval;
}


int main(void) {
  printf("%ld",_1406_main());
  return 0;
}
