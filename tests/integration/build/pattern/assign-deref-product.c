/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward typedefs */
struct struct0;

/* Typedefs */
struct struct0 {
    int64_t _0;
    int64_t _1;
    int64_t _2;
};

/* Function forward definitions */
int64_t _1137_main(void);

/* Function definitions */
int64_t _1137_main(void){
    int64_t _1137_t1;
    int64_t _1137_t2;
    int64_t _1137_t3;
    struct struct0 _1138_x;
    int64_t _1137_t4;
    int64_t _1137_t5;
    int64_t* _1138_a;
    int64_t _1137_t7;
    int64_t _1137_t8;
    int64_t* _1138_b;
    int64_t _1137_t10;
    int64_t _1137_t11;
    int64_t* _1138_c;
    int64_t _1137_t14;
    int64_t _1137_t15;
    int64_t _1137_t16;
    struct struct0 _1137_t13;
    int64_t _1137_t17;
    int64_t _1137_$retval;
    _1137_t1 = 0;
    _1137_t2 = 0;
    _1137_t3 = 0;
    _1138_x = (struct struct0) {_1137_t1, _1137_t2, _1137_t3};
    _1137_t4 = 0;
    _1137_t5 = 3;
    $bounds_check(_1137_t4, _1137_t5, "tests/integration/pattern/assign-deref-product.orng:4:14:\n    let a = &mut x[0]\n            ^");
    _1138_a = ((int64_t*)&_1138_x + _1137_t4);
    _1137_t7 = 1;
    _1137_t8 = 3;
    $bounds_check(_1137_t7, _1137_t8, "tests/integration/pattern/assign-deref-product.orng:5:14:\n    let b = &mut x[1]\n            ^");
    _1138_b = ((int64_t*)&_1138_x + _1137_t7);
    _1137_t10 = 2;
    _1137_t11 = 3;
    $bounds_check(_1137_t10, _1137_t11, "tests/integration/pattern/assign-deref-product.orng:6:14:\n    let c = &mut x[2]\n            ^");
    _1138_c = ((int64_t*)&_1138_x + _1137_t10);
    _1137_t14 = 100;
    _1137_t15 = 30;
    _1137_t16 = 30;
    _1137_t13 = (struct struct0) {_1137_t14, _1137_t15, _1137_t16};
    *_1138_a = _1137_t13._0;
    *_1138_b = _1137_t13._1;
    *_1138_c = _1137_t13._2;
    _1137_t17 = $add_int64_t(*_1138_a, *_1138_b, "tests/integration/pattern/assign-deref-product.orng:8:9:\n    a^ + b^ + c^\n       ^");
    _1137_$retval = $add_int64_t(_1137_t17, *_1138_c, "tests/integration/pattern/assign-deref-product.orng:8:14:\n    a^ + b^ + c^\n            ^");
    return _1137_$retval;
}

int main(void) {
  printf("%ld",_1137_main());
  return 0;
}
