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
int64_t _820_main(void);

/* Function definitions */
int64_t _820_main(void) {
    int64_t _820_t1;
    int64_t _820_t2;
    int64_t _820_t3;
    struct0 _821_x;
    int64_t _820_t4;
    int64_t* _821_a;
    int64_t _820_t6;
    int64_t* _821_b;
    int64_t _820_t8;
    int64_t* _821_c;
    int64_t _820_t11;
    int64_t _820_t12;
    int64_t _820_t13;
    struct0 _820_t10;
    int64_t _820_t14;
    int64_t _820_$retval;
    _820_t1 = 0;
    _820_t2 = 0;
    _820_t3 = 0;
    _821_x = (struct0) {_820_t1, _820_t2, _820_t3};
    _820_t4 = 0;
    _821_a = ((int64_t*)&_821_x + _820_t4);
    _820_t6 = 1;
    _821_b = ((int64_t*)&_821_x + _820_t6);
    _820_t8 = 2;
    _821_c = ((int64_t*)&_821_x + _820_t8);
    _820_t11 = 100;
    _820_t12 = 30;
    _820_t13 = 30;
    _820_t10 = (struct0) {_820_t11, _820_t12, _820_t13};
    *_821_a = _820_t10._0;
    *_821_b = _820_t10._1;
    *_821_c = _820_t10._2;
    _820_t14 = $add_int64_t(*_821_a, *_821_b, "tests/integration/pattern/assign-deref-product.orng:8:9:\n    a^ + b^ + c^\n       ^");
    _820_$retval = $add_int64_t(_820_t14, *_821_c, "tests/integration/pattern/assign-deref-product.orng:8:14:\n    a^ + b^ + c^\n            ^");
    return _820_$retval;
}

int main(void) {
  printf("%ld",_820_main());
  return 0;
}
