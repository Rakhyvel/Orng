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

/* Function forward definitions */
int64_t _1287_main(void);

/* Function definitions */
int64_t _1287_main(void){
    int64_t _1287_t1;
    int64_t _1287_t2;
    int64_t _1287_t3;
    struct0 _1288_x;
    int64_t _1287_t4;
    int64_t _1287_t5;
    int64_t* _1288_a;
    int64_t _1287_t7;
    int64_t _1287_t8;
    int64_t* _1288_b;
    int64_t _1287_t10;
    int64_t _1287_t11;
    int64_t* _1288_c;
    int64_t _1287_t14;
    int64_t _1287_t15;
    int64_t _1287_t16;
    struct0 _1287_t13;
    int64_t _1287_t17;
    int64_t _1287_$retval;
    _1287_t1 = 0;
    _1287_t2 = 0;
    _1287_t3 = 0;
    _1288_x = (struct0) {_1287_t1, _1287_t2, _1287_t3};
    _1287_t4 = 0;
    _1287_t5 = 3;
    $bounds_check(_1287_t4, _1287_t5, "tests/integration/pattern/assign-deref-product.orng:4:14:\n    let a = &mut x[0]\n            ^");
    _1288_a = ((int64_t*)&_1288_x + _1287_t4);
    _1287_t7 = 1;
    _1287_t8 = 3;
    $bounds_check(_1287_t7, _1287_t8, "tests/integration/pattern/assign-deref-product.orng:5:14:\n    let b = &mut x[1]\n            ^");
    _1288_b = ((int64_t*)&_1288_x + _1287_t7);
    _1287_t10 = 2;
    _1287_t11 = 3;
    $bounds_check(_1287_t10, _1287_t11, "tests/integration/pattern/assign-deref-product.orng:6:14:\n    let c = &mut x[2]\n            ^");
    _1288_c = ((int64_t*)&_1288_x + _1287_t10);
    _1287_t14 = 100;
    _1287_t15 = 30;
    _1287_t16 = 30;
    _1287_t13 = (struct0) {_1287_t14, _1287_t15, _1287_t16};
    *_1288_a = _1287_t13._0;
    *_1288_b = _1287_t13._1;
    *_1288_c = _1287_t13._2;
    _1287_t17 = $add_int64_t(*_1288_a, *_1288_b, "tests/integration/pattern/assign-deref-product.orng:8:9:\n    a^ + b^ + c^\n       ^");
    _1287_$retval = $add_int64_t(_1287_t17, *_1288_c, "tests/integration/pattern/assign-deref-product.orng:8:14:\n    a^ + b^ + c^\n            ^");
    return _1287_$retval;
}

int main(void) {
  printf("%ld",_1287_main());
  return 0;
}
