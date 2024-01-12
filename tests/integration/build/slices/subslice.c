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
int64_t _1359_main(void);
int64_t _1361_sum_up(struct struct1 _1361_xs);

/* Function definitions */
int64_t _1359_main(void){
    int64_t _1359_t1;
    int64_t _1359_t2;
    int64_t _1359_t3;
    int64_t _1359_t4;
    int64_t _1359_t5;
    int64_t _1359_t6;
    struct struct0 _1360_x;
    int64_t _1359_t8;
    int64_t _1359_t9;
    int64_t* _1359_t10;
    int64_t _1359_t11;
    struct struct1 _1360_y;
    int64_t _1359_t12;
    int64_t _1359_t15;
    int64_t* _1359_t16;
    struct struct1 _1360_z;
    int64_t _1359_t19;
    function2 _1359_t20;
    int64_t _1359_t21;
    int64_t _1359_$retval;
    _1359_t1 = 1;
    _1359_t2 = 15;
    _1359_t3 = 24;
    _1359_t4 = 4;
    _1359_t5 = 35;
    _1359_t6 = 6;
    _1360_x = (struct struct0) {_1359_t1, _1359_t2, _1359_t3, _1359_t4, _1359_t5, _1359_t6};
    _1359_t8 = 0;
    _1359_t9 = 6;
    $bounds_check(_1359_t8, _1359_t9, "tests/integration/slices/subslice.orng:4:19:\n    let y = [mut]x\n                 ^");
    _1359_t10 = ((int64_t*)&_1360_x + _1359_t8);
    _1359_t11 = 6;
    _1360_y = (struct struct1) {_1359_t10, _1359_t11};
    _1359_t12 = 1;
    _1359_t15 = 4;
    _1359_t16 = _1360_y._0+_1359_t12;
    _1360_z = (struct struct1) {_1359_t16, _1359_t15};
    _1359_t19 = 2;
    $bounds_check(_1359_t19, _1360_z._1, "tests/integration/slices/subslice.orng:6:14:\n    z[2] = 10\n            ^");
    *((int64_t*)_1360_z._0 + _1359_t19) = 10;
    _1359_t20 = _1361_sum_up;
    $lines[$line_idx++] = "tests/integration/slices/subslice.orng:7:12:\n    sum_up(z)\n          ^";
    _1359_t21 = _1359_t20(_1360_z);
    $line_idx--;
    _1359_$retval = _1359_t21;
    return _1359_$retval;
}

int64_t _1361_sum_up(struct struct1 _1361_xs){
    int64_t _1362_sum;
    int64_t _1363_i;
    uint8_t _1361_t3;
    int64_t _1361_t5;
    int64_t _1361_$retval;
    _1362_sum = 0;
    _1363_i = 0;
    goto BB1635;
BB1635:
    _1361_t3 = _1363_i<_1361_xs._1;
    if (_1361_t3) {
        goto BB1636;
    } else {
        goto BB1641;
    }
BB1636:
    $bounds_check(_1363_i, _1361_xs._1, "tests/integration/slices/subslice.orng:13:15:\n        sum += xs[i]\n             ^");
    _1362_sum = $add_int64_t(_1362_sum, *((int64_t*)_1361_xs._0 + _1363_i), "tests/integration/slices/subslice.orng:13:15:\n        sum += xs[i]\n             ^");
    _1361_t5 = 1;
    _1363_i = $add_int64_t(_1363_i, _1361_t5, "tests/integration/slices/subslice.orng:12:50:\n    while let mut i: Int = 0; i < xs.length; i += 1 {\n                                                ^");
    goto BB1635;
BB1641:
    _1361_$retval = _1362_sum;
    return _1361_$retval;
}

int main(void) {
  printf("%ld",_1359_main());
  return 0;
}
