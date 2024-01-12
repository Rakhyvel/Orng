/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward typedefs */
struct struct0;

/* Typedefs */
struct struct0 {
    int64_t _0;
    int64_t _1;
};

/* Function forward definitions */
int64_t _1168_main(void);

/* Function definitions */
int64_t _1168_main(void){
    int64_t _1168_t1;
    int64_t _1168_t2;
    struct struct0 _1168_t0;
    int64_t _1169_a;
    int64_t _1169_b;
    int64_t _1168_t4;
    int64_t _1168_t5;
    uint8_t _1168_t7;
    int64_t _1168_t3;
    int64_t _1168_$retval;
    _1168_t1 = 0;
    _1168_t2 = 0;
    _1168_t0 = (struct struct0) {_1168_t1, _1168_t2};
    _1169_a = _1168_t0._0;
    _1169_b = _1168_t0._1;
    _1168_t4 = $add_int64_t(_1169_a, _1169_b, "tests/integration/pattern/let-product-default.orng:4:11:\n    if a + b == 0 {\n         ^");
    _1168_t5 = 0;
    _1168_t7 = _1168_t4==_1168_t5;
    if (_1168_t7) {
        goto BB1368;
    } else {
        goto BB1372;
    }
BB1368:
    _1168_t3 = 160;
    goto BB1371;
BB1372:
    _1168_t3 = 61;
    goto BB1371;
BB1371:
    _1168_$retval = _1168_t3;
    return _1168_$retval;
}

int main(void) {
  printf("%ld",_1168_main());
  return 0;
}
