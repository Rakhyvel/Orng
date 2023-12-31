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
int64_t _1058_main(void);
int64_t _1060_f(void);

/* Function definitions */
int64_t _1058_main(void){
    int64_t _1058_t1;
    int64_t _1058_t2;
    int64_t _1058_t3;
    int64_t _1058_t4;
    struct struct0 _1059_x;
    int64_t _1058_t6;
    int64_t _1058_t7;
    int64_t* _1058_t8;
    int64_t _1058_t9;
    struct struct1 _1059_y;
    function2 _1058_t10;
    int64_t _1058_t11;
    int64_t _1058_t12;
    uint8_t _1058_t13;
    int64_t _1058_t14;
    int64_t* _1058_t15;
    struct struct1 _1059_z;
    int64_t _1058_t17;
    int64_t _1058_$retval;
    _1058_t1 = 0;
    _1058_t2 = 0;
    _1058_t3 = 0;
    _1058_t4 = 0;
    _1059_x = (struct struct0) {_1058_t1, _1058_t2, _1058_t3, _1058_t4};
    _1058_t6 = 0;
    _1058_t7 = 4;
    $bounds_check(_1058_t6, _1058_t7, "tests/integration/lint/subslice-bounds.orng:4:16:\n    let y = []x\n              ^");
    _1058_t8 = ((int64_t*)&_1059_x + _1058_t6);
    _1058_t9 = 4;
    _1059_y = (struct struct1) {_1058_t8, _1058_t9};
    _1058_t10 = _1060_f;
    $lines[$line_idx++] = "tests/integration/lint/subslice-bounds.orng:5:17:\n    let z = y[f()..1]\n               ^";
    _1058_t11 = _1058_t10();
    $line_idx--;
    _1058_t12 = 1;
    _1058_t13 = _1058_t11>_1058_t12;
    if (_1058_t13) {
        goto BB1263;
    } else {
        goto BB1264;
    }
BB1263:
    $lines[$line_idx++] = "tests/integration/lint/subslice-bounds.orng:5:15:\n    let z = y[f()..1]\n             ^";
    $panic("subslice lower bound is greater than upper bound\n");
BB1264:
    _1058_t14 = $sub_int64_t(_1058_t12, _1058_t11, "tests/integration/lint/subslice-bounds.orng:5:15:\n    let z = y[f()..1]\n             ^");
    _1058_t15 = _1059_y._0+_1058_t11;
    _1059_z = (struct struct1) {_1058_t15, _1058_t14};
    _1058_t17 = 0;
    $bounds_check(_1058_t17, _1059_z._1, "tests/integration/lint/subslice-bounds.orng:2:3:\nfn main() -> Int {\n ^");
    _1058_$retval = *((int64_t*)_1059_z._0 + _1058_t17);
    return _1058_$retval;
}

int64_t _1060_f(void){
    int64_t _1060_$retval;
    _1060_$retval = 2;
    return _1060_$retval;
}

int main(void) {
  printf("%ld",_1058_main());
  return 0;
}
