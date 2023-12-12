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
int64_t _839_main(void);

/* Function definitions */
int64_t _839_main(void) {
    int64_t _839_t1;
    int64_t _839_t2;
    int64_t _839_t3;
    struct0 _840_x;
    int64_t _839_t4;
    int64_t* _840_a;
    int64_t _839_t6;
    int64_t* _840_b;
    int64_t _839_t8;
    int64_t* _840_c;
    int64_t _839_t11;
    int64_t _839_t12;
    int64_t _839_t13;
    struct0 _839_t10;
    int64_t _839_t14;
    int64_t _839_$retval;
    _839_t1 = 0;
    _839_t2 = 0;
    _839_t3 = 0;
    _840_x = (struct0) {_839_t1, _839_t2, _839_t3};
    _839_t4 = 0;
    _840_a = ((int64_t*)&_840_x + _839_t4);
    _839_t6 = 1;
    _840_b = ((int64_t*)&_840_x + _839_t6);
    _839_t8 = 2;
    _840_c = ((int64_t*)&_840_x + _839_t8);
    _839_t11 = 100;
    _839_t12 = 30;
    _839_t13 = 30;
    _839_t10 = (struct0) {_839_t11, _839_t12, _839_t13};
    *_840_a = _839_t10._0;
    *_840_b = _839_t10._1;
    *_840_c = _839_t10._2;
    _839_t14 = $add_int64_t(*_840_a, *_840_b, "tests/integration/pattern/assign-deref-product.orng:8:9:\n    a^ + b^ + c^\n       ^");
    _839_$retval = $add_int64_t(_839_t14, *_840_c, "tests/integration/pattern/assign-deref-product.orng:8:14:\n    a^ + b^ + c^\n            ^");
    return _839_$retval;
}

int main(void) {
  printf("%ld",_839_main());
  return 0;
}
