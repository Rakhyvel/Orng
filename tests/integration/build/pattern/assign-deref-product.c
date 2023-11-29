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
int64_t _829_main(void);

/* Function definitions */
int64_t _829_main(void) {
    int64_t _829_t1;
    int64_t _829_t2;
    int64_t _829_t3;
    struct0 _830_x;
    int64_t _829_t4;
    int64_t* _830_a;
    int64_t _829_t6;
    int64_t* _830_b;
    int64_t _829_t8;
    int64_t* _830_c;
    int64_t _829_t11;
    int64_t _829_t12;
    int64_t _829_t13;
    struct0 _829_t10;
    int64_t _829_t14;
    int64_t _829_$retval;
    _829_t1 = 0;
    _829_t2 = 0;
    _829_t3 = 0;
    _830_x = (struct0) {_829_t1, _829_t2, _829_t3};
    _829_t4 = 0;
    _830_a = ((int64_t*)&_830_x + _829_t4);
    _829_t6 = 1;
    _830_b = ((int64_t*)&_830_x + _829_t6);
    _829_t8 = 2;
    _830_c = ((int64_t*)&_830_x + _829_t8);
    _829_t11 = 100;
    _829_t12 = 30;
    _829_t13 = 30;
    _829_t10 = (struct0) {_829_t11, _829_t12, _829_t13};
    *_830_a = _829_t10._0;
    *_830_b = _829_t10._1;
    *_830_c = _829_t10._2;
    _829_t14 = $add_int64_t(*_830_a, *_830_b, "tests/integration/pattern/assign-deref-product.orng:8:9:\n    a^ + b^ + c^\n       ^");
    _829_$retval = $add_int64_t(_829_t14, *_830_c, "tests/integration/pattern/assign-deref-product.orng:8:14:\n    a^ + b^ + c^\n            ^");
    return _829_$retval;
}

int main(void) {
  printf("%ld",_829_main());
  return 0;
}
