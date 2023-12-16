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
int64_t _1036_main(void);

/* Function definitions */
int64_t _1036_main(void){
    int64_t _1036_t1;
    int64_t _1036_t2;
    int64_t _1036_t3;
    struct0 _1037_x;
    int64_t _1036_t4;
    int64_t* _1037_a;
    int64_t _1036_t6;
    int64_t* _1037_b;
    int64_t _1036_t8;
    int64_t* _1037_c;
    int64_t _1036_t11;
    int64_t _1036_t12;
    int64_t _1036_t13;
    struct0 _1036_t10;
    int64_t _1036_t14;
    int64_t _1036_$retval;
    _1036_t1 = 0;
    _1036_t2 = 0;
    _1036_t3 = 0;
    _1037_x = (struct0) {_1036_t1, _1036_t2, _1036_t3};
    _1036_t4 = 0;
    _1037_a = ((int64_t*)&_1037_x + _1036_t4);
    _1036_t6 = 1;
    _1037_b = ((int64_t*)&_1037_x + _1036_t6);
    _1036_t8 = 2;
    _1037_c = ((int64_t*)&_1037_x + _1036_t8);
    _1036_t11 = 100;
    _1036_t12 = 30;
    _1036_t13 = 30;
    _1036_t10 = (struct0) {_1036_t11, _1036_t12, _1036_t13};
    *_1037_a = _1036_t10._0;
    *_1037_b = _1036_t10._1;
    *_1037_c = _1036_t10._2;
    _1036_t14 = $add_int64_t(*_1037_a, *_1037_b, "tests/integration/pattern/assign-deref-product.orng:8:9:\n    a^ + b^ + c^\n       ^");
    _1036_$retval = $add_int64_t(_1036_t14, *_1037_c, "tests/integration/pattern/assign-deref-product.orng:8:14:\n    a^ + b^ + c^\n            ^");
    return _1036_$retval;
}

int main(void) {
  printf("%ld",_1036_main());
  return 0;
}
