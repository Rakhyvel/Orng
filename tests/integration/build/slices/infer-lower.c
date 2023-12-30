/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef struct {
        int64_t _0;
        int64_t _1;
        int64_t _2;
        int64_t _3;
        int64_t _4;
        int64_t _5;
} struct0;

typedef struct {
        int64_t* _0;
        int64_t _1;
} struct1;

typedef int64_t(*function2)(struct1);

/* Function forward definitions */
int64_t _1308_main(void);
int64_t _1310_sum_up(struct1 _1310_xs);

/* Function definitions */
int64_t _1308_main(void){
    int64_t _1308_t1;
    int64_t _1308_t2;
    int64_t _1308_t3;
    int64_t _1308_t4;
    int64_t _1308_t5;
    int64_t _1308_t6;
    struct0 _1309_x;
    int64_t _1308_t8;
    int64_t _1308_t9;
    int64_t* _1308_t10;
    int64_t _1308_t11;
    struct1 _1309_y;
    int64_t _1308_t15;
    int64_t* _1308_t16;
    struct1 _1309_z;
    function2 _1308_t18;
    int64_t _1308_t19;
    int64_t _1308_$retval;
    _1308_t1 = 100;
    _1308_t2 = 8;
    _1308_t3 = 2;
    _1308_t4 = 4;
    _1308_t5 = 35;
    _1308_t6 = 6;
    _1309_x = (struct0) {_1308_t1, _1308_t2, _1308_t3, _1308_t4, _1308_t5, _1308_t6};
    _1308_t8 = 0;
    _1308_t9 = 6;
    $bounds_check(_1308_t8, _1308_t9, "tests/integration/slices/infer-lower.orng:4:19:\n    let y = [mut]x\n                 ^");
    _1308_t10 = ((int64_t*)&_1309_x + _1308_t8);
    _1308_t11 = 6;
    _1309_y = (struct1) {_1308_t10, _1308_t11};
    _1308_t15 = 3;
    _1308_t16 = _1309_y._0;
    _1309_z = (struct1) {_1308_t16, _1308_t15};
    _1308_t18 = _1310_sum_up;
    $lines[$line_idx++] = "tests/integration/slices/infer-lower.orng:6:12:\n    sum_up(z)\n          ^";
    _1308_t19 = _1308_t18(_1309_z);
    $line_idx--;
    _1308_$retval = _1308_t19;
    return _1308_$retval;
}

int64_t _1310_sum_up(struct1 _1310_xs){
    int64_t _1311_sum;
    int64_t _1312_i;
    uint8_t _1310_t3;
    int64_t _1310_t5;
    int64_t _1310_$retval;
    _1311_sum = 0;
    _1312_i = 0;
    goto BB1583;
BB1583:
    _1310_t3 = _1312_i<_1310_xs._1;
    if (_1310_t3) {
        goto BB1584;
    } else {
        goto BB1589;
    }
BB1584:
    $bounds_check(_1312_i, _1310_xs._1, "tests/integration/slices/infer-lower.orng:12:15:\n        sum += xs[i]\n             ^");
    _1311_sum = $add_int64_t(_1311_sum, *((int64_t*)_1310_xs._0 + _1312_i), "tests/integration/slices/infer-lower.orng:12:15:\n        sum += xs[i]\n             ^");
    _1310_t5 = 1;
    _1312_i = $add_int64_t(_1312_i, _1310_t5, "tests/integration/slices/infer-lower.orng:11:50:\n    while let mut i: Int = 0; i < xs.length; i += 1 {\n                                                ^");
    goto BB1583;
BB1589:
    _1310_$retval = _1311_sum;
    return _1310_$retval;
}

int main(void) {
  printf("%ld",_1308_main());
  return 0;
}
