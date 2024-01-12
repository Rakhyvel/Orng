/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward typedefs */
struct struct0;
struct struct1;

/* Typedefs */
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
int64_t _1326_main(void);
int64_t _1328_sum_up(struct struct1 _1328_xs);

/* Function definitions */
int64_t _1326_main(void){
    int64_t _1326_t1;
    int64_t _1326_t2;
    int64_t _1326_t3;
    int64_t _1326_t4;
    int64_t _1326_t5;
    int64_t _1326_t6;
    struct struct0 _1327_x;
    int64_t _1326_t8;
    int64_t _1326_t9;
    int64_t* _1326_t10;
    int64_t _1326_t11;
    struct struct1 _1327_y;
    int64_t _1326_t15;
    int64_t* _1326_t16;
    struct struct1 _1327_z;
    function2 _1326_t18;
    int64_t _1326_t19;
    int64_t _1326_$retval;
    _1326_t1 = 100;
    _1326_t2 = 8;
    _1326_t3 = 2;
    _1326_t4 = 4;
    _1326_t5 = 35;
    _1326_t6 = 6;
    _1327_x = (struct struct0) {_1326_t1, _1326_t2, _1326_t3, _1326_t4, _1326_t5, _1326_t6};
    _1326_t8 = 0;
    _1326_t9 = 6;
    $bounds_check(_1326_t8, _1326_t9, "tests/integration/slices/infer-lower.orng:4:19:\n    let y = [mut]x\n                 ^");
    _1326_t10 = ((int64_t*)&_1327_x + _1326_t8);
    _1326_t11 = 6;
    _1327_y = (struct struct1) {_1326_t10, _1326_t11};
    _1326_t15 = 3;
    _1326_t16 = _1327_y._0;
    _1327_z = (struct struct1) {_1326_t16, _1326_t15};
    _1326_t18 = _1328_sum_up;
    $lines[$line_idx++] = "tests/integration/slices/infer-lower.orng:6:12:\n    sum_up(z)\n          ^";
    _1326_t19 = _1326_t18(_1327_z);
    $line_idx--;
    _1326_$retval = _1326_t19;
    return _1326_$retval;
}

int64_t _1328_sum_up(struct struct1 _1328_xs){
    int64_t _1329_sum;
    int64_t _1330_i;
    uint8_t _1328_t3;
    int64_t _1328_t5;
    int64_t _1328_$retval;
    _1329_sum = 0;
    _1330_i = 0;
    goto BB1591;
BB1591:
    _1328_t3 = _1330_i<_1328_xs._1;
    if (_1328_t3) {
        goto BB1592;
    } else {
        goto BB1597;
    }
BB1592:
    $bounds_check(_1330_i, _1328_xs._1, "tests/integration/slices/infer-lower.orng:12:15:\n        sum += xs[i]\n             ^");
    _1329_sum = $add_int64_t(_1329_sum, *((int64_t*)_1328_xs._0 + _1330_i), "tests/integration/slices/infer-lower.orng:12:15:\n        sum += xs[i]\n             ^");
    _1328_t5 = 1;
    _1330_i = $add_int64_t(_1330_i, _1328_t5, "tests/integration/slices/infer-lower.orng:11:50:\n    while let mut i: Int = 0; i < xs.length; i += 1 {\n                                                ^");
    goto BB1591;
BB1597:
    _1328_$retval = _1329_sum;
    return _1328_$retval;
}

int main(void) {
  printf("%ld",_1326_main());
  return 0;
}
