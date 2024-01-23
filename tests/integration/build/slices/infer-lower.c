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
int64_t _1331_main(void);
int64_t _1333_sum_up(struct struct1 _1333_xs);


/* Function definitions */
int64_t _1331_main(void){
    int64_t _1331_t1;
    int64_t _1331_t2;
    int64_t _1331_t3;
    int64_t _1331_t4;
    int64_t _1331_t5;
    int64_t _1331_t6;
    struct struct0 _1332_x;
    int64_t _1331_t8;
    int64_t _1331_t9;
    int64_t* _1331_t10;
    int64_t _1331_t11;
    struct struct1 _1332_y;
    int64_t _1331_t15;
    int64_t* _1331_t16;
    struct struct1 _1332_z;
    function2 _1331_t18;
    int64_t _1331_t19;
    int64_t _1331_$retval;
    _1331_t1 = 100;
    _1331_t2 = 8;
    _1331_t3 = 2;
    _1331_t4 = 4;
    _1331_t5 = 35;
    _1331_t6 = 6;
    _1332_x = (struct struct0) {_1331_t1, _1331_t2, _1331_t3, _1331_t4, _1331_t5, _1331_t6};
    _1331_t8 = 0;
    _1331_t9 = 6;
    $bounds_check(_1331_t8, _1331_t9, "tests/integration/slices/infer-lower.orng:4:19:\n    let y = [mut]x\n                 ^");
    _1331_t10 = ((int64_t*)&_1332_x + _1331_t8);
    _1331_t11 = 6;
    _1332_y = (struct struct1) {_1331_t10, _1331_t11};
    _1331_t15 = 3;
    _1331_t16 = _1332_y._0;
    _1332_z = (struct struct1) {_1331_t16, _1331_t15};
    _1331_t18 = _1333_sum_up;
    $lines[$line_idx++] = "tests/integration/slices/infer-lower.orng:6:12:\n    sum_up(z)\n          ^";
    _1331_t19 = _1331_t18(_1332_z);
    $line_idx--;
    _1331_$retval = _1331_t19;
    return _1331_$retval;
}

int64_t _1333_sum_up(struct struct1 _1333_xs){
    int64_t _1334_sum;
    int64_t _1335_i;
    uint8_t _1333_t3;
    int64_t _1333_t5;
    int64_t _1333_$retval;
    _1334_sum = 0;
    _1335_i = 0;
    goto BB1595;
BB1595:
    _1333_t3 = _1335_i<_1333_xs._1;
    if (_1333_t3) {
        goto BB1596;
    } else {
        goto BB1601;
    }
BB1596:
    $bounds_check(_1335_i, _1333_xs._1, "tests/integration/slices/infer-lower.orng:12:15:\n        sum += xs[i]\n             ^");
    _1334_sum = $add_int64_t(_1334_sum, *((int64_t*)_1333_xs._0 + _1335_i), "tests/integration/slices/infer-lower.orng:12:15:\n        sum += xs[i]\n             ^");
    _1333_t5 = 1;
    _1335_i = $add_int64_t(_1335_i, _1333_t5, "tests/integration/slices/infer-lower.orng:11:50:\n    while let mut i: Int = 0; i < xs.length; i += 1 {\n                                                ^");
    goto BB1595;
BB1601:
    _1333_$retval = _1334_sum;
    return _1333_$retval;
}


int main(void) {
  printf("%ld",_1331_main());
  return 0;
}
