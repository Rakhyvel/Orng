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
int64_t _7_main(void);

/* Function definitions */
int64_t _7_main(void) {
    int64_t _7_t1;
    int64_t _7_t2;
    int64_t _7_t3;
    struct0 _8_x;
    int64_t _7_t4;
    int64_t* _8_a;
    int64_t _7_t6;
    int64_t* _8_b;
    int64_t _7_t8;
    int64_t* _8_c;
    int64_t _7_t11;
    int64_t _7_t12;
    int64_t _7_t13;
    struct0 _7_t10;
    int64_t _7_t14;
    int64_t _7_$retval;
    _7_t1 = 0;
    _7_t2 = 0;
    _7_t3 = 0;
    _8_x = (struct0) {_7_t1, _7_t2, _7_t3};
    _7_t4 = 0;
    _8_a = ((int64_t*)&_8_x + _7_t4);
    _7_t6 = 1;
    _8_b = ((int64_t*)&_8_x + _7_t6);
    _7_t8 = 2;
    _8_c = ((int64_t*)&_8_x + _7_t8);
    _7_t11 = 100;
    _7_t12 = 30;
    _7_t13 = 30;
    _7_t10 = (struct0) {_7_t11, _7_t12, _7_t13};
    *_8_a = _7_t10._0;
    *_8_b = _7_t10._1;
    *_8_c = _7_t10._2;
    _7_t14 = $add_int64_t(*_8_a, *_8_b, "tests/integration/pattern/assign-deref-product.orng:8:9:\n    a^ + b^ + c^\n       ^");
    _7_$retval = $add_int64_t(_7_t14, *_8_c, "tests/integration/pattern/assign-deref-product.orng:8:14:\n    a^ + b^ + c^\n            ^");
    return _7_$retval;
}

int main(void) {
  printf("%ld",_7_main());
  return 0;
}
