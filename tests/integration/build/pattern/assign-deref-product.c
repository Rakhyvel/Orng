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
int64_t _722_main(void);

/* Function definitions */
int64_t _722_main(void) {
    int64_t _722_t1;
    int64_t _722_t2;
    int64_t _722_t3;
    struct0 _723_x;
    int64_t _722_t4;
    int64_t* _723_a;
    int64_t _722_t6;
    int64_t* _723_b;
    int64_t _722_t8;
    int64_t* _723_c;
    int64_t _722_t11;
    int64_t _722_t12;
    int64_t _722_t13;
    struct0 _722_t10;
    int64_t _722_t14;
    int64_t _722_$retval;
    _722_t1 = 0;
    _722_t2 = 0;
    _722_t3 = 0;
    _723_x = (struct0) {_722_t1, _722_t2, _722_t3};
    _722_t4 = 0;
    _723_a = ((int64_t*)&_723_x + _722_t4);
    _722_t6 = 1;
    _723_b = ((int64_t*)&_723_x + _722_t6);
    _722_t8 = 2;
    _723_c = ((int64_t*)&_723_x + _722_t8);
    _722_t11 = 100;
    _722_t12 = 30;
    _722_t13 = 30;
    _722_t10 = (struct0) {_722_t11, _722_t12, _722_t13};
    *_723_a = _722_t10._0;
    *_723_b = _722_t10._1;
    *_723_c = _722_t10._2;
    _722_t14 = $add_int64_t(*_723_a, *_723_b, "tests/integration/pattern/assign-deref-product.orng:8:9:\n    a^ + b^ + c^\n       ^");
    _722_$retval = $add_int64_t(_722_t14, *_723_c, "tests/integration/pattern/assign-deref-product.orng:8:14:\n    a^ + b^ + c^\n            ^");
    return _722_$retval;
}

int main(void) {
  printf("%ld",_722_main());
  return 0;
}
