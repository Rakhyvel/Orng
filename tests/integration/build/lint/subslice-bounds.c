/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward typedefs */
struct struct0;
struct struct1;

/* Typedefs */
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
int64_t _1061_main(void);
int64_t _1063_f(void);

/* Function definitions */
int64_t _1061_main(void){
    int64_t _1061_t1;
    int64_t _1061_t2;
    int64_t _1061_t3;
    int64_t _1061_t4;
    struct struct0 _1062_x;
    int64_t _1061_t6;
    int64_t _1061_t7;
    int64_t* _1061_t8;
    int64_t _1061_t9;
    struct struct1 _1062_y;
    function2 _1061_t10;
    int64_t _1061_t11;
    int64_t _1061_t12;
    uint8_t _1061_t13;
    int64_t _1061_t14;
    int64_t* _1061_t15;
    struct struct1 _1062_z;
    int64_t _1061_t17;
    int64_t _1061_$retval;
    _1061_t1 = 0;
    _1061_t2 = 0;
    _1061_t3 = 0;
    _1061_t4 = 0;
    _1062_x = (struct struct0) {_1061_t1, _1061_t2, _1061_t3, _1061_t4};
    _1061_t6 = 0;
    _1061_t7 = 4;
    $bounds_check(_1061_t6, _1061_t7, "tests/integration/lint/subslice-bounds.orng:4:16:\n    let y = []x\n              ^");
    _1061_t8 = ((int64_t*)&_1062_x + _1061_t6);
    _1061_t9 = 4;
    _1062_y = (struct struct1) {_1061_t8, _1061_t9};
    _1061_t10 = _1063_f;
    $lines[$line_idx++] = "tests/integration/lint/subslice-bounds.orng:5:17:\n    let z = y[f()..1]\n               ^";
    _1061_t11 = _1061_t10();
    $line_idx--;
    _1061_t12 = 1;
    _1061_t13 = _1061_t11>_1061_t12;
    if (_1061_t13) {
        goto BB1255;
    } else {
        goto BB1256;
    }
BB1255:
    $lines[$line_idx++] = "tests/integration/lint/subslice-bounds.orng:5:15:\n    let z = y[f()..1]\n             ^";
    $panic("subslice lower bound is greater than upper bound\n");
BB1256:
    _1061_t14 = $sub_int64_t(_1061_t12, _1061_t11, "tests/integration/lint/subslice-bounds.orng:5:15:\n    let z = y[f()..1]\n             ^");
    _1061_t15 = _1062_y._0+_1061_t11;
    _1062_z = (struct struct1) {_1061_t15, _1061_t14};
    _1061_t17 = 0;
    $bounds_check(_1061_t17, _1062_z._1, "tests/integration/lint/subslice-bounds.orng:2:3:\nfn main() -> Int {\n ^");
    _1061_$retval = *((int64_t*)_1062_z._0 + _1061_t17);
    return _1061_$retval;
}

int64_t _1063_f(void){
    int64_t _1063_$retval;
    _1063_$retval = 2;
    return _1063_$retval;
}

int main(void) {
  printf("%ld",_1061_main());
  return 0;
}
