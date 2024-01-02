/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward typedefs */
struct struct0;
struct struct1;
struct struct2;
struct struct3;

/* Typedefs */
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
int64_t _1327_main(void);

/* Function definitions */
int64_t _1327_main(void){
    int64_t _1327_t1;
    int64_t _1327_t2;
    int64_t _1327_t3;
    struct struct0 _1328_x;
    int64_t _1327_t6;
    int64_t _1327_t7;
    int64_t* _1327_t8;
    int64_t _1327_t9;
    struct struct1 _1327_t5;
    int64_t _1327_t11;
    int64_t _1327_t12;
    int64_t* _1327_t13;
    int64_t _1327_t14;
    struct struct1 _1327_t10;
    int64_t _1327_t16;
    int64_t _1327_t17;
    int64_t* _1327_t18;
    int64_t _1327_t19;
    struct struct1 _1327_t15;
    struct struct2 _1328_y;
    int64_t _1327_t21;
    int64_t _1327_t22;
    struct struct1* _1327_t23;
    int64_t _1327_t24;
    struct struct3 _1328_z;
    int64_t _1327_t26;
    int64_t _1327_t27;
    int64_t _1327_t28;
    int64_t _1327_t29;
    int64_t _1327_$retval;
    _1327_t1 = 1;
    _1327_t2 = 2;
    _1327_t3 = 3;
    _1328_x = (struct struct0) {_1327_t1, _1327_t2, _1327_t3};
    _1327_t6 = 0;
    _1327_t7 = 3;
    $bounds_check(_1327_t6, _1327_t7, "tests/integration/slices/multi-dim.orng:4:37:\n    let mut y: [3][mut]Int = ([mut]x, [mut]x, [mut]x)\n                                   ^");
    _1327_t8 = ((int64_t*)&_1328_x + _1327_t6);
    _1327_t9 = 3;
    _1327_t5 = (struct struct1) {_1327_t8, _1327_t9};
    _1327_t11 = 0;
    _1327_t12 = 3;
    $bounds_check(_1327_t11, _1327_t12, "tests/integration/slices/multi-dim.orng:4:45:\n    let mut y: [3][mut]Int = ([mut]x, [mut]x, [mut]x)\n                                           ^");
    _1327_t13 = ((int64_t*)&_1328_x + _1327_t11);
    _1327_t14 = 3;
    _1327_t10 = (struct struct1) {_1327_t13, _1327_t14};
    _1327_t16 = 0;
    _1327_t17 = 3;
    $bounds_check(_1327_t16, _1327_t17, "tests/integration/slices/multi-dim.orng:4:53:\n    let mut y: [3][mut]Int = ([mut]x, [mut]x, [mut]x)\n                                                   ^");
    _1327_t18 = ((int64_t*)&_1328_x + _1327_t16);
    _1327_t19 = 3;
    _1327_t15 = (struct struct1) {_1327_t18, _1327_t19};
    _1328_y = (struct struct2) {_1327_t5, _1327_t10, _1327_t15};
    _1327_t21 = 0;
    _1327_t22 = 3;
    $bounds_check(_1327_t21, _1327_t22, "tests/integration/slices/multi-dim.orng:5:34:\n    let z: [mut][mut]Int = [mut]y\n                                ^");
    _1327_t23 = ((struct struct1*)&_1328_y + _1327_t21);
    _1327_t24 = 3;
    _1328_z = (struct struct3) {_1327_t23, _1327_t24};
    _1327_t26 = 1;
    _1327_t27 = 2;
    $bounds_check(_1327_t26, _1328_z._1, "tests/integration/slices/multi-dim.orng:6:17:\n    z[1][2] = 82\n               ^");
    $bounds_check(_1327_t27, (*((struct struct1*)_1328_z._0 + _1327_t26))._1, "tests/integration/slices/multi-dim.orng:6:17:\n    z[1][2] = 82\n               ^");
    *((int64_t*)(*((struct struct1*)_1328_z._0 + _1327_t26))._0 + _1327_t27) = 82;
    _1327_t28 = 1;
    _1327_t29 = 2;
    $bounds_check(_1327_t28, _1328_z._1, "tests/integration/slices/multi-dim.orng:2:3:\nfn main() -> Int {\n ^");
    $bounds_check(_1327_t29, (*((struct struct1*)_1328_z._0 + _1327_t28))._1, "tests/integration/slices/multi-dim.orng:2:3:\nfn main() -> Int {\n ^");
    _1327_$retval = *((int64_t*)(*((struct struct1*)_1328_z._0 + _1327_t28))._0 + _1327_t29);
    return _1327_$retval;
}

int main(void) {
  printf("%ld",_1327_main());
  return 0;
}
