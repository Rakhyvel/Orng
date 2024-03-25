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
int64_t _1336_main(void);
int64_t _1338_sum_up(struct struct1 _1338_xs);


/* Function definitions */
int64_t _1336_main(void){
    int64_t _1336_t1;
    int64_t _1336_t2;
    int64_t _1336_t3;
    int64_t _1336_t4;
    int64_t _1336_t5;
    int64_t _1336_t6;
    struct struct0 _1337_x;
    int64_t _1336_t9;
    int64_t _1336_t10;
    int64_t* _1336_t11;
    int64_t _1336_t12;
    struct struct1 _1337_y;
    int64_t _1336_t17;
    int64_t* _1336_t18;
    struct struct1 _1337_z;
    function2 _1336_t21;
    int64_t _1336_t22;
    int64_t _1336_$retval;
    _1336_t1 = 100;
    _1336_t2 = 8;
    _1336_t3 = 2;
    _1336_t4 = 4;
    _1336_t5 = 35;
    _1336_t6 = 6;
    _1337_x = (struct struct0) {_1336_t1, _1336_t2, _1336_t3, _1336_t4, _1336_t5, _1336_t6};
    _1336_t9 = 0;
    _1336_t10 = 6;
    $bounds_check(_1336_t9, _1336_t10, "tests/integration/slices/infer-lower.orng:4:19:\n    let y = [mut]x\n                 ^");
    _1336_t11 = ((int64_t*)&_1337_x + _1336_t9);
    _1336_t12 = 6;
    _1337_y = (struct struct1) {_1336_t11, _1336_t12};
    _1336_t17 = 3;
    _1336_t18 = _1337_y._0;
    _1337_z = (struct struct1) {_1336_t18, _1336_t17};
    _1336_t21 = (function2) _1338_sum_up;
    $lines[$line_idx++] = "tests/integration/slices/infer-lower.orng:6:12:\n    sum_up(z)\n          ^";
    _1336_t22 = _1336_t21(_1337_z);
    $line_idx--;
    _1336_$retval = _1336_t22;
    return _1336_$retval;
}

int64_t _1338_sum_up(struct struct1 _1338_xs){
    int64_t _1339_sum;
    int64_t _1340_i;
    uint8_t _1338_t5;
    int64_t _1338_t7;
    int64_t _1338_$retval;
    _1339_sum = 0;
    _1340_i = 0;
    goto BB1564;
BB1564:
    _1338_t5 = _1340_i<_1338_xs._1;
    if (_1338_t5) {
        goto BB1565;
    } else {
        goto BB1570;
    }
BB1565:
    $bounds_check(_1340_i, _1338_xs._1, "tests/integration/slices/infer-lower.orng:12:15:\n        sum += xs[i]\n             ^");
    _1339_sum = $add_int64_t(_1339_sum, *((int64_t*)_1338_xs._0 + _1340_i), "tests/integration/slices/infer-lower.orng:12:15:\n        sum += xs[i]\n             ^");
    _1338_t7 = 1;
    _1340_i = $add_int64_t(_1340_i, _1338_t7, "tests/integration/slices/infer-lower.orng:11:50:\n    while let mut i: Int = 0; i < xs.length; i += 1 {\n                                                ^");
    goto BB1564;
BB1570:
    _1338_$retval = _1339_sum;
    return _1338_$retval;
}


int main(void) {
  printf("%ld",_1336_main());
  return 0;
}
