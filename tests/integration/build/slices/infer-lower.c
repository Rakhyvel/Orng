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
int64_t _1361_main(void);
int64_t _1363_sum_up(struct struct1 _1363_xs);


/* Function definitions */
int64_t _1361_main(void){
    int64_t _1361_t1;
    int64_t _1361_t2;
    int64_t _1361_t3;
    int64_t _1361_t4;
    int64_t _1361_t5;
    int64_t _1361_t6;
    struct struct0 _1362_x;
    int64_t _1361_t9;
    int64_t _1361_t10;
    int64_t* _1361_t11;
    int64_t _1361_t12;
    struct struct1 _1362_y;
    int64_t _1361_t17;
    int64_t* _1361_t18;
    struct struct1 _1362_z;
    function2 _1361_t21;
    int64_t _1361_t22;
    int64_t _1361_$retval;
    _1361_t1 = 100;
    _1361_t2 = 8;
    _1361_t3 = 2;
    _1361_t4 = 4;
    _1361_t5 = 35;
    _1361_t6 = 6;
    _1362_x = (struct struct0) {_1361_t1, _1361_t2, _1361_t3, _1361_t4, _1361_t5, _1361_t6};
    _1361_t9 = 0;
    _1361_t10 = 6;
    $bounds_check(_1361_t9, _1361_t10, "tests/integration/slices/infer-lower.orng:4:19:\n    let y = [mut]x\n                 ^");
    _1361_t11 = ((int64_t*)&_1362_x + _1361_t9);
    _1361_t12 = 6;
    _1362_y = (struct struct1) {_1361_t11, _1361_t12};
    _1361_t17 = 3;
    _1361_t18 = _1362_y._0;
    _1362_z = (struct struct1) {_1361_t18, _1361_t17};
    _1361_t21 = (function2) _1363_sum_up;
    $lines[$line_idx++] = "tests/integration/slices/infer-lower.orng:6:12:\n    sum_up(z)\n          ^";
    _1361_t22 = _1361_t21(_1362_z);
    $line_idx--;
    _1361_$retval = _1361_t22;
    return _1361_$retval;
}

int64_t _1363_sum_up(struct struct1 _1363_xs){
    int64_t _1364_sum;
    int64_t _1365_i;
    uint8_t _1363_t5;
    int64_t _1363_t7;
    int64_t _1363_$retval;
    _1364_sum = 0;
    _1365_i = 0;
    goto BB1611;
BB1611:
    _1363_t5 = _1365_i<_1363_xs._1;
    if (_1363_t5) {
        goto BB1612;
    } else {
        goto BB1617;
    }
BB1612:
    $bounds_check(_1365_i, _1363_xs._1, "tests/integration/slices/infer-lower.orng:12:15:\n        sum += xs[i]\n             ^");
    _1364_sum = $add_int64_t(_1364_sum, *((int64_t*)_1363_xs._0 + _1365_i), "tests/integration/slices/infer-lower.orng:12:15:\n        sum += xs[i]\n             ^");
    _1363_t7 = 1;
    _1365_i = $add_int64_t(_1365_i, _1363_t7, "tests/integration/slices/infer-lower.orng:11:50:\n    while let mut i: Int = 0; i < xs.length; i += 1 {\n                                                ^");
    goto BB1611;
BB1617:
    _1363_$retval = _1364_sum;
    return _1363_$retval;
}


int main(void) {
  printf("%ld",_1361_main());
  return 0;
}
