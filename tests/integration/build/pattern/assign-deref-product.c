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
int64_t _1028_main(void);

/* Function definitions */
int64_t _1028_main(void) {
    int64_t _1028_t1;
    int64_t _1028_t2;
    int64_t _1028_t3;
    struct0 _1029_x;
    int64_t _1028_t4;
    int64_t* _1029_a;
    int64_t _1028_t6;
    int64_t* _1029_b;
    int64_t _1028_t8;
    int64_t* _1029_c;
    int64_t _1028_t11;
    int64_t _1028_t12;
    int64_t _1028_t13;
    struct0 _1028_t10;
    int64_t _1028_t14;
    int64_t _1028_$retval;
    _1028_t1 = 0;
    _1028_t2 = 0;
    _1028_t3 = 0;
    _1029_x = (struct0) {_1028_t1, _1028_t2, _1028_t3};
    _1028_t4 = 0;
    _1029_a = ((int64_t*)&_1029_x + _1028_t4);
    _1028_t6 = 1;
    _1029_b = ((int64_t*)&_1029_x + _1028_t6);
    _1028_t8 = 2;
    _1029_c = ((int64_t*)&_1029_x + _1028_t8);
    _1028_t11 = 100;
    _1028_t12 = 30;
    _1028_t13 = 30;
    _1028_t10 = (struct0) {_1028_t11, _1028_t12, _1028_t13};
    *_1029_a = _1028_t10._0;
    *_1029_b = _1028_t10._1;
    *_1029_c = _1028_t10._2;
    _1028_t14 = $add_int64_t(*_1029_a, *_1029_b, "tests/integration/pattern/assign-deref-product.orng:8:9:\n    a^ + b^ + c^\n       ^");
    _1028_$retval = $add_int64_t(_1028_t14, *_1029_c, "tests/integration/pattern/assign-deref-product.orng:8:14:\n    a^ + b^ + c^\n            ^");
    return _1028_$retval;
}

int main(void) {
  printf("%ld",_1028_main());
  return 0;
}
