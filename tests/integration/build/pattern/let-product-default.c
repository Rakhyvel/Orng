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
int64_t _872_main(void);

/* Function definitions */
int64_t _872_main(void) {
    int64_t _872_t1;
    int64_t _872_t2;
    struct0 _872_t0;
    int64_t _873_a;
    int64_t _873_b;
    int64_t _872_t4;
    int64_t _872_t5;
    uint8_t _872_t7;
    int64_t _872_t3;
    int64_t _872_$retval;
    _872_t1 = 0;
    _872_t2 = 0;
    _872_t0 = (struct0) {_872_t1, _872_t2};
    _873_a = _872_t0._0;
    _873_b = _872_t0._1;
    _872_t4 = $add_int64_t(_873_a, _873_b, "tests/integration/pattern/let-product-default.orng:4:11:\n    if a + b == 0 {\n         ^");
    _872_t5 = 0;
    _872_t7 = _872_t4 == _872_t5;
    if (_872_t7) {
        goto BB3;
    } else {
        goto BB7;
    }
BB3:
    _872_t3 = 160;
    goto BB6;
BB7:
    _872_t3 = 61;
    goto BB6;
BB6:
    _872_$retval = _872_t3;
    return _872_$retval;
}

int main(void) {
  printf("%ld",_872_main());
  return 0;
}
