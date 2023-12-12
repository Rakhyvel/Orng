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
int64_t _875_main(void);

/* Function definitions */
int64_t _875_main(void) {
    int64_t _875_t1;
    int64_t _875_t2;
    struct0 _875_t0;
    int64_t _876_a;
    int64_t _876_b;
    int64_t _875_t4;
    int64_t _875_t5;
    uint8_t _875_t7;
    int64_t _875_t3;
    int64_t _875_$retval;
    _875_t1 = 0;
    _875_t2 = 0;
    _875_t0 = (struct0) {_875_t1, _875_t2};
    _876_a = _875_t0._0;
    _876_b = _875_t0._1;
    _875_t4 = $add_int64_t(_876_a, _876_b, "tests/integration/pattern/let-product-default.orng:4:11:\n    if a + b == 0 {\n         ^");
    _875_t5 = 0;
    _875_t7 = _875_t4 == _875_t5;
    if (_875_t7) {
        goto BB3;
    } else {
        goto BB7;
    }
BB3:
    _875_t3 = 160;
    goto BB6;
BB7:
    _875_t3 = 61;
    goto BB6;
BB6:
    _875_$retval = _875_t3;
    return _875_$retval;
}

int main(void) {
  printf("%ld",_875_main());
  return 0;
}
