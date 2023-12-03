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
int64_t _788_main(void);

/* Function definitions */
int64_t _788_main(void) {
    int64_t _788_t1;
    int64_t _788_t2;
    int64_t _788_t3;
    struct0 _789_x;
    int64_t _788_t4;
    int64_t* _789_a;
    int64_t _788_t6;
    int64_t* _789_b;
    int64_t _788_t8;
    int64_t* _789_c;
    int64_t _788_t11;
    int64_t _788_t12;
    int64_t _788_t13;
    struct0 _788_t10;
    int64_t _788_t14;
    int64_t _788_$retval;
    _788_t1 = 0;
    _788_t2 = 0;
    _788_t3 = 0;
    _789_x = (struct0) {_788_t1, _788_t2, _788_t3};
    _788_t4 = 0;
    _789_a = ((int64_t*)&_789_x + _788_t4);
    _788_t6 = 1;
    _789_b = ((int64_t*)&_789_x + _788_t6);
    _788_t8 = 2;
    _789_c = ((int64_t*)&_789_x + _788_t8);
    _788_t11 = 100;
    _788_t12 = 30;
    _788_t13 = 30;
    _788_t10 = (struct0) {_788_t11, _788_t12, _788_t13};
    *_789_a = _788_t10._0;
    *_789_b = _788_t10._1;
    *_789_c = _788_t10._2;
    _788_t14 = $add_int64_t(*_789_a, *_789_b, "tests/integration/pattern/assign-deref-product.orng:8:9:\n    a^ + b^ + c^\n       ^");
    _788_$retval = $add_int64_t(_788_t14, *_789_c, "tests/integration/pattern/assign-deref-product.orng:8:14:\n    a^ + b^ + c^\n            ^");
    return _788_$retval;
}

int main(void) {
  printf("%ld",_788_main());
  return 0;
}
