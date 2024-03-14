/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward struct, union, and function declarations */
struct struct0;

/* Struct, union, and function definitions */
struct struct0 {
    int64_t _0;
    int64_t _1;
    int64_t _2;
};

/* Function forward definitions */
int64_t _1167_main(void);


/* Function definitions */
int64_t _1167_main(void){
    int64_t _1167_t1;
    int64_t _1167_t2;
    int64_t _1167_t3;
    struct struct0 _1168_x;
    int64_t _1167_t5;
    int64_t _1167_t6;
    int64_t* _1168_a;
    int64_t _1167_t9;
    int64_t _1167_t10;
    int64_t* _1168_b;
    int64_t _1167_t13;
    int64_t _1167_t14;
    int64_t* _1168_c;
    int64_t _1167_t18;
    int64_t _1167_t19;
    int64_t _1167_t20;
    struct struct0 _1167_t17;
    int64_t _1167_t21;
    int64_t _1167_$retval;
    _1167_t1 = 0;
    _1167_t2 = 0;
    _1167_t3 = 0;
    _1168_x = (struct struct0) {_1167_t1, _1167_t2, _1167_t3};
    _1167_t5 = 0;
    _1167_t6 = 3;
    $bounds_check(_1167_t5, _1167_t6, "tests/integration/pattern/assign-deref-product.orng:4:14:\n    let a = &mut x[0]\n            ^");
    _1168_a = ((int64_t*)&_1168_x + _1167_t5);
    _1167_t9 = 1;
    _1167_t10 = 3;
    $bounds_check(_1167_t9, _1167_t10, "tests/integration/pattern/assign-deref-product.orng:5:14:\n    let b = &mut x[1]\n            ^");
    _1168_b = ((int64_t*)&_1168_x + _1167_t9);
    _1167_t13 = 2;
    _1167_t14 = 3;
    $bounds_check(_1167_t13, _1167_t14, "tests/integration/pattern/assign-deref-product.orng:6:14:\n    let c = &mut x[2]\n            ^");
    _1168_c = ((int64_t*)&_1168_x + _1167_t13);
    _1167_t18 = 100;
    _1167_t19 = 30;
    _1167_t20 = 30;
    _1167_t17 = (struct struct0) {_1167_t18, _1167_t19, _1167_t20};
    *_1168_a = _1167_t17._0;
    *_1168_b = _1167_t17._1;
    *_1168_c = _1167_t17._2;
    _1167_t21 = $add_int64_t(*_1168_a, *_1168_b, "tests/integration/pattern/assign-deref-product.orng:8:9:\n    a^ + b^ + c^\n       ^");
    _1167_$retval = $add_int64_t(_1167_t21, *_1168_c, "tests/integration/pattern/assign-deref-product.orng:8:14:\n    a^ + b^ + c^\n            ^");
    return _1167_$retval;
}


int main(void) {
  printf("%ld",_1167_main());
  return 0;
}
