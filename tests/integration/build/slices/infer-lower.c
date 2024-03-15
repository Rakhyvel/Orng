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
int64_t _1327_main(void);
int64_t _1329_sum_up(struct struct1 _1329_xs);


/* Function definitions */
int64_t _1327_main(void){
    int64_t _1327_t1;
    int64_t _1327_t2;
    int64_t _1327_t3;
    int64_t _1327_t4;
    int64_t _1327_t5;
    int64_t _1327_t6;
    struct struct0 _1328_x;
    int64_t _1327_t9;
    int64_t _1327_t10;
    int64_t* _1327_t11;
    int64_t _1327_t12;
    struct struct1 _1328_y;
    int64_t _1327_t17;
    int64_t* _1327_t18;
    struct struct1 _1328_z;
    function2 _1327_t21;
    int64_t _1327_t22;
    int64_t _1327_$retval;
    _1327_t1 = 100;
    _1327_t2 = 8;
    _1327_t3 = 2;
    _1327_t4 = 4;
    _1327_t5 = 35;
    _1327_t6 = 6;
    _1328_x = (struct struct0) {_1327_t1, _1327_t2, _1327_t3, _1327_t4, _1327_t5, _1327_t6};
    _1327_t9 = 0;
    _1327_t10 = 6;
    $bounds_check(_1327_t9, _1327_t10, "tests/integration/slices/infer-lower.orng:4:19:\n    let y = [mut]x\n                 ^");
    _1327_t11 = ((int64_t*)&_1328_x + _1327_t9);
    _1327_t12 = 6;
    _1328_y = (struct struct1) {_1327_t11, _1327_t12};
    _1327_t17 = 3;
    _1327_t18 = _1328_y._0;
    _1328_z = (struct struct1) {_1327_t18, _1327_t17};
    _1327_t21 = (function2) _1329_sum_up;
    $lines[$line_idx++] = "tests/integration/slices/infer-lower.orng:6:12:\n    sum_up(z)\n          ^";
    _1327_t22 = _1327_t21(_1328_z);
    $line_idx--;
    _1327_$retval = _1327_t22;
    return _1327_$retval;
}

int64_t _1329_sum_up(struct struct1 _1329_xs){
    int64_t _1330_sum;
    int64_t _1331_i;
    uint8_t _1329_t5;
    int64_t _1329_t7;
    int64_t _1329_$retval;
    _1330_sum = 0;
    _1331_i = 0;
    goto BB1558;
BB1558:
    _1329_t5 = _1331_i<_1329_xs._1;
    if (_1329_t5) {
        goto BB1559;
    } else {
        goto BB1564;
    }
BB1559:
    $bounds_check(_1331_i, _1329_xs._1, "tests/integration/slices/infer-lower.orng:12:15:\n        sum += xs[i]\n             ^");
    _1330_sum = $add_int64_t(_1330_sum, *((int64_t*)_1329_xs._0 + _1331_i), "tests/integration/slices/infer-lower.orng:12:15:\n        sum += xs[i]\n             ^");
    _1329_t7 = 1;
    _1331_i = $add_int64_t(_1331_i, _1329_t7, "tests/integration/slices/infer-lower.orng:11:50:\n    while let mut i: Int = 0; i < xs.length; i += 1 {\n                                                ^");
    goto BB1558;
BB1564:
    _1329_$retval = _1330_sum;
    return _1329_$retval;
}


int main(void) {
  printf("%ld",_1327_main());
  return 0;
}
