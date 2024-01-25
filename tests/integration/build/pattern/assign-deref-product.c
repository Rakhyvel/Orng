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
int64_t _1164_main(void);


/* Function definitions */
int64_t _1164_main(void){
    int64_t _1164_t1;
    int64_t _1164_t2;
    int64_t _1164_t3;
    struct struct0 _1165_x;
    int64_t _1164_t4;
    int64_t _1164_t5;
    int64_t* _1165_a;
    int64_t _1164_t7;
    int64_t _1164_t8;
    int64_t* _1165_b;
    int64_t _1164_t10;
    int64_t _1164_t11;
    int64_t* _1165_c;
    int64_t _1164_t14;
    int64_t _1164_t15;
    int64_t _1164_t16;
    struct struct0 _1164_t13;
    int64_t _1164_t17;
    int64_t _1164_$retval;
    _1164_t1 = 0;
    _1164_t2 = 0;
    _1164_t3 = 0;
    _1165_x = (struct struct0) {_1164_t1, _1164_t2, _1164_t3};
    _1164_t4 = 0;
    _1164_t5 = 3;
    $bounds_check(_1164_t4, _1164_t5, "tests/integration/pattern/assign-deref-product.orng:4:14:\n    let a = &mut x[0]\n            ^");
    _1165_a = ((int64_t*)&_1165_x + _1164_t4);
    _1164_t7 = 1;
    _1164_t8 = 3;
    $bounds_check(_1164_t7, _1164_t8, "tests/integration/pattern/assign-deref-product.orng:5:14:\n    let b = &mut x[1]\n            ^");
    _1165_b = ((int64_t*)&_1165_x + _1164_t7);
    _1164_t10 = 2;
    _1164_t11 = 3;
    $bounds_check(_1164_t10, _1164_t11, "tests/integration/pattern/assign-deref-product.orng:6:14:\n    let c = &mut x[2]\n            ^");
    _1165_c = ((int64_t*)&_1165_x + _1164_t10);
    _1164_t14 = 100;
    _1164_t15 = 30;
    _1164_t16 = 30;
    _1164_t13 = (struct struct0) {_1164_t14, _1164_t15, _1164_t16};
    *_1165_a = _1164_t13._0;
    *_1165_b = _1164_t13._1;
    *_1165_c = _1164_t13._2;
    _1164_t17 = $add_int64_t(*_1165_a, *_1165_b, "tests/integration/pattern/assign-deref-product.orng:8:9:\n    a^ + b^ + c^\n       ^");
    _1164_$retval = $add_int64_t(_1164_t17, *_1165_c, "tests/integration/pattern/assign-deref-product.orng:8:14:\n    a^ + b^ + c^\n            ^");
    return _1164_$retval;
}


int main(void) {
  printf("%ld",_1164_main());
  return 0;
}
