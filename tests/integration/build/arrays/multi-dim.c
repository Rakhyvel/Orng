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
int64_t _85_main(void);


/* Function definitions */
int64_t _85_main(void){
    int64_t _85_t2;
    int64_t _85_t3;
    int64_t _85_t4;
    struct struct0 _85_t1;
    int64_t _85_t6;
    int64_t _85_t7;
    int64_t _85_t8;
    struct struct0 _85_t5;
    int64_t _85_t10;
    int64_t _85_t11;
    int64_t _85_t12;
    struct struct0 _85_t9;
    struct struct1 _86_x;
    int64_t _85_t14;
    int64_t _85_t15;
    int64_t _85_t16;
    int64_t _85_t17;
    int64_t _85_t18;
    int64_t _85_t20;
    int64_t _85_t21;
    int64_t _85_t22;
    int64_t _85_t23;
    int64_t _85_t24;
    int64_t _85_t25;
    int64_t _85_t26;
    int64_t _85_t27;
    int64_t _85_$retval;
    _85_t2 = 1;
    _85_t3 = 2;
    _85_t4 = 3;
    _85_t1 = (struct struct0) {_85_t2, _85_t3, _85_t4};
    _85_t6 = 4;
    _85_t7 = 5;
    _85_t8 = 68;
    _85_t5 = (struct struct0) {_85_t6, _85_t7, _85_t8};
    _85_t10 = 7;
    _85_t11 = 8;
    _85_t12 = 9;
    _85_t9 = (struct struct0) {_85_t10, _85_t11, _85_t12};
    _86_x = (struct struct1) {_85_t1, _85_t5, _85_t9};
    _85_t14 = 1;
    _85_t15 = 3;
    _85_t16 = 2;
    _85_t17 = 3;
    _85_t18 = 1;
    _85_t20 = 1;
    _85_t21 = 3;
    _85_t22 = 2;
    _85_t23 = 3;
    $bounds_check(_85_t20, _85_t21, "tests/integration/arrays/multi-dim.orng:8:15:\n    x[1][2] += 1 // nice\n             ^");
    $bounds_check(_85_t22, _85_t23, "tests/integration/arrays/multi-dim.orng:8:15:\n    x[1][2] += 1 // nice\n             ^");
    $bounds_check(_85_t14, _85_t15, "tests/integration/arrays/multi-dim.orng:8:15:\n    x[1][2] += 1 // nice\n             ^");
    $bounds_check(_85_t16, _85_t17, "tests/integration/arrays/multi-dim.orng:8:15:\n    x[1][2] += 1 // nice\n             ^");
    *((int64_t*)((struct struct0*)&_86_x + _85_t20) + _85_t22) = $add_int64_t(*((int64_t*)((struct struct0*)&_86_x + _85_t14) + _85_t16), _85_t18, "tests/integration/arrays/multi-dim.orng:8:15:\n    x[1][2] += 1 // nice\n             ^");
    _85_t24 = 1;
    _85_t25 = 3;
    _85_t26 = 2;
    _85_t27 = 3;
    $bounds_check(_85_t24, _85_t25, "tests/integration/arrays/multi-dim.orng:2:8:\nfn main() -> Int {\n      ^");
    $bounds_check(_85_t26, _85_t27, "tests/integration/arrays/multi-dim.orng:2:8:\nfn main() -> Int {\n      ^");
    _85_$retval = *((int64_t*)((struct struct0*)&_86_x + _85_t24) + _85_t26);
    return _85_$retval;
}


int main(void) {
  printf("%ld",_85_main());
  return 0;
}
