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
int64_t _988_main(void);

/* Function definitions */
int64_t _988_main(void) {
    int64_t _988_t1;
    int64_t _988_t2;
    int64_t _988_t3;
    struct0 _989_x;
    int64_t _988_t4;
    int64_t* _989_a;
    int64_t _988_t6;
    int64_t* _989_b;
    int64_t _988_t8;
    int64_t* _989_c;
    int64_t _988_t11;
    int64_t _988_t12;
    int64_t _988_t13;
    struct0 _988_t10;
    int64_t _988_t14;
    int64_t _988_$retval;
    _988_t1 = 0;
    _988_t2 = 0;
    _988_t3 = 0;
    _989_x = (struct0) {_988_t1, _988_t2, _988_t3};
    _988_t4 = 0;
    _989_a = ((int64_t*)&_989_x + _988_t4);
    _988_t6 = 1;
    _989_b = ((int64_t*)&_989_x + _988_t6);
    _988_t8 = 2;
    _989_c = ((int64_t*)&_989_x + _988_t8);
    _988_t11 = 100;
    _988_t12 = 30;
    _988_t13 = 30;
    _988_t10 = (struct0) {_988_t11, _988_t12, _988_t13};
    *_989_a = _988_t10._0;
    *_989_b = _988_t10._1;
    *_989_c = _988_t10._2;
    _988_t14 = $add_int64_t(*_989_a, *_989_b, "tests/integration/pattern/assign-deref-product.orng:8:9:\n    a^ + b^ + c^\n       ^");
    _988_$retval = $add_int64_t(_988_t14, *_989_c, "tests/integration/pattern/assign-deref-product.orng:8:14:\n    a^ + b^ + c^\n            ^");
    return _988_$retval;
}

int main(void) {
  printf("%ld",_988_main());
  return 0;
}
