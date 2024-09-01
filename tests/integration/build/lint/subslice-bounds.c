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
int64_t _1127_main(void);
int64_t _1129_f(void);


/* Function definitions */
int64_t _1127_main(void){
    int64_t _1127_t1;
    int64_t _1127_t2;
    int64_t _1127_t3;
    int64_t _1127_t4;
    struct struct0 _1128_x;
    int64_t _1127_t7;
    int64_t _1127_t8;
    int64_t* _1127_t9;
    int64_t _1127_t10;
    struct struct1 _1128_y;
    function2 _1127_t12;
    int64_t _1127_t13;
    int64_t _1127_t14;
    uint8_t _1127_t15;
    int64_t _1127_t16;
    int64_t* _1127_t17;
    struct struct1 _1128_z;
    int64_t _1127_t20;
    int64_t _1127_$retval;
    _1127_t1 = 0;
    _1127_t2 = 0;
    _1127_t3 = 0;
    _1127_t4 = 0;
    _1128_x = (struct struct0) {_1127_t1, _1127_t2, _1127_t3, _1127_t4};
    _1127_t7 = 0;
    _1127_t8 = 4;
    $bounds_check(_1127_t7, _1127_t8, "tests/integration/lint/subslice-bounds.orng:4:16:\n    let y = []x\n              ^");
    _1127_t9 = ((int64_t*)&_1128_x + _1127_t7);
    _1127_t10 = 4;
    _1128_y = (struct struct1) {_1127_t9, _1127_t10};
    _1127_t12 = (function2) _1129_f;
    $lines[$line_idx++] = "tests/integration/lint/subslice-bounds.orng:5:17:\n    let z = y[f()..1]\n               ^";
    _1127_t13 = _1127_t12();
    $line_idx--;
    _1127_t14 = 1;
    _1127_t15 = _1127_t13>_1127_t14;
    if (_1127_t15) {
        goto BB1295;
    } else {
        goto BB1296;
    }
BB1295:
    $lines[$line_idx++] = "tests/integration/lint/subslice-bounds.orng:5:15:\n    let z = y[f()..1]\n             ^";
    $panic("subslice lower bound is greater than upper bound\n");
BB1296:
    _1127_t16 = $sub_int64_t(_1127_t14, _1127_t13, "tests/integration/lint/subslice-bounds.orng:5:15:\n    let z = y[f()..1]\n             ^");
    _1127_t17 = _1128_y._0+_1127_t13;
    _1128_z = (struct struct1) {_1127_t17, _1127_t16};
    _1127_t20 = 0;
    $bounds_check(_1127_t20, _1128_z._1, "tests/integration/lint/subslice-bounds.orng:2:3:\nfn main() -> Int {\n ^");
    _1127_$retval = *((int64_t*)_1128_z._0 + _1127_t20);
    return _1127_$retval;
}

int64_t _1129_f(void){
    int64_t _1129_$retval;
    _1129_$retval = 2;
    return _1129_$retval;
}


int main(void) {
  printf("%ld",_1127_main());
  return 0;
}
