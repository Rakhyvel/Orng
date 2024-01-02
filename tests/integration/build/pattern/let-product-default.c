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
int64_t _1153_main(void);

/* Function definitions */
int64_t _1153_main(void){
    int64_t _1153_t1;
    int64_t _1153_t2;
    struct struct0 _1153_t0;
    int64_t _1154_a;
    int64_t _1154_b;
    int64_t _1153_t4;
    int64_t _1153_t5;
    uint8_t _1153_t7;
    int64_t _1153_t3;
    int64_t _1153_$retval;
    _1153_t1 = 0;
    _1153_t2 = 0;
    _1153_t0 = (struct struct0) {_1153_t1, _1153_t2};
    _1154_a = _1153_t0._0;
    _1154_b = _1153_t0._1;
    _1153_t4 = $add_int64_t(_1154_a, _1154_b, "tests/integration/pattern/let-product-default.orng:4:11:\n    if a + b == 0 {\n         ^");
    _1153_t5 = 0;
    _1153_t7 = _1153_t4==_1153_t5;
    if (_1153_t7) {
        goto BB1352;
    } else {
        goto BB1356;
    }
BB1352:
    _1153_t3 = 160;
    goto BB1355;
BB1356:
    _1153_t3 = 61;
    goto BB1355;
BB1355:
    _1153_$retval = _1153_t3;
    return _1153_$retval;
}

int main(void) {
  printf("%ld",_1153_main());
  return 0;
}
