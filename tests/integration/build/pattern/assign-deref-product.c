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
int64_t _753_main(void);

/* Function definitions */
int64_t _753_main(void) {
    int64_t _753_t1;
    int64_t _753_t2;
    int64_t _753_t3;
    struct0 _754_x;
    int64_t _753_t4;
    int64_t* _754_a;
    int64_t _753_t6;
    int64_t* _754_b;
    int64_t _753_t8;
    int64_t* _754_c;
    int64_t _753_t11;
    int64_t _753_t12;
    int64_t _753_t13;
    struct0 _753_t10;
    int64_t _753_t14;
    int64_t _753_$retval;
    _753_t1 = 0;
    _753_t2 = 0;
    _753_t3 = 0;
    _754_x = (struct0) {_753_t1, _753_t2, _753_t3};
    _753_t4 = 0;
    _754_a = ((int64_t*)&_754_x + _753_t4);
    _753_t6 = 1;
    _754_b = ((int64_t*)&_754_x + _753_t6);
    _753_t8 = 2;
    _754_c = ((int64_t*)&_754_x + _753_t8);
    _753_t11 = 100;
    _753_t12 = 30;
    _753_t13 = 30;
    _753_t10 = (struct0) {_753_t11, _753_t12, _753_t13};
    *_754_a = _753_t10._0;
    *_754_b = _753_t10._1;
    *_754_c = _753_t10._2;
    _753_t14 = $add_int64_t(*_754_a, *_754_b, "tests/integration/pattern/assign-deref-product.orng:8:9:\n    a^ + b^ + c^\n       ^");
    _753_$retval = $add_int64_t(_753_t14, *_754_c, "tests/integration/pattern/assign-deref-product.orng:8:14:\n    a^ + b^ + c^\n            ^");
    return _753_$retval;
}

int main(void) {
  printf("%ld",_753_main());
  return 0;
}
