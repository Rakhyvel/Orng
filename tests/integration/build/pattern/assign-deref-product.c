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
int64_t _1192_main(void);

/* Function definitions */
int64_t _1192_main(void){
    int64_t _1192_t1;
    int64_t _1192_t2;
    int64_t _1192_t3;
    struct0 _1193_x;
    int64_t _1192_t4;
    int64_t* _1193_a;
    int64_t _1192_t6;
    int64_t* _1193_b;
    int64_t _1192_t8;
    int64_t* _1193_c;
    int64_t _1192_t11;
    int64_t _1192_t12;
    int64_t _1192_t13;
    struct0 _1192_t10;
    int64_t _1192_t14;
    int64_t _1192_$retval;
    _1192_t1 = 0;
    _1192_t2 = 0;
    _1192_t3 = 0;
    _1193_x = (struct0) {_1192_t1, _1192_t2, _1192_t3};
    _1192_t4 = 0;
    _1193_a = ((int64_t*)&_1193_x + _1192_t4);
    _1192_t6 = 1;
    _1193_b = ((int64_t*)&_1193_x + _1192_t6);
    _1192_t8 = 2;
    _1193_c = ((int64_t*)&_1193_x + _1192_t8);
    _1192_t11 = 100;
    _1192_t12 = 30;
    _1192_t13 = 30;
    _1192_t10 = (struct0) {_1192_t11, _1192_t12, _1192_t13};
    *_1193_a = _1192_t10._0;
    *_1193_b = _1192_t10._1;
    *_1193_c = _1192_t10._2;
    _1192_t14 = $add_int64_t(*_1193_a, *_1193_b, "tests/integration/pattern/assign-deref-product.orng:8:9:\n    a^ + b^ + c^\n       ^");
    _1192_$retval = $add_int64_t(_1192_t14, *_1193_c, "tests/integration/pattern/assign-deref-product.orng:8:14:\n    a^ + b^ + c^\n            ^");
    return _1192_$retval;
}

int main(void) {
  printf("%ld",_1192_main());
  return 0;
}
