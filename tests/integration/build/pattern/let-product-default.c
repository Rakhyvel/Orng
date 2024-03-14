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
int64_t _1203_main(void);


/* Function definitions */
int64_t _1203_main(void){
    int64_t _1203_t1;
    int64_t _1203_t2;
    struct struct0 _1203_t0;
    int64_t _1204_a;
    int64_t _1204_b;
    int64_t _1203_t5;
    int64_t _1203_t6;
    uint8_t _1203_t8;
    int64_t _1203_t4;
    int64_t _1203_$retval;
    _1203_t1 = 0;
    _1203_t2 = 0;
    _1203_t0 = (struct struct0) {_1203_t1, _1203_t2};
    _1204_a = _1203_t0._0;
    _1204_b = _1203_t0._1;
    _1203_t5 = $add_int64_t(_1204_a, _1204_b, "tests/integration/pattern/let-product-default.orng:4:11:\n    if a + b == 0 {\n         ^");
    _1203_t6 = 0;
    _1203_t8 = _1203_t5==_1203_t6;
    if (_1203_t8) {
        goto BB1388;
    } else {
        goto BB1392;
    }
BB1388:
    _1203_t4 = 160;
    goto BB1391;
BB1392:
    _1203_t4 = 61;
    goto BB1391;
BB1391:
    _1203_$retval = _1203_t4;
    return _1203_$retval;
}


int main(void) {
  printf("%ld",_1203_main());
  return 0;
}
