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
};

struct struct1 {
    int64_t* _0;
    int64_t _1;
};

typedef int64_t(*function2)(void);

/* Function forward definitions */
int64_t _1108_main(void);
int64_t _1110_f(void);


/* Function definitions */
int64_t _1108_main(void){
    int64_t _1108_t1;
    int64_t _1108_t2;
    int64_t _1108_t3;
    int64_t _1108_t4;
    struct struct0 _1109_x;
    int64_t _1108_t6;
    int64_t _1108_t7;
    int64_t* _1108_t8;
    int64_t _1108_t9;
    struct struct1 _1109_y;
    function2 _1108_t10;
    int64_t _1108_t11;
    int64_t _1108_t12;
    uint8_t _1108_t13;
    int64_t _1108_t14;
    int64_t* _1108_t15;
    struct struct1 _1109_z;
    int64_t _1108_t17;
    int64_t _1108_$retval;
    _1108_t1 = 0;
    _1108_t2 = 0;
    _1108_t3 = 0;
    _1108_t4 = 0;
    _1109_x = (struct struct0) {_1108_t1, _1108_t2, _1108_t3, _1108_t4};
    _1108_t6 = 0;
    _1108_t7 = 4;
    $bounds_check(_1108_t6, _1108_t7, "tests/integration/lint/subslice-bounds.orng:4:16:\n    let y = []x\n              ^");
    _1108_t8 = ((int64_t*)&_1109_x + _1108_t6);
    _1108_t9 = 4;
    _1109_y = (struct struct1) {_1108_t8, _1108_t9};
    _1108_t10 = _1110_f;
    $lines[$line_idx++] = "tests/integration/lint/subslice-bounds.orng:5:17:\n    let z = y[f()..1]\n               ^";
    _1108_t11 = _1108_t10();
    $line_idx--;
    _1108_t12 = 1;
    _1108_t13 = _1108_t11>_1108_t12;
    if (_1108_t13) {
        goto BB1297;
    } else {
        goto BB1298;
    }
BB1297:
    $lines[$line_idx++] = "tests/integration/lint/subslice-bounds.orng:5:15:\n    let z = y[f()..1]\n             ^";
    $panic("subslice lower bound is greater than upper bound\n");
BB1298:
    _1108_t14 = $sub_int64_t(_1108_t12, _1108_t11, "tests/integration/lint/subslice-bounds.orng:5:15:\n    let z = y[f()..1]\n             ^");
    _1108_t15 = _1109_y._0+_1108_t11;
    _1109_z = (struct struct1) {_1108_t15, _1108_t14};
    _1108_t17 = 0;
    $bounds_check(_1108_t17, _1109_z._1, "tests/integration/lint/subslice-bounds.orng:2:3:\nfn main() -> Int {\n ^");
    _1108_$retval = *((int64_t*)_1109_z._0 + _1108_t17);
    return _1108_$retval;
}

int64_t _1110_f(void){
    int64_t _1110_$retval;
    _1110_$retval = 2;
    return _1110_$retval;
}


int main(void) {
  printf("%ld",_1108_main());
  return 0;
}
