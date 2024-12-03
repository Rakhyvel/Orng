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
int64_t _71_main(void);


/* Function definitions */
int64_t _71_main(void){
    int64_t _71_t2;
    int64_t _71_t3;
    int64_t _71_t4;
    struct struct0 _71_t1;
    int64_t _71_t6;
    int64_t _71_t7;
    int64_t _71_t8;
    struct struct0 _71_t5;
    int64_t _71_t10;
    int64_t _71_t11;
    int64_t _71_t12;
    struct struct0 _71_t9;
    struct struct1 _72_x;
    int64_t _71_t14;
    int64_t _71_t15;
    int64_t _71_t16;
    int64_t _71_t17;
    int64_t _71_t18;
    int64_t _71_t20;
    int64_t _71_t21;
    int64_t _71_t22;
    int64_t _71_t23;
    int64_t _71_t24;
    int64_t _71_t25;
    int64_t _71_t26;
    int64_t _71_t27;
    int64_t _71_$retval;
    _71_t2 = 1;
    _71_t3 = 2;
    _71_t4 = 3;
    _71_t1 = (struct struct0) {_71_t2, _71_t3, _71_t4};
    _71_t6 = 4;
    _71_t7 = 5;
    _71_t8 = 68;
    _71_t5 = (struct struct0) {_71_t6, _71_t7, _71_t8};
    _71_t10 = 7;
    _71_t11 = 8;
    _71_t12 = 9;
    _71_t9 = (struct struct0) {_71_t10, _71_t11, _71_t12};
    _72_x = (struct struct1) {_71_t1, _71_t5, _71_t9};
    _71_t14 = 1;
    _71_t15 = 3;
    _71_t16 = 2;
    _71_t17 = 3;
    _71_t18 = 1;
    _71_t20 = 1;
    _71_t21 = 3;
    _71_t22 = 2;
    _71_t23 = 3;
    $bounds_check(_71_t20, _71_t21, "tests/integration/arrays/multi-dim.orng:8:15:\n    x[1][2] += 1 // nice\n             ^");
    $bounds_check(_71_t22, _71_t23, "tests/integration/arrays/multi-dim.orng:8:15:\n    x[1][2] += 1 // nice\n             ^");
    $bounds_check(_71_t14, _71_t15, "tests/integration/arrays/multi-dim.orng:8:15:\n    x[1][2] += 1 // nice\n             ^");
    $bounds_check(_71_t16, _71_t17, "tests/integration/arrays/multi-dim.orng:8:15:\n    x[1][2] += 1 // nice\n             ^");
    *((int64_t*)((struct struct0*)&_72_x + _71_t20) + _71_t22) = $add_int64_t(*((int64_t*)((struct struct0*)&_72_x + _71_t14) + _71_t16), _71_t18, "tests/integration/arrays/multi-dim.orng:8:15:\n    x[1][2] += 1 // nice\n             ^");
    _71_t24 = 1;
    _71_t25 = 3;
    _71_t26 = 2;
    _71_t27 = 3;
    $bounds_check(_71_t24, _71_t25, "tests/integration/arrays/multi-dim.orng:2:8:\nfn main() -> Int {\n      ^");
    $bounds_check(_71_t26, _71_t27, "tests/integration/arrays/multi-dim.orng:2:8:\nfn main() -> Int {\n      ^");
    _71_$retval = *((int64_t*)((struct struct0*)&_72_x + _71_t24) + _71_t26);
    return _71_$retval;
}


int main(void) {
  printf("%ld",_71_main());
  return 0;
}
