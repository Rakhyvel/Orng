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
int64_t _848_main(void);

/* Function definitions */
int64_t _848_main(void) {
    int64_t _848_t1;
    int64_t _848_t2;
    struct0 _848_t0;
    int64_t _849_a;
    int64_t _849_b;
    int64_t _848_t4;
    int64_t _848_t5;
    uint8_t _848_t7;
    int64_t _848_t3;
    int64_t _848_$retval;
    _848_t1 = 0;
    _848_t2 = 0;
    _848_t0 = (struct0) {_848_t1, _848_t2};
    _849_a = _848_t0._0;
    _849_b = _848_t0._1;
    _848_t4 = $add_int64_t(_849_a, _849_b, "tests/integration/pattern/let-product-default.orng:4:11:\n    if a + b == 0 {\n         ^");
    _848_t5 = 0;
    _848_t7 = _848_t4 == _848_t5;
    if (_848_t7) {
        goto BB3;
    } else {
        goto BB7;
    }
BB3:
    _848_t3 = 160;
    goto BB6;
BB7:
    _848_t3 = 61;
    goto BB6;
BB6:
    _848_$retval = _848_t3;
    return _848_$retval;
}

int main(void) {
  printf("%ld",_848_main());
  return 0;
}
