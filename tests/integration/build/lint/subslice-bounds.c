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
int64_t _1182_main(void);
int64_t _1184_f(void);


/* Function definitions */
int64_t _1182_main(void){
    int64_t _1182_t1;
    int64_t _1182_t2;
    int64_t _1182_t3;
    int64_t _1182_t4;
    struct struct0 _1183_x;
    int64_t _1182_t7;
    int64_t _1182_t8;
    int64_t* _1182_t9;
    int64_t _1182_t10;
    struct struct1 _1183_y;
    function2 _1182_t12;
    int64_t _1182_t13;
    int64_t _1182_t14;
    uint8_t _1182_t15;
    int64_t _1182_t16;
    int64_t* _1182_t17;
    struct struct1 _1183_z;
    int64_t _1182_t20;
    int64_t _1182_$retval;
    _1182_t1 = 0;
    _1182_t2 = 0;
    _1182_t3 = 0;
    _1182_t4 = 0;
    _1183_x = (struct struct0) {_1182_t1, _1182_t2, _1182_t3, _1182_t4};
    _1182_t7 = 0;
    _1182_t8 = 4;
    $bounds_check(_1182_t7, _1182_t8, "tests/integration/lint/subslice-bounds.orng:4:16:\n    let y = []x\n              ^");
    _1182_t9 = ((int64_t*)&_1183_x + _1182_t7);
    _1182_t10 = 4;
    _1183_y = (struct struct1) {_1182_t9, _1182_t10};
    _1182_t12 = (function2) _1184_f;
    $lines[$line_idx++] = "tests/integration/lint/subslice-bounds.orng:5:17:\n    let z = y[f()..1]\n               ^";
    _1182_t13 = _1182_t12();
    $line_idx--;
    _1182_t14 = 1;
    _1182_t15 = _1182_t13>_1182_t14;
    if (_1182_t15) {
        goto BB1352;
    } else {
        goto BB1353;
    }
BB1352:
    $lines[$line_idx++] = "tests/integration/lint/subslice-bounds.orng:5:15:\n    let z = y[f()..1]\n             ^";
    $panic("subslice lower bound is greater than upper bound\n");
BB1353:
    _1182_t16 = $sub_int64_t(_1182_t14, _1182_t13, "tests/integration/lint/subslice-bounds.orng:5:15:\n    let z = y[f()..1]\n             ^");
    _1182_t17 = _1183_y._0+_1182_t13;
    _1183_z = (struct struct1) {_1182_t17, _1182_t16};
    _1182_t20 = 0;
    $bounds_check(_1182_t20, _1183_z._1, "tests/integration/lint/subslice-bounds.orng:2:8:\nfn main() -> Int {\n      ^");
    _1182_$retval = *((int64_t*)_1183_z._0 + _1182_t20);
    return _1182_$retval;
}

int64_t _1184_f(void){
    int64_t _1184_$retval;
    _1184_$retval = 2;
    return _1184_$retval;
}


int main(void) {
  printf("%ld",_1182_main());
  return 0;
}
