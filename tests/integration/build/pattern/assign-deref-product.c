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
int64_t _1211_main(void);


/* Function definitions */
int64_t _1211_main(void){
    int64_t _1211_t1;
    int64_t _1211_t2;
    int64_t _1211_t3;
    struct struct0 _1212_x;
    int64_t _1211_t5;
    int64_t _1211_t6;
    int64_t* _1212_a;
    int64_t _1211_t9;
    int64_t _1211_t10;
    int64_t* _1212_b;
    int64_t _1211_t13;
    int64_t _1211_t14;
    int64_t* _1212_c;
    int64_t _1211_t18;
    int64_t _1211_t19;
    int64_t _1211_t20;
    struct struct0 _1211_t17;
    int64_t _1211_t21;
    int64_t _1211_$retval;
    _1211_t1 = 0;
    _1211_t2 = 0;
    _1211_t3 = 0;
    _1212_x = (struct struct0) {_1211_t1, _1211_t2, _1211_t3};
    _1211_t5 = 0;
    _1211_t6 = 3;
    $bounds_check(_1211_t5, _1211_t6, "tests/integration/pattern/assign-deref-product.orng:4:14:\n    let a = &mut x[0]\n            ^");
    _1212_a = ((int64_t*)&_1212_x + _1211_t5);
    _1211_t9 = 1;
    _1211_t10 = 3;
    $bounds_check(_1211_t9, _1211_t10, "tests/integration/pattern/assign-deref-product.orng:5:14:\n    let b = &mut x[1]\n            ^");
    _1212_b = ((int64_t*)&_1212_x + _1211_t9);
    _1211_t13 = 2;
    _1211_t14 = 3;
    $bounds_check(_1211_t13, _1211_t14, "tests/integration/pattern/assign-deref-product.orng:6:14:\n    let c = &mut x[2]\n            ^");
    _1212_c = ((int64_t*)&_1212_x + _1211_t13);
    _1211_t18 = 100;
    _1211_t19 = 30;
    _1211_t20 = 30;
    _1211_t17 = (struct struct0) {_1211_t18, _1211_t19, _1211_t20};
    *_1212_a = _1211_t17._0;
    *_1212_b = _1211_t17._1;
    *_1212_c = _1211_t17._2;
    _1211_t21 = $add_int64_t(*_1212_a, *_1212_b, "tests/integration/pattern/assign-deref-product.orng:8:9:\n    a^ + b^ + c^\n       ^");
    _1211_$retval = $add_int64_t(_1211_t21, *_1212_c, "tests/integration/pattern/assign-deref-product.orng:8:14:\n    a^ + b^ + c^\n            ^");
    return _1211_$retval;
}


int main(void) {
  printf("%ld",_1211_main());
  return 0;
}
