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
int64_t _1241_main(void);


/* Function definitions */
int64_t _1241_main(void){
    int64_t _1241_t1;
    int64_t _1241_t2;
    struct struct0 _1241_t0;
    int64_t _1242_a;
    int64_t _1242_b;
    int64_t _1241_t5;
    int64_t _1241_t6;
    uint8_t _1241_t8;
    int64_t _1241_t4;
    int64_t _1241_$retval;
    _1241_t1 = 0;
    _1241_t2 = 0;
    _1241_t0 = (struct struct0) {_1241_t1, _1241_t2};
    _1242_a = _1241_t0._0;
    _1242_b = _1241_t0._1;
    _1241_t5 = $add_int64_t(_1242_a, _1242_b, "tests/integration/pattern/let-product-default.orng:4:11:\n    if a + b == 0 {\n         ^");
    _1241_t6 = 0;
    _1241_t8 = _1241_t5==_1241_t6;
    if (_1241_t8) {
        goto BB1410;
    } else {
        goto BB1414;
    }
BB1410:
    _1241_t4 = 160;
    goto BB1413;
BB1414:
    _1241_t4 = 61;
    goto BB1413;
BB1413:
    _1241_$retval = _1241_t4;
    return _1241_$retval;
}


int main(void) {
  printf("%ld",_1241_main());
  return 0;
}
