/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward struct, union, and function declarations */
struct struct0;
struct struct1;
struct struct2;
struct struct3;

/* Struct, union, and function definitions */
struct struct0 {
    int64_t _0;
    int64_t _1;
    int64_t _2;
};

struct struct1 {
    int64_t* _0;
    int64_t _1;
};

struct struct2 {
    struct struct1 _0;
    struct struct1 _1;
    struct struct1 _2;
};

struct struct3 {
    struct struct1* _0;
    int64_t _1;
};

/* Function forward definitions */
int64_t _1374_main(void);


/* Function definitions */
int64_t _1374_main(void){
    int64_t _1374_t1;
    int64_t _1374_t2;
    int64_t _1374_t3;
    struct struct0 _1375_x;
    int64_t _1374_t6;
    int64_t _1374_t7;
    int64_t* _1374_t8;
    int64_t _1374_t9;
    struct struct1 _1374_t5;
    int64_t _1374_t11;
    int64_t _1374_t12;
    int64_t* _1374_t13;
    int64_t _1374_t14;
    struct struct1 _1374_t10;
    int64_t _1374_t16;
    int64_t _1374_t17;
    int64_t* _1374_t18;
    int64_t _1374_t19;
    struct struct1 _1374_t15;
    struct struct2 _1375_y;
    int64_t _1374_t21;
    int64_t _1374_t22;
    struct struct1* _1374_t23;
    int64_t _1374_t24;
    struct struct3 _1375_z;
    int64_t _1374_t26;
    int64_t _1374_t27;
    int64_t _1374_t28;
    int64_t _1374_t29;
    int64_t _1374_$retval;
    _1374_t1 = 1;
    _1374_t2 = 2;
    _1374_t3 = 3;
    _1375_x = (struct struct0) {_1374_t1, _1374_t2, _1374_t3};
    _1374_t6 = 0;
    _1374_t7 = 3;
    $bounds_check(_1374_t6, _1374_t7, "tests/integration/slices/multi-dim.orng:4:37:\n    let mut y: [3][mut]Int = ([mut]x, [mut]x, [mut]x)\n                                   ^");
    _1374_t8 = ((int64_t*)&_1375_x + _1374_t6);
    _1374_t9 = 3;
    _1374_t5 = (struct struct1) {_1374_t8, _1374_t9};
    _1374_t11 = 0;
    _1374_t12 = 3;
    $bounds_check(_1374_t11, _1374_t12, "tests/integration/slices/multi-dim.orng:4:45:\n    let mut y: [3][mut]Int = ([mut]x, [mut]x, [mut]x)\n                                           ^");
    _1374_t13 = ((int64_t*)&_1375_x + _1374_t11);
    _1374_t14 = 3;
    _1374_t10 = (struct struct1) {_1374_t13, _1374_t14};
    _1374_t16 = 0;
    _1374_t17 = 3;
    $bounds_check(_1374_t16, _1374_t17, "tests/integration/slices/multi-dim.orng:4:53:\n    let mut y: [3][mut]Int = ([mut]x, [mut]x, [mut]x)\n                                                   ^");
    _1374_t18 = ((int64_t*)&_1375_x + _1374_t16);
    _1374_t19 = 3;
    _1374_t15 = (struct struct1) {_1374_t18, _1374_t19};
    _1375_y = (struct struct2) {_1374_t5, _1374_t10, _1374_t15};
    _1374_t21 = 0;
    _1374_t22 = 3;
    $bounds_check(_1374_t21, _1374_t22, "tests/integration/slices/multi-dim.orng:5:34:\n    let z: [mut][mut]Int = [mut]y\n                                ^");
    _1374_t23 = ((struct struct1*)&_1375_y + _1374_t21);
    _1374_t24 = 3;
    _1375_z = (struct struct3) {_1374_t23, _1374_t24};
    _1374_t26 = 1;
    _1374_t27 = 2;
    $bounds_check(_1374_t26, _1375_z._1, "tests/integration/slices/multi-dim.orng:6:17:\n    z[1][2] = 82\n               ^");
    $bounds_check(_1374_t27, (*((struct struct1*)_1375_z._0 + _1374_t26))._1, "tests/integration/slices/multi-dim.orng:6:17:\n    z[1][2] = 82\n               ^");
    *((int64_t*)(*((struct struct1*)_1375_z._0 + _1374_t26))._0 + _1374_t27) = 82;
    _1374_t28 = 1;
    _1374_t29 = 2;
    $bounds_check(_1374_t28, _1375_z._1, "tests/integration/slices/multi-dim.orng:2:3:\nfn main() -> Int {\n ^");
    $bounds_check(_1374_t29, (*((struct struct1*)_1375_z._0 + _1374_t28))._1, "tests/integration/slices/multi-dim.orng:2:3:\nfn main() -> Int {\n ^");
    _1374_$retval = *((int64_t*)(*((struct struct1*)_1375_z._0 + _1374_t28))._0 + _1374_t29);
    return _1374_$retval;
}


int main(void) {
  printf("%ld",_1374_main());
  return 0;
}
