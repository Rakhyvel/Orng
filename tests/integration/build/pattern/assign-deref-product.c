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
int64_t _1107_main(void);

/* Function definitions */
int64_t _1107_main(void){
    int64_t _1107_t1;
    int64_t _1107_t2;
    int64_t _1107_t3;
    struct0 _1108_x;
    int64_t _1107_t4;
    int64_t* _1108_a;
    int64_t _1107_t6;
    int64_t* _1108_b;
    int64_t _1107_t8;
    int64_t* _1108_c;
    int64_t _1107_t11;
    int64_t _1107_t12;
    int64_t _1107_t13;
    struct0 _1107_t10;
    int64_t _1107_t14;
    int64_t _1107_$retval;
    _1107_t1 = 0;
    _1107_t2 = 0;
    _1107_t3 = 0;
    _1108_x = (struct0) {_1107_t1, _1107_t2, _1107_t3};
    _1107_t4 = 0;
    _1108_a = ((int64_t*)&_1108_x + _1107_t4);
    _1107_t6 = 1;
    _1108_b = ((int64_t*)&_1108_x + _1107_t6);
    _1107_t8 = 2;
    _1108_c = ((int64_t*)&_1108_x + _1107_t8);
    _1107_t11 = 100;
    _1107_t12 = 30;
    _1107_t13 = 30;
    _1107_t10 = (struct0) {_1107_t11, _1107_t12, _1107_t13};
    *_1108_a = _1107_t10._0;
    *_1108_b = _1107_t10._1;
    *_1108_c = _1107_t10._2;
    _1107_t14 = $add_int64_t(*_1108_a, *_1108_b, "tests/integration/pattern/assign-deref-product.orng:8:9:\n    a^ + b^ + c^\n       ^");
    _1107_$retval = $add_int64_t(_1107_t14, *_1108_c, "tests/integration/pattern/assign-deref-product.orng:8:14:\n    a^ + b^ + c^\n            ^");
    return _1107_$retval;
}

int main(void) {
  printf("%ld",_1107_main());
  return 0;
}
