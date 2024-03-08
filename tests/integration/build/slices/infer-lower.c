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
int64_t _1358_main(void);
int64_t _1360_sum_up(struct struct1 _1360_xs);


/* Function definitions */
int64_t _1358_main(void){
    int64_t _1358_t1;
    int64_t _1358_t2;
    int64_t _1358_t3;
    int64_t _1358_t4;
    int64_t _1358_t5;
    int64_t _1358_t6;
    struct struct0 _1359_x;
    int64_t _1358_t8;
    int64_t _1358_t9;
    int64_t* _1358_t10;
    int64_t _1358_t11;
    struct struct1 _1359_y;
    int64_t _1358_t15;
    int64_t* _1358_t16;
    struct struct1 _1359_z;
    function2 _1358_t18;
    int64_t _1358_t19;
    int64_t _1358_$retval;
    _1358_t1 = 100;
    _1358_t2 = 8;
    _1358_t3 = 2;
    _1358_t4 = 4;
    _1358_t5 = 35;
    _1358_t6 = 6;
    _1359_x = (struct struct0) {_1358_t1, _1358_t2, _1358_t3, _1358_t4, _1358_t5, _1358_t6};
    _1358_t8 = 0;
    _1358_t9 = 6;
    $bounds_check(_1358_t8, _1358_t9, "tests/integration/slices/infer-lower.orng:4:19:\n    let y = [mut]x\n                 ^");
    _1358_t10 = ((int64_t*)&_1359_x + _1358_t8);
    _1358_t11 = 6;
    _1359_y = (struct struct1) {_1358_t10, _1358_t11};
    _1358_t15 = 3;
    _1358_t16 = _1359_y._0;
    _1359_z = (struct struct1) {_1358_t16, _1358_t15};
    _1358_t18 = (function2) _1360_sum_up;
    $lines[$line_idx++] = "tests/integration/slices/infer-lower.orng:6:12:\n    sum_up(z)\n          ^";
    _1358_t19 = _1358_t18(_1359_z);
    $line_idx--;
    _1358_$retval = _1358_t19;
    return _1358_$retval;
}

int64_t _1360_sum_up(struct struct1 _1360_xs){
    int64_t _1361_sum;
    int64_t _1362_i;
    uint8_t _1360_t3;
    int64_t _1360_t5;
    int64_t _1360_$retval;
    _1361_sum = 0;
    _1362_i = 0;
    goto BB1617;
BB1617:
    _1360_t3 = _1362_i<_1360_xs._1;
    if (_1360_t3) {
        goto BB1618;
    } else {
        goto BB1623;
    }
BB1618:
    $bounds_check(_1362_i, _1360_xs._1, "tests/integration/slices/infer-lower.orng:12:15:\n        sum += xs[i]\n             ^");
    _1361_sum = $add_int64_t(_1361_sum, *((int64_t*)_1360_xs._0 + _1362_i), "tests/integration/slices/infer-lower.orng:12:15:\n        sum += xs[i]\n             ^");
    _1360_t5 = 1;
    _1362_i = $add_int64_t(_1362_i, _1360_t5, "tests/integration/slices/infer-lower.orng:11:50:\n    while let mut i: Int = 0; i < xs.length; i += 1 {\n                                                ^");
    goto BB1617;
BB1623:
    _1360_$retval = _1361_sum;
    return _1360_$retval;
}


int main(void) {
  printf("%ld",_1358_main());
  return 0;
}
