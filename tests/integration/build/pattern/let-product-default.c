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
} struct0;

/* Function forward definitions */
int64_t _43_main(void);

/* Function definitions */
int64_t _43_main(void) {
    int64_t _43_t1;
    int64_t _43_t2;
    struct0 _43_t0;
    int64_t _44_a;
    int64_t _44_b;
    int64_t _43_t4;
    int64_t _43_t5;
    uint8_t _43_t7;
    uint8_t _43_t6;
    int64_t _43_t3;
    int64_t _43_$retval;
    _43_t1 = 0;
    _43_t2 = 0;
    _43_t0 = (struct0) {_43_t1, _43_t2};
    _44_a = _43_t0._0;
    _44_b = _43_t0._1;
    _43_t4 = $add_int64_t(_44_a, _44_b, "tests/integration/pattern/let-product-default.orng:4:11:\n    if a + b == 0 {\n         ^");
    _43_t5 = 0;
    _43_t7 = _43_t4 == _43_t5;
    if (_43_t7) {
        goto BB1;
    } else {
        goto BB9;
    }
BB1:
    _43_t6 = 1;
    goto BB2;
BB9:
    _43_t6 = 0;
    goto BB2;
BB2:
    if (_43_t6) {
        goto BB3;
    } else {
        goto BB7;
    }
BB3:
    _43_t3 = 160;
    goto BB6;
BB7:
    _43_t3 = 61;
    goto BB6;
BB6:
    _43_$retval = _43_t3;
    return _43_$retval;
}

int main(void) {
  printf("%ld",_43_main());
  return 0;
}
