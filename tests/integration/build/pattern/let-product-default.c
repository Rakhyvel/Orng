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
int64_t _758_main(void);

/* Function definitions */
int64_t _758_main(void) {
    int64_t _758_t1;
    int64_t _758_t2;
    struct0 _758_t0;
    int64_t _759_a;
    int64_t _759_b;
    int64_t _758_t4;
    int64_t _758_t5;
    uint8_t _758_t7;
    uint8_t _758_t6;
    int64_t _758_t3;
    int64_t _758_$retval;
    _758_t1 = 0;
    _758_t2 = 0;
    _758_t0 = (struct0) {_758_t1, _758_t2};
    _759_a = _758_t0._0;
    _759_b = _758_t0._1;
    _758_t4 = $add_int64_t(_759_a, _759_b, "tests/integration/pattern/let-product-default.orng:4:11:\n    if a + b == 0 {\n         ^");
    _758_t5 = 0;
    _758_t7 = _758_t4 == _758_t5;
    if (_758_t7) {
        goto BB1;
    } else {
        goto BB9;
    }
BB1:
    _758_t6 = 1;
    goto BB2;
BB9:
    _758_t6 = 0;
    goto BB2;
BB2:
    if (_758_t6) {
        goto BB3;
    } else {
        goto BB7;
    }
BB3:
    _758_t3 = 160;
    goto BB6;
BB7:
    _758_t3 = 61;
    goto BB6;
BB6:
    _758_$retval = _758_t3;
    return _758_$retval;
}

int main(void) {
  printf("%ld",_758_main());
  return 0;
}
