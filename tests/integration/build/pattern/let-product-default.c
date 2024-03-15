/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward struct, union, and function declarations */
struct struct0;

/* Struct, union, and function definitions */
struct struct0 {
    int64_t _0;
    int64_t _1;
};

/* Function forward definitions */
int64_t _1169_main(void);


/* Function definitions */
int64_t _1169_main(void){
    int64_t _1169_t1;
    int64_t _1169_t2;
    struct struct0 _1169_t0;
    int64_t _1170_a;
    int64_t _1170_b;
    int64_t _1169_t5;
    int64_t _1169_t6;
    uint8_t _1169_t8;
    int64_t _1169_t4;
    int64_t _1169_$retval;
    _1169_t1 = 0;
    _1169_t2 = 0;
    _1169_t0 = (struct struct0) {_1169_t1, _1169_t2};
    _1170_a = _1169_t0._0;
    _1170_b = _1169_t0._1;
    _1169_t5 = $add_int64_t(_1170_a, _1170_b, "tests/integration/pattern/let-product-default.orng:4:11:\n    if a + b == 0 {\n         ^");
    _1169_t6 = 0;
    _1169_t8 = _1169_t5==_1169_t6;
    if (_1169_t8) {
        goto BB1335;
    } else {
        goto BB1339;
    }
BB1335:
    _1169_t4 = 160;
    goto BB1338;
BB1339:
    _1169_t4 = 61;
    goto BB1338;
BB1338:
    _1169_$retval = _1169_t4;
    return _1169_$retval;
}


int main(void) {
  printf("%ld",_1169_main());
  return 0;
}
