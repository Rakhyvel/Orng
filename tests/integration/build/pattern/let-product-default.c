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
int64_t _1085_main(void);

/* Function definitions */
int64_t _1085_main(void) {
    int64_t _1085_t1;
    int64_t _1085_t2;
    struct0 _1085_t0;
    int64_t _1086_a;
    int64_t _1086_b;
    int64_t _1085_t4;
    int64_t _1085_t5;
    uint8_t _1085_t7;
    int64_t _1085_t3;
    int64_t _1085_$retval;
    _1085_t1 = 0;
    _1085_t2 = 0;
    _1085_t0 = (struct0) {_1085_t1, _1085_t2};
    _1086_a = _1085_t0._0;
    _1086_b = _1085_t0._1;
    _1085_t4 = $add_int64_t(_1086_a, _1086_b, "tests/integration/pattern/let-product-default.orng:4:11:\n    if a + b == 0 {\n         ^");
    _1085_t5 = 0;
    _1085_t7 = _1085_t4 == _1085_t5;
    if (_1085_t7) {
        goto BB3;
    } else {
        goto BB7;
    }
BB3:
    _1085_t3 = 160;
    goto BB6;
BB7:
    _1085_t3 = 61;
    goto BB6;
BB6:
    _1085_$retval = _1085_t3;
    return _1085_$retval;
}

int main(void) {
  printf("%ld",_1085_main());
  return 0;
}
