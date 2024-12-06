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
int64_t _1247_main(void);


/* Function definitions */
int64_t _1247_main(void){
    int64_t _1247_t1;
    int64_t _1247_t2;
    struct struct0 _1247_t0;
    int64_t _1248_a;
    int64_t _1248_b;
    int64_t _1247_t5;
    int64_t _1247_t6;
    uint8_t _1247_t8;
    int64_t _1247_t4;
    int64_t _1247_$retval;
    _1247_t1 = 0;
    _1247_t2 = 0;
    _1247_t0 = (struct struct0) {_1247_t1, _1247_t2};
    _1248_a = _1247_t0._0;
    _1248_b = _1247_t0._1;
    _1247_t5 = $add_int64_t(_1248_a, _1248_b, "tests/integration/pattern/let-product-default.orng:4:11:\n    if a + b == 0 {\n         ^");
    _1247_t6 = 0;
    _1247_t8 = _1247_t5==_1247_t6;
    if (_1247_t8) {
        goto BB1419;
    } else {
        goto BB1423;
    }
BB1419:
    _1247_t4 = 160;
    goto BB1422;
BB1423:
    _1247_t4 = 61;
    goto BB1422;
BB1422:
    _1247_$retval = _1247_t4;
    return _1247_$retval;
}


int main(void) {
  printf("%ld",_1247_main());
  return 0;
}
