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
int64_t _1083_main(void);
int64_t _1085_f(void);


/* Function definitions */
int64_t _1083_main(void){
    int64_t _1083_t1;
    int64_t _1083_t2;
    int64_t _1083_t3;
    int64_t _1083_t4;
    struct struct0 _1084_x;
    int64_t _1083_t7;
    int64_t _1083_t8;
    int64_t* _1083_t9;
    int64_t _1083_t10;
    struct struct1 _1084_y;
    function2 _1083_t12;
    int64_t _1083_t13;
    int64_t _1083_t14;
    uint8_t _1083_t15;
    int64_t _1083_t16;
    int64_t* _1083_t17;
    struct struct1 _1084_z;
    int64_t _1083_t20;
    int64_t _1083_$retval;
    _1083_t1 = 0;
    _1083_t2 = 0;
    _1083_t3 = 0;
    _1083_t4 = 0;
    _1084_x = (struct struct0) {_1083_t1, _1083_t2, _1083_t3, _1083_t4};
    _1083_t7 = 0;
    _1083_t8 = 4;
    $bounds_check(_1083_t7, _1083_t8, "tests/integration/lint/subslice-bounds.orng:4:16:\n    let y = []x\n              ^");
    _1083_t9 = ((int64_t*)&_1084_x + _1083_t7);
    _1083_t10 = 4;
    _1084_y = (struct struct1) {_1083_t9, _1083_t10};
    _1083_t12 = (function2) _1085_f;
    $lines[$line_idx++] = "tests/integration/lint/subslice-bounds.orng:5:17:\n    let z = y[f()..1]\n               ^";
    _1083_t13 = _1083_t12();
    $line_idx--;
    _1083_t14 = 1;
    _1083_t15 = _1083_t13>_1083_t14;
    if (_1083_t15) {
        goto BB1243;
    } else {
        goto BB1244;
    }
BB1243:
    $lines[$line_idx++] = "tests/integration/lint/subslice-bounds.orng:5:15:\n    let z = y[f()..1]\n             ^";
    $panic("subslice lower bound is greater than upper bound\n");
BB1244:
    _1083_t16 = $sub_int64_t(_1083_t14, _1083_t13, "tests/integration/lint/subslice-bounds.orng:5:15:\n    let z = y[f()..1]\n             ^");
    _1083_t17 = _1084_y._0+_1083_t13;
    _1084_z = (struct struct1) {_1083_t17, _1083_t16};
    _1083_t20 = 0;
    $bounds_check(_1083_t20, _1084_z._1, "tests/integration/lint/subslice-bounds.orng:2:3:\nfn main() -> Int {\n ^");
    _1083_$retval = *((int64_t*)_1084_z._0 + _1083_t20);
    return _1083_$retval;
}

int64_t _1085_f(void){
    int64_t _1085_$retval;
    _1085_$retval = 2;
    return _1085_$retval;
}


int main(void) {
  printf("%ld",_1083_main());
  return 0;
}
