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
        int64_t _3;
} struct0;

typedef struct {
        int64_t* _0;
        int64_t _1;
} struct1;

typedef int64_t(*function2)(void);

/* Function forward definitions */
int64_t _1045_main(void);
int64_t _1047_f(void);

/* Function definitions */
int64_t _1045_main(void){
    int64_t _1045_t1;
    int64_t _1045_t2;
    int64_t _1045_t3;
    int64_t _1045_t4;
    struct0 _1046_x;
    int64_t _1045_t6;
    int64_t _1045_t7;
    int64_t* _1045_t8;
    int64_t _1045_t9;
    struct1 _1046_y;
    function2 _1045_t10;
    int64_t _1045_t11;
    int64_t _1045_t12;
    uint8_t _1045_t13;
    int64_t _1045_t14;
    int64_t* _1045_t15;
    struct1 _1046_z;
    int64_t _1045_t17;
    int64_t _1045_$retval;
    _1045_t1 = 0;
    _1045_t2 = 0;
    _1045_t3 = 0;
    _1045_t4 = 0;
    _1046_x = (struct0) {_1045_t1, _1045_t2, _1045_t3, _1045_t4};
    _1045_t6 = 0;
    _1045_t7 = 4;
    $bounds_check(_1045_t6, _1045_t7, "tests/integration/lint/subslice-bounds.orng:4:16:\n    let y = []x\n              ^");
    _1045_t8 = ((int64_t*)&_1046_x + _1045_t6);
    _1045_t9 = 4;
    _1046_y = (struct1) {_1045_t8, _1045_t9};
    _1045_t10 = _1047_f;
    $lines[$line_idx++] = "tests/integration/lint/subslice-bounds.orng:5:17:\n    let z = y[f()..1]\n               ^";
    _1045_t11 = _1045_t10();
    $line_idx--;
    _1045_t12 = 1;
    _1045_t13 = _1045_t11>_1045_t12;
    if (_1045_t13) {
        goto BB1253;
    } else {
        goto BB1254;
    }
BB1253:
    $lines[$line_idx++] = "tests/integration/lint/subslice-bounds.orng:5:15:\n    let z = y[f()..1]\n             ^";
    $panic("subslice lower bound is greater than upper bound\n");
BB1254:
    _1045_t14 = $sub_int64_t(_1045_t12, _1045_t11, "tests/integration/lint/subslice-bounds.orng:5:15:\n    let z = y[f()..1]\n             ^");
    _1045_t15 = _1046_y._0+_1045_t11;
    _1046_z = (struct1) {_1045_t15, _1045_t14};
    _1045_t17 = 0;
    $bounds_check(_1045_t17, _1046_z._1, "tests/integration/lint/subslice-bounds.orng:2:3:\nfn main() -> Int {\n ^");
    _1045_$retval = *((int64_t*)_1046_z._0 + _1045_t17);
    return _1045_$retval;
}

int64_t _1047_f(void){
    int64_t _1047_$retval;
    _1047_$retval = 2;
    return _1047_$retval;
}

int main(void) {
  printf("%ld",_1045_main());
  return 0;
}
