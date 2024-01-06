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
int64_t _1158_main(void);

/* Function definitions */
int64_t _1158_main(void){
    int64_t _1158_t1;
    int64_t _1158_t2;
    struct struct0 _1158_t0;
    int64_t _1159_a;
    int64_t _1159_b;
    int64_t _1158_t4;
    int64_t _1158_t5;
    uint8_t _1158_t7;
    int64_t _1158_t3;
    int64_t _1158_$retval;
    _1158_t1 = 0;
    _1158_t2 = 0;
    _1158_t0 = (struct struct0) {_1158_t1, _1158_t2};
    _1159_a = _1158_t0._0;
    _1159_b = _1158_t0._1;
    _1158_t4 = $add_int64_t(_1159_a, _1159_b, "tests/integration/pattern/let-product-default.orng:4:11:\n    if a + b == 0 {\n         ^");
    _1158_t5 = 0;
    _1158_t7 = _1158_t4==_1158_t5;
    if (_1158_t7) {
        goto BB1356;
    } else {
        goto BB1360;
    }
BB1356:
    _1158_t3 = 160;
    goto BB1359;
BB1360:
    _1158_t3 = 61;
    goto BB1359;
BB1359:
    _1158_$retval = _1158_t3;
    return _1158_$retval;
}

int main(void) {
  printf("%ld",_1158_main());
  return 0;
}
