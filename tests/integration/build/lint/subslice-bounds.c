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
int64_t _1146_main(void);
int64_t _1148_f(void);


/* Function definitions */
int64_t _1146_main(void){
    int64_t _1146_t1;
    int64_t _1146_t2;
    int64_t _1146_t3;
    int64_t _1146_t4;
    struct struct0 _1147_x;
    int64_t _1146_t7;
    int64_t _1146_t8;
    int64_t* _1146_t9;
    int64_t _1146_t10;
    struct struct1 _1147_y;
    function2 _1146_t12;
    int64_t _1146_t13;
    int64_t _1146_t14;
    uint8_t _1146_t15;
    int64_t _1146_t16;
    int64_t* _1146_t17;
    struct struct1 _1147_z;
    int64_t _1146_t20;
    int64_t _1146_$retval;
    _1146_t1 = 0;
    _1146_t2 = 0;
    _1146_t3 = 0;
    _1146_t4 = 0;
    _1147_x = (struct struct0) {_1146_t1, _1146_t2, _1146_t3, _1146_t4};
    _1146_t7 = 0;
    _1146_t8 = 4;
    $bounds_check(_1146_t7, _1146_t8, "tests/integration/lint/subslice-bounds.orng:4:16:\n    let y = []x\n              ^");
    _1146_t9 = ((int64_t*)&_1147_x + _1146_t7);
    _1146_t10 = 4;
    _1147_y = (struct struct1) {_1146_t9, _1146_t10};
    _1146_t12 = (function2) _1148_f;
    $lines[$line_idx++] = "tests/integration/lint/subslice-bounds.orng:5:17:\n    let z = y[f()..1]\n               ^";
    _1146_t13 = _1146_t12();
    $line_idx--;
    _1146_t14 = 1;
    _1146_t15 = _1146_t13>_1146_t14;
    if (_1146_t15) {
        goto BB1312;
    } else {
        goto BB1313;
    }
BB1312:
    $lines[$line_idx++] = "tests/integration/lint/subslice-bounds.orng:5:15:\n    let z = y[f()..1]\n             ^";
    $panic("subslice lower bound is greater than upper bound\n");
BB1313:
    _1146_t16 = $sub_int64_t(_1146_t14, _1146_t13, "tests/integration/lint/subslice-bounds.orng:5:15:\n    let z = y[f()..1]\n             ^");
    _1146_t17 = _1147_y._0+_1146_t13;
    _1147_z = (struct struct1) {_1146_t17, _1146_t16};
    _1146_t20 = 0;
    $bounds_check(_1146_t20, _1147_z._1, "tests/integration/lint/subslice-bounds.orng:2:8:\nfn main() -> Int {\n      ^");
    _1146_$retval = *((int64_t*)_1147_z._0 + _1146_t20);
    return _1146_$retval;
}

int64_t _1148_f(void){
    int64_t _1148_$retval;
    _1148_$retval = 2;
    return _1148_$retval;
}


int main(void) {
  printf("%ld",_1146_main());
  return 0;
}
