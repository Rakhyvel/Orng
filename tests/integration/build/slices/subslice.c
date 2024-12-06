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
int64_t _1461_main(void);
int64_t _1463_sum_up(struct struct1 _1463_xs);


/* Function definitions */
int64_t _1461_main(void){
    int64_t _1461_t1;
    int64_t _1461_t2;
    int64_t _1461_t3;
    int64_t _1461_t4;
    int64_t _1461_t5;
    int64_t _1461_t6;
    struct struct0 _1462_x;
    int64_t _1461_t9;
    int64_t _1461_t10;
    int64_t* _1461_t11;
    int64_t _1461_t12;
    struct struct1 _1462_y;
    int64_t _1461_t14;
    int64_t _1461_t17;
    int64_t* _1461_t18;
    struct struct1 _1462_z;
    int64_t _1461_t22;
    function2 _1461_t23;
    int64_t _1461_t24;
    int64_t _1461_$retval;
    _1461_t1 = 1;
    _1461_t2 = 15;
    _1461_t3 = 24;
    _1461_t4 = 4;
    _1461_t5 = 35;
    _1461_t6 = 6;
    _1462_x = (struct struct0) {_1461_t1, _1461_t2, _1461_t3, _1461_t4, _1461_t5, _1461_t6};
    _1461_t9 = 0;
    _1461_t10 = 6;
    $bounds_check(_1461_t9, _1461_t10, "tests/integration/slices/subslice.orng:4:19:\n    let y = [mut]x\n                 ^");
    _1461_t11 = ((int64_t*)&_1462_x + _1461_t9);
    _1461_t12 = 6;
    _1462_y = (struct struct1) {_1461_t11, _1461_t12};
    _1461_t14 = 1;
    _1461_t17 = 4;
    _1461_t18 = _1462_y._0+_1461_t14;
    _1462_z = (struct struct1) {_1461_t18, _1461_t17};
    _1461_t22 = 2;
    $bounds_check(_1461_t22, _1462_z._1, "tests/integration/slices/subslice.orng:6:14:\n    z[2] = 10\n            ^");
    *((int64_t*)_1462_z._0 + _1461_t22) = 10;
    _1461_t23 = (function2) _1463_sum_up;
    $lines[$line_idx++] = "tests/integration/slices/subslice.orng:7:12:\n    sum_up(z)\n          ^";
    _1461_t24 = _1461_t23(_1462_z);
    $line_idx--;
    _1461_$retval = _1461_t24;
    return _1461_$retval;
}

int64_t _1463_sum_up(struct struct1 _1463_xs){
    int64_t _1464_sum;
    int64_t _1465_i;
    uint8_t _1463_t5;
    int64_t _1463_t7;
    int64_t _1463_$retval;
    _1464_sum = 0;
    _1465_i = 0;
    goto BB1708;
BB1708:
    _1463_t5 = _1465_i<_1463_xs._1;
    if (_1463_t5) {
        goto BB1709;
    } else {
        goto BB1714;
    }
BB1709:
    $bounds_check(_1465_i, _1463_xs._1, "tests/integration/slices/subslice.orng:13:15:\n        sum += xs[i]\n             ^");
    _1464_sum = $add_int64_t(_1464_sum, *((int64_t*)_1463_xs._0 + _1465_i), "tests/integration/slices/subslice.orng:13:15:\n        sum += xs[i]\n             ^");
    _1463_t7 = 1;
    _1465_i = $add_int64_t(_1465_i, _1463_t7, "tests/integration/slices/subslice.orng:12:50:\n    while let mut i: Int = 0; i < xs.length; i += 1 {\n                                                ^");
    goto BB1708;
BB1714:
    _1463_$retval = _1464_sum;
    return _1463_$retval;
}


int main(void) {
  printf("%ld",_1461_main());
  return 0;
}
