/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef struct {
    int64_t _0;
    int64_t _1;
    int64_t _2;
} struct0;

typedef struct {
    int64_t* _0;
    int64_t _1;
} struct1;

typedef struct {
    struct1 _0;
    struct1 _1;
    struct1 _2;
} struct2;

typedef struct {
    struct1* _0;
    int64_t _1;
} struct3;

/* Function forward definitions */
int64_t _1300_main(void);

/* Function definitions */
int64_t _1300_main(void){
    int64_t _1300_t1;
    int64_t _1300_t2;
    int64_t _1300_t3;
    struct0 _1301_x;
    int64_t _1300_t6;
    int64_t _1300_t7;
    int64_t* _1300_t8;
    int64_t _1300_t9;
    struct1 _1300_t5;
    int64_t _1300_t11;
    int64_t _1300_t12;
    int64_t* _1300_t13;
    int64_t _1300_t14;
    struct1 _1300_t10;
    int64_t _1300_t16;
    int64_t _1300_t17;
    int64_t* _1300_t18;
    int64_t _1300_t19;
    struct1 _1300_t15;
    struct2 _1301_y;
    int64_t _1300_t21;
    int64_t _1300_t22;
    struct1* _1300_t23;
    int64_t _1300_t24;
    struct3 _1301_z;
    int64_t _1300_t26;
    int64_t _1300_t27;
    int64_t _1300_t28;
    int64_t _1300_t29;
    int64_t _1300_$retval;
    _1300_t1 = 1;
    _1300_t2 = 2;
    _1300_t3 = 3;
    _1301_x = (struct0) {_1300_t1, _1300_t2, _1300_t3};
    _1300_t6 = 0;
    _1300_t7 = 3;
    $bounds_check(_1300_t6, _1300_t7, "tests/integration/slices/multi-dim.orng:4:37:\n    let mut y: [3][mut]Int = ([mut]x, [mut]x, [mut]x)\n                                   ^");
    _1300_t8 = ((int64_t*)&_1301_x + _1300_t6);
    _1300_t9 = 3;
    _1300_t5 = (struct1) {_1300_t8, _1300_t9};
    _1300_t11 = 0;
    _1300_t12 = 3;
    $bounds_check(_1300_t11, _1300_t12, "tests/integration/slices/multi-dim.orng:4:45:\n    let mut y: [3][mut]Int = ([mut]x, [mut]x, [mut]x)\n                                           ^");
    _1300_t13 = ((int64_t*)&_1301_x + _1300_t11);
    _1300_t14 = 3;
    _1300_t10 = (struct1) {_1300_t13, _1300_t14};
    _1300_t16 = 0;
    _1300_t17 = 3;
    $bounds_check(_1300_t16, _1300_t17, "tests/integration/slices/multi-dim.orng:4:53:\n    let mut y: [3][mut]Int = ([mut]x, [mut]x, [mut]x)\n                                                   ^");
    _1300_t18 = ((int64_t*)&_1301_x + _1300_t16);
    _1300_t19 = 3;
    _1300_t15 = (struct1) {_1300_t18, _1300_t19};
    _1301_y = (struct2) {_1300_t5, _1300_t10, _1300_t15};
    _1300_t21 = 0;
    _1300_t22 = 3;
    $bounds_check(_1300_t21, _1300_t22, "tests/integration/slices/multi-dim.orng:5:34:\n    let z: [mut][mut]Int = [mut]y\n                                ^");
    _1300_t23 = ((struct1*)&_1301_y + _1300_t21);
    _1300_t24 = 3;
    _1301_z = (struct3) {_1300_t23, _1300_t24};
    _1300_t26 = 1;
    _1300_t27 = 2;
    $bounds_check(_1300_t26, _1301_z._1, "tests/integration/slices/multi-dim.orng:6:17:\n    z[1][2] = 82\n               ^");
    $bounds_check(_1300_t27, (*((struct1*)_1301_z._0 + _1300_t26))._1, "tests/integration/slices/multi-dim.orng:6:17:\n    z[1][2] = 82\n               ^");
    *((int64_t*)(*((struct1*)_1301_z._0 + _1300_t26))._0 + _1300_t27) = 82;
    _1300_t28 = 1;
    _1300_t29 = 2;
    $bounds_check(_1300_t28, _1301_z._1, "tests/integration/slices/multi-dim.orng:2:3:\nfn main() -> Int {\n ^");
    $bounds_check(_1300_t29, (*((struct1*)_1301_z._0 + _1300_t28))._1, "tests/integration/slices/multi-dim.orng:2:3:\nfn main() -> Int {\n ^");
    _1300_$retval = *((int64_t*)(*((struct1*)_1301_z._0 + _1300_t28))._0 + _1300_t29);
    return _1300_$retval;
}

int main(void) {
  printf("%ld",_1300_main());
  return 0;
}
