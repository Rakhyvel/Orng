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
int64_t _1317_main(void);
int64_t _1319_sum_up(struct1 _1319_xs);

/* Function definitions */
int64_t _1317_main(void){
    int64_t _1317_t1;
    int64_t _1317_t2;
    int64_t _1317_t3;
    int64_t _1317_t4;
    int64_t _1317_t5;
    int64_t _1317_t6;
    struct0 _1318_x;
    int64_t _1317_t8;
    int64_t _1317_t9;
    int64_t* _1317_t10;
    int64_t _1317_t11;
    struct1 _1318_y;
    int64_t _1317_t12;
    int64_t _1317_t15;
    int64_t* _1317_t16;
    struct1 _1318_z;
    int64_t _1317_t19;
    function2 _1317_t20;
    int64_t _1317_t21;
    int64_t _1317_$retval;
    _1317_t1 = 1;
    _1317_t2 = 15;
    _1317_t3 = 24;
    _1317_t4 = 4;
    _1317_t5 = 35;
    _1317_t6 = 6;
    _1318_x = (struct0) {_1317_t1, _1317_t2, _1317_t3, _1317_t4, _1317_t5, _1317_t6};
    _1317_t8 = 0;
    _1317_t9 = 6;
    $bounds_check(_1317_t8, _1317_t9, "tests/integration/slices/subslice.orng:4:19:\n    let y = [mut]x\n                 ^");
    _1317_t10 = ((int64_t*)&_1318_x + _1317_t8);
    _1317_t11 = 6;
    _1318_y = (struct1) {_1317_t10, _1317_t11};
    _1317_t12 = 1;
    _1317_t15 = 4;
    _1317_t16 = _1318_y._0+_1317_t12;
    _1318_z = (struct1) {_1317_t16, _1317_t15};
    _1317_t19 = 2;
    $bounds_check(_1317_t19, _1318_z._1, "tests/integration/slices/subslice.orng:6:14:\n    z[2] = 10\n            ^");
    *((int64_t*)_1318_z._0 + _1317_t19) = 10;
    _1317_t20 = _1319_sum_up;
    $lines[$line_idx++] = "tests/integration/slices/subslice.orng:7:12:\n    sum_up(z)\n          ^";
    _1317_t21 = _1317_t20(_1318_z);
    $line_idx--;
    _1317_$retval = _1317_t21;
    return _1317_$retval;
}

int64_t _1319_sum_up(struct1 _1319_xs){
    int64_t _1320_sum;
    int64_t _1321_i;
    uint8_t _1319_t3;
    int64_t _1319_t5;
    int64_t _1319_$retval;
    _1320_sum = 0;
    _1321_i = 0;
    goto BB1630;
BB1630:
    _1319_t3 = _1321_i<_1319_xs._1;
    if (_1319_t3) {
        goto BB1631;
    } else {
        goto BB1636;
    }
BB1631:
    $bounds_check(_1321_i, _1319_xs._1, "tests/integration/slices/subslice.orng:13:15:\n        sum += xs[i]\n             ^");
    _1320_sum = $add_int64_t(_1320_sum, *((int64_t*)_1319_xs._0 + _1321_i), "tests/integration/slices/subslice.orng:13:15:\n        sum += xs[i]\n             ^");
    _1319_t5 = 1;
    _1321_i = $add_int64_t(_1321_i, _1319_t5, "tests/integration/slices/subslice.orng:12:50:\n    while let mut i: Int = 0; i < xs.length; i += 1 {\n                                                ^");
    goto BB1630;
BB1636:
    _1319_$retval = _1320_sum;
    return _1319_$retval;
}

int main(void) {
  printf("%ld",_1317_main());
  return 0;
}
