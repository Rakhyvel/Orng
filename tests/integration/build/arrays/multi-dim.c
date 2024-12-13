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
};

struct struct1 {
    struct struct0 _0;
    struct struct0 _1;
    struct struct0 _2;
};

/* Function forward definitions */
int64_t _89_main(void);


/* Function definitions */
int64_t _89_main(void){
    int64_t _89_t2;
    int64_t _89_t3;
    int64_t _89_t4;
    struct struct0 _89_t1;
    int64_t _89_t6;
    int64_t _89_t7;
    int64_t _89_t8;
    struct struct0 _89_t5;
    int64_t _89_t10;
    int64_t _89_t11;
    int64_t _89_t12;
    struct struct0 _89_t9;
    struct struct1 _90_x;
    int64_t _89_t14;
    int64_t _89_t15;
    int64_t _89_t16;
    int64_t _89_t17;
    int64_t _89_t18;
    int64_t _89_t20;
    int64_t _89_t21;
    int64_t _89_t22;
    int64_t _89_t23;
    int64_t _89_t24;
    int64_t _89_t25;
    int64_t _89_t26;
    int64_t _89_t27;
    int64_t _89_$retval;
    _89_t2 = 1;
    _89_t3 = 2;
    _89_t4 = 3;
    _89_t1 = (struct struct0) {_89_t2, _89_t3, _89_t4};
    _89_t6 = 4;
    _89_t7 = 5;
    _89_t8 = 68;
    _89_t5 = (struct struct0) {_89_t6, _89_t7, _89_t8};
    _89_t10 = 7;
    _89_t11 = 8;
    _89_t12 = 9;
    _89_t9 = (struct struct0) {_89_t10, _89_t11, _89_t12};
    _90_x = (struct struct1) {_89_t1, _89_t5, _89_t9};
    _89_t14 = 1;
    _89_t15 = 3;
    _89_t16 = 2;
    _89_t17 = 3;
    _89_t18 = 1;
    _89_t20 = 1;
    _89_t21 = 3;
    _89_t22 = 2;
    _89_t23 = 3;
    $bounds_check(_89_t20, _89_t21, "tests/integration/arrays/multi-dim.orng:8:15:\n    x[1][2] += 1 // nice\n             ^");
    $bounds_check(_89_t22, _89_t23, "tests/integration/arrays/multi-dim.orng:8:15:\n    x[1][2] += 1 // nice\n             ^");
    $bounds_check(_89_t14, _89_t15, "tests/integration/arrays/multi-dim.orng:8:15:\n    x[1][2] += 1 // nice\n             ^");
    $bounds_check(_89_t16, _89_t17, "tests/integration/arrays/multi-dim.orng:8:15:\n    x[1][2] += 1 // nice\n             ^");
    *((int64_t*)((struct struct0*)&_90_x + _89_t20) + _89_t22) = $add_int64_t(*((int64_t*)((struct struct0*)&_90_x + _89_t14) + _89_t16), _89_t18, "tests/integration/arrays/multi-dim.orng:8:15:\n    x[1][2] += 1 // nice\n             ^");
    _89_t24 = 1;
    _89_t25 = 3;
    _89_t26 = 2;
    _89_t27 = 3;
    $bounds_check(_89_t24, _89_t25, "tests/integration/arrays/multi-dim.orng:2:8:\nfn main() -> Int {\n      ^");
    $bounds_check(_89_t26, _89_t27, "tests/integration/arrays/multi-dim.orng:2:8:\nfn main() -> Int {\n      ^");
    _89_$retval = *((int64_t*)((struct struct0*)&_90_x + _89_t24) + _89_t26);
    return _89_$retval;
}


int main(void) {
  printf("%ld",_89_main());
  return 0;
}
