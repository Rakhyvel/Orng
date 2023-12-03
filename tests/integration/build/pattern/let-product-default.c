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
int64_t _824_main(void);

/* Function definitions */
int64_t _824_main(void) {
    int64_t _824_t1;
    int64_t _824_t2;
    struct0 _824_t0;
    int64_t _825_a;
    int64_t _825_b;
    int64_t _824_t4;
    int64_t _824_t5;
    uint8_t _824_t7;
    int64_t _824_t3;
    int64_t _824_$retval;
    _824_t1 = 0;
    _824_t2 = 0;
    _824_t0 = (struct0) {_824_t1, _824_t2};
    _825_a = _824_t0._0;
    _825_b = _824_t0._1;
    _824_t4 = $add_int64_t(_825_a, _825_b, "tests/integration/pattern/let-product-default.orng:4:11:\n    if a + b == 0 {\n         ^");
    _824_t5 = 0;
    _824_t7 = _824_t4 == _824_t5;
    if (_824_t7) {
        goto BB3;
    } else {
        goto BB7;
    }
BB3:
    _824_t3 = 160;
    goto BB6;
BB7:
    _824_t3 = 61;
    goto BB6;
BB6:
    _824_$retval = _824_t3;
    return _824_$retval;
}

int main(void) {
  printf("%ld",_824_main());
  return 0;
}
