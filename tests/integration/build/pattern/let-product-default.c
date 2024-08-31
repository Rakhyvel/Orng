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
int64_t _1183_main(void);


/* Function definitions */
int64_t _1183_main(void){
    int64_t _1183_t1;
    int64_t _1183_t2;
    struct struct0 _1183_t0;
    int64_t _1184_a;
    int64_t _1184_b;
    int64_t _1183_t5;
    int64_t _1183_t6;
    uint8_t _1183_t8;
    int64_t _1183_t4;
    int64_t _1183_$retval;
    _1183_t1 = 0;
    _1183_t2 = 0;
    _1183_t0 = (struct struct0) {_1183_t1, _1183_t2};
    _1184_a = _1183_t0._0;
    _1184_b = _1183_t0._1;
    _1183_t5 = $add_int64_t(_1184_a, _1184_b, "tests/integration/pattern/let-product-default.orng:4:11:\n    if a + b == 0 {\n         ^");
    _1183_t6 = 0;
    _1183_t8 = _1183_t5==_1183_t6;
    if (_1183_t8) {
        goto BB1345;
    } else {
        goto BB1349;
    }
BB1345:
    _1183_t4 = 160;
    goto BB1348;
BB1349:
    _1183_t4 = 61;
    goto BB1348;
BB1348:
    _1183_$retval = _1183_t4;
    return _1183_$retval;
}


int main(void) {
  printf("%ld",_1183_main());
  return 0;
}
