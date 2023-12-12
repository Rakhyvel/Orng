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
int64_t _856_main(void);

/* Function definitions */
int64_t _856_main(void) {
    int64_t _856_t1;
    int64_t _856_t2;
    struct0 _856_t0;
    int64_t _857_a;
    int64_t _857_b;
    int64_t _856_t4;
    int64_t _856_t5;
    uint8_t _856_t7;
    int64_t _856_t3;
    int64_t _856_$retval;
    _856_t1 = 0;
    _856_t2 = 0;
    _856_t0 = (struct0) {_856_t1, _856_t2};
    _857_a = _856_t0._0;
    _857_b = _856_t0._1;
    _856_t4 = $add_int64_t(_857_a, _857_b, "tests/integration/pattern/let-product-default.orng:4:11:\n    if a + b == 0 {\n         ^");
    _856_t5 = 0;
    _856_t7 = _856_t4 == _856_t5;
    if (_856_t7) {
        goto BB3;
    } else {
        goto BB7;
    }
BB3:
    _856_t3 = 160;
    goto BB6;
BB7:
    _856_t3 = 61;
    goto BB6;
BB6:
    _856_$retval = _856_t3;
    return _856_$retval;
}

int main(void) {
  printf("%ld",_856_main());
  return 0;
}
