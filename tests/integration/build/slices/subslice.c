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
int64_t _1364_main(void);
int64_t _1366_sum_up(struct struct1 _1366_xs);


/* Function definitions */
int64_t _1364_main(void){
    int64_t _1364_t1;
    int64_t _1364_t2;
    int64_t _1364_t3;
    int64_t _1364_t4;
    int64_t _1364_t5;
    int64_t _1364_t6;
    struct struct0 _1365_x;
    int64_t _1364_t8;
    int64_t _1364_t9;
    int64_t* _1364_t10;
    int64_t _1364_t11;
    struct struct1 _1365_y;
    int64_t _1364_t12;
    int64_t _1364_t15;
    int64_t* _1364_t16;
    struct struct1 _1365_z;
    int64_t _1364_t19;
    function2 _1364_t20;
    int64_t _1364_t21;
    int64_t _1364_$retval;
    _1364_t1 = 1;
    _1364_t2 = 15;
    _1364_t3 = 24;
    _1364_t4 = 4;
    _1364_t5 = 35;
    _1364_t6 = 6;
    _1365_x = (struct struct0) {_1364_t1, _1364_t2, _1364_t3, _1364_t4, _1364_t5, _1364_t6};
    _1364_t8 = 0;
    _1364_t9 = 6;
    $bounds_check(_1364_t8, _1364_t9, "tests/integration/slices/subslice.orng:4:19:\n    let y = [mut]x\n                 ^");
    _1364_t10 = ((int64_t*)&_1365_x + _1364_t8);
    _1364_t11 = 6;
    _1365_y = (struct struct1) {_1364_t10, _1364_t11};
    _1364_t12 = 1;
    _1364_t15 = 4;
    _1364_t16 = _1365_y._0+_1364_t12;
    _1365_z = (struct struct1) {_1364_t16, _1364_t15};
    _1364_t19 = 2;
    $bounds_check(_1364_t19, _1365_z._1, "tests/integration/slices/subslice.orng:6:14:\n    z[2] = 10\n            ^");
    *((int64_t*)_1365_z._0 + _1364_t19) = 10;
    _1364_t20 = _1366_sum_up;
    $lines[$line_idx++] = "tests/integration/slices/subslice.orng:7:12:\n    sum_up(z)\n          ^";
    _1364_t21 = _1364_t20(_1365_z);
    $line_idx--;
    _1364_$retval = _1364_t21;
    return _1364_$retval;
}

int64_t _1366_sum_up(struct struct1 _1366_xs){
    int64_t _1367_sum;
    int64_t _1368_i;
    uint8_t _1366_t3;
    int64_t _1366_t5;
    int64_t _1366_$retval;
    _1367_sum = 0;
    _1368_i = 0;
    goto BB1639;
BB1639:
    _1366_t3 = _1368_i<_1366_xs._1;
    if (_1366_t3) {
        goto BB1640;
    } else {
        goto BB1645;
    }
BB1640:
    $bounds_check(_1368_i, _1366_xs._1, "tests/integration/slices/subslice.orng:13:15:\n        sum += xs[i]\n             ^");
    _1367_sum = $add_int64_t(_1367_sum, *((int64_t*)_1366_xs._0 + _1368_i), "tests/integration/slices/subslice.orng:13:15:\n        sum += xs[i]\n             ^");
    _1366_t5 = 1;
    _1368_i = $add_int64_t(_1368_i, _1366_t5, "tests/integration/slices/subslice.orng:12:50:\n    while let mut i: Int = 0; i < xs.length; i += 1 {\n                                                ^");
    goto BB1639;
BB1645:
    _1366_$retval = _1367_sum;
    return _1366_$retval;
}


int main(void) {
  printf("%ld",_1364_main());
  return 0;
}
