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
int64_t _1344_main(void);

/* Function definitions */
int64_t _1344_main(void){
    int64_t _1344_t1;
    int64_t _1344_t2;
    struct0 _1344_t0;
    int64_t _1345_a;
    int64_t _1345_b;
    int64_t _1344_t4;
    int64_t _1344_t5;
    uint8_t _1344_t7;
    int64_t _1344_t3;
    int64_t _1344_$retval;
    _1344_t1 = 0;
    _1344_t2 = 0;
    _1344_t0 = (struct0) {_1344_t1, _1344_t2};
    _1345_a = _1344_t0._0;
    _1345_b = _1344_t0._1;
    _1344_t4 = $add_int64_t(_1345_a, _1345_b, "tests/integration/pattern/let-product-default.orng:4:11:\n    if a + b == 0 {\n         ^");
    _1344_t5 = 0;
    _1344_t7 = _1344_t4 == _1344_t5;
    if (_1344_t7) {
        goto BB3;
    } else {
        goto BB7;
    }
BB3:
    _1344_t3 = 160;
    goto BB6;
BB7:
    _1344_t3 = 61;
    goto BB6;
BB6:
    _1344_$retval = _1344_t3;
    return _1344_$retval;
}

int main(void) {
  printf("%ld",_1344_main());
  return 0;
}
