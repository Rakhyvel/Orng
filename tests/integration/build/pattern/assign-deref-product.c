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
int64_t _812_main(void);

/* Function definitions */
int64_t _812_main(void) {
    int64_t _812_t1;
    int64_t _812_t2;
    int64_t _812_t3;
    struct0 _813_x;
    int64_t _812_t4;
    int64_t* _813_a;
    int64_t _812_t6;
    int64_t* _813_b;
    int64_t _812_t8;
    int64_t* _813_c;
    int64_t _812_t11;
    int64_t _812_t12;
    int64_t _812_t13;
    struct0 _812_t10;
    int64_t _812_t14;
    int64_t _812_$retval;
    _812_t1 = 0;
    _812_t2 = 0;
    _812_t3 = 0;
    _813_x = (struct0) {_812_t1, _812_t2, _812_t3};
    _812_t4 = 0;
    _813_a = ((int64_t*)&_813_x + _812_t4);
    _812_t6 = 1;
    _813_b = ((int64_t*)&_813_x + _812_t6);
    _812_t8 = 2;
    _813_c = ((int64_t*)&_813_x + _812_t8);
    _812_t11 = 100;
    _812_t12 = 30;
    _812_t13 = 30;
    _812_t10 = (struct0) {_812_t11, _812_t12, _812_t13};
    *_813_a = _812_t10._0;
    *_813_b = _812_t10._1;
    *_813_c = _812_t10._2;
    _812_t14 = $add_int64_t(*_813_a, *_813_b, "tests/integration/pattern/assign-deref-product.orng:8:9:\n    a^ + b^ + c^\n       ^");
    _812_$retval = $add_int64_t(_812_t14, *_813_c, "tests/integration/pattern/assign-deref-product.orng:8:14:\n    a^ + b^ + c^\n            ^");
    return _812_$retval;
}

int main(void) {
  printf("%ld",_812_main());
  return 0;
}
