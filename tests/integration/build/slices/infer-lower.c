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
int64_t _1409_main(void);
int64_t _1411_sum_up(struct struct1 _1411_xs);


/* Function definitions */
int64_t _1409_main(void){
    int64_t _1409_t1;
    int64_t _1409_t2;
    int64_t _1409_t3;
    int64_t _1409_t4;
    int64_t _1409_t5;
    int64_t _1409_t6;
    struct struct0 _1410_x;
    int64_t _1409_t9;
    int64_t _1409_t10;
    int64_t* _1409_t11;
    int64_t _1409_t12;
    struct struct1 _1410_y;
    int64_t _1409_t17;
    int64_t* _1409_t18;
    struct struct1 _1410_z;
    function2 _1409_t21;
    int64_t _1409_t22;
    int64_t _1409_$retval;
    _1409_t1 = 100;
    _1409_t2 = 8;
    _1409_t3 = 2;
    _1409_t4 = 4;
    _1409_t5 = 35;
    _1409_t6 = 6;
    _1410_x = (struct struct0) {_1409_t1, _1409_t2, _1409_t3, _1409_t4, _1409_t5, _1409_t6};
    _1409_t9 = 0;
    _1409_t10 = 6;
    $bounds_check(_1409_t9, _1409_t10, "tests/integration/slices/infer-lower.orng:4:19:\n    let y = [mut]x\n                 ^");
    _1409_t11 = ((int64_t*)&_1410_x + _1409_t9);
    _1409_t12 = 6;
    _1410_y = (struct struct1) {_1409_t11, _1409_t12};
    _1409_t17 = 3;
    _1409_t18 = _1410_y._0;
    _1410_z = (struct struct1) {_1409_t18, _1409_t17};
    _1409_t21 = (function2) _1411_sum_up;
    $lines[$line_idx++] = "tests/integration/slices/infer-lower.orng:6:12:\n    sum_up(z)\n          ^";
    _1409_t22 = _1409_t21(_1410_z);
    $line_idx--;
    _1409_$retval = _1409_t22;
    return _1409_$retval;
}

int64_t _1411_sum_up(struct struct1 _1411_xs){
    int64_t _1412_sum;
    int64_t _1413_i;
    uint8_t _1411_t5;
    int64_t _1411_t7;
    int64_t _1411_$retval;
    _1412_sum = 0;
    _1413_i = 0;
    goto BB1641;
BB1641:
    _1411_t5 = _1413_i<_1411_xs._1;
    if (_1411_t5) {
        goto BB1642;
    } else {
        goto BB1647;
    }
BB1642:
    $bounds_check(_1413_i, _1411_xs._1, "tests/integration/slices/infer-lower.orng:12:15:\n        sum += xs[i]\n             ^");
    _1412_sum = $add_int64_t(_1412_sum, *((int64_t*)_1411_xs._0 + _1413_i), "tests/integration/slices/infer-lower.orng:12:15:\n        sum += xs[i]\n             ^");
    _1411_t7 = 1;
    _1413_i = $add_int64_t(_1413_i, _1411_t7, "tests/integration/slices/infer-lower.orng:11:50:\n    while let mut i: Int = 0; i < xs.length; i += 1 {\n                                                ^");
    goto BB1641;
BB1647:
    _1411_$retval = _1412_sum;
    return _1411_$retval;
}


int main(void) {
  printf("%ld",_1409_main());
  return 0;
}
