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
int64_t _1106_main(void);

/* Function definitions */
int64_t _1106_main(void){
    int64_t _1106_t1;
    int64_t _1106_t2;
    int64_t _1106_t3;
    struct0 _1107_x;
    int64_t _1106_t4;
    int64_t _1106_t5;
    int64_t* _1107_a;
    int64_t _1106_t7;
    int64_t _1106_t8;
    int64_t* _1107_b;
    int64_t _1106_t10;
    int64_t _1106_t11;
    int64_t* _1107_c;
    int64_t _1106_t14;
    int64_t _1106_t15;
    int64_t _1106_t16;
    struct0 _1106_t13;
    int64_t _1106_t17;
    int64_t _1106_$retval;
    _1106_t1 = 0;
    _1106_t2 = 0;
    _1106_t3 = 0;
    _1107_x = (struct0) {_1106_t1, _1106_t2, _1106_t3};
    _1106_t4 = 0;
    _1106_t5 = 3;
    $bounds_check(_1106_t4, _1106_t5, "tests/integration/pattern/assign-deref-product.orng:4:14:\n    let a = &mut x[0]\n            ^");
    _1107_a = ((int64_t*)&_1107_x + _1106_t4);
    _1106_t7 = 1;
    _1106_t8 = 3;
    $bounds_check(_1106_t7, _1106_t8, "tests/integration/pattern/assign-deref-product.orng:5:14:\n    let b = &mut x[1]\n            ^");
    _1107_b = ((int64_t*)&_1107_x + _1106_t7);
    _1106_t10 = 2;
    _1106_t11 = 3;
    $bounds_check(_1106_t10, _1106_t11, "tests/integration/pattern/assign-deref-product.orng:6:14:\n    let c = &mut x[2]\n            ^");
    _1107_c = ((int64_t*)&_1107_x + _1106_t10);
    _1106_t14 = 100;
    _1106_t15 = 30;
    _1106_t16 = 30;
    _1106_t13 = (struct0) {_1106_t14, _1106_t15, _1106_t16};
    *_1107_a = _1106_t13._0;
    *_1107_b = _1106_t13._1;
    *_1107_c = _1106_t13._2;
    _1106_t17 = $add_int64_t(*_1107_a, *_1107_b, "tests/integration/pattern/assign-deref-product.orng:8:9:\n    a^ + b^ + c^\n       ^");
    _1106_$retval = $add_int64_t(_1106_t17, *_1107_c, "tests/integration/pattern/assign-deref-product.orng:8:14:\n    a^ + b^ + c^\n            ^");
    return _1106_$retval;
}

int main(void) {
  printf("%ld",_1106_main());
  return 0;
}
