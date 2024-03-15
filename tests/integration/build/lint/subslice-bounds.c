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
int64_t _1074_main(void);
int64_t _1076_f(void);


/* Function definitions */
int64_t _1074_main(void){
    int64_t _1074_t1;
    int64_t _1074_t2;
    int64_t _1074_t3;
    int64_t _1074_t4;
    struct struct0 _1075_x;
    int64_t _1074_t7;
    int64_t _1074_t8;
    int64_t* _1074_t9;
    int64_t _1074_t10;
    struct struct1 _1075_y;
    function2 _1074_t12;
    int64_t _1074_t13;
    int64_t _1074_t14;
    uint8_t _1074_t15;
    int64_t _1074_t16;
    int64_t* _1074_t17;
    struct struct1 _1075_z;
    int64_t _1074_t20;
    int64_t _1074_$retval;
    _1074_t1 = 0;
    _1074_t2 = 0;
    _1074_t3 = 0;
    _1074_t4 = 0;
    _1075_x = (struct struct0) {_1074_t1, _1074_t2, _1074_t3, _1074_t4};
    _1074_t7 = 0;
    _1074_t8 = 4;
    $bounds_check(_1074_t7, _1074_t8, "tests/integration/lint/subslice-bounds.orng:4:16:\n    let y = []x\n              ^");
    _1074_t9 = ((int64_t*)&_1075_x + _1074_t7);
    _1074_t10 = 4;
    _1075_y = (struct struct1) {_1074_t9, _1074_t10};
    _1074_t12 = (function2) _1076_f;
    $lines[$line_idx++] = "tests/integration/lint/subslice-bounds.orng:5:17:\n    let z = y[f()..1]\n               ^";
    _1074_t13 = _1074_t12();
    $line_idx--;
    _1074_t14 = 1;
    _1074_t15 = _1074_t13>_1074_t14;
    if (_1074_t15) {
        goto BB1237;
    } else {
        goto BB1238;
    }
BB1237:
    $lines[$line_idx++] = "tests/integration/lint/subslice-bounds.orng:5:15:\n    let z = y[f()..1]\n             ^";
    $panic("subslice lower bound is greater than upper bound\n");
BB1238:
    _1074_t16 = $sub_int64_t(_1074_t14, _1074_t13, "tests/integration/lint/subslice-bounds.orng:5:15:\n    let z = y[f()..1]\n             ^");
    _1074_t17 = _1075_y._0+_1074_t13;
    _1075_z = (struct struct1) {_1074_t17, _1074_t16};
    _1074_t20 = 0;
    $bounds_check(_1074_t20, _1075_z._1, "tests/integration/lint/subslice-bounds.orng:2:3:\nfn main() -> Int {\n ^");
    _1074_$retval = *((int64_t*)_1075_z._0 + _1074_t20);
    return _1074_$retval;
}

int64_t _1076_f(void){
    int64_t _1076_$retval;
    _1076_$retval = 2;
    return _1076_$retval;
}


int main(void) {
  printf("%ld",_1074_main());
  return 0;
}
