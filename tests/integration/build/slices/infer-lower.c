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
int64_t _1311_main(void);
int64_t _1313_sum_up(struct struct1 _1313_xs);

/* Function definitions */
int64_t _1311_main(void){
    int64_t _1311_t1;
    int64_t _1311_t2;
    int64_t _1311_t3;
    int64_t _1311_t4;
    int64_t _1311_t5;
    int64_t _1311_t6;
    struct struct0 _1312_x;
    int64_t _1311_t8;
    int64_t _1311_t9;
    int64_t* _1311_t10;
    int64_t _1311_t11;
    struct struct1 _1312_y;
    int64_t _1311_t15;
    int64_t* _1311_t16;
    struct struct1 _1312_z;
    function2 _1311_t18;
    int64_t _1311_t19;
    int64_t _1311_$retval;
    _1311_t1 = 100;
    _1311_t2 = 8;
    _1311_t3 = 2;
    _1311_t4 = 4;
    _1311_t5 = 35;
    _1311_t6 = 6;
    _1312_x = (struct struct0) {_1311_t1, _1311_t2, _1311_t3, _1311_t4, _1311_t5, _1311_t6};
    _1311_t8 = 0;
    _1311_t9 = 6;
    $bounds_check(_1311_t8, _1311_t9, "tests/integration/slices/infer-lower.orng:4:19:\n    let y = [mut]x\n                 ^");
    _1311_t10 = ((int64_t*)&_1312_x + _1311_t8);
    _1311_t11 = 6;
    _1312_y = (struct struct1) {_1311_t10, _1311_t11};
    _1311_t15 = 3;
    _1311_t16 = _1312_y._0;
    _1312_z = (struct struct1) {_1311_t16, _1311_t15};
    _1311_t18 = _1313_sum_up;
    $lines[$line_idx++] = "tests/integration/slices/infer-lower.orng:6:12:\n    sum_up(z)\n          ^";
    _1311_t19 = _1311_t18(_1312_z);
    $line_idx--;
    _1311_$retval = _1311_t19;
    return _1311_$retval;
}

int64_t _1313_sum_up(struct struct1 _1313_xs){
    int64_t _1314_sum;
    int64_t _1315_i;
    uint8_t _1313_t3;
    int64_t _1313_t5;
    int64_t _1313_$retval;
    _1314_sum = 0;
    _1315_i = 0;
    goto BB1575;
BB1575:
    _1313_t3 = _1315_i<_1313_xs._1;
    if (_1313_t3) {
        goto BB1576;
    } else {
        goto BB1581;
    }
BB1576:
    $bounds_check(_1315_i, _1313_xs._1, "tests/integration/slices/infer-lower.orng:12:15:\n        sum += xs[i]\n             ^");
    _1314_sum = $add_int64_t(_1314_sum, *((int64_t*)_1313_xs._0 + _1315_i), "tests/integration/slices/infer-lower.orng:12:15:\n        sum += xs[i]\n             ^");
    _1313_t5 = 1;
    _1315_i = $add_int64_t(_1315_i, _1313_t5, "tests/integration/slices/infer-lower.orng:11:50:\n    while let mut i: Int = 0; i < xs.length; i += 1 {\n                                                ^");
    goto BB1575;
BB1581:
    _1313_$retval = _1314_sum;
    return _1313_$retval;
}

int main(void) {
  printf("%ld",_1311_main());
  return 0;
}
