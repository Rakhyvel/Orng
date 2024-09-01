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
int64_t _1222_main(void);


/* Function definitions */
int64_t _1222_main(void){
    int64_t _1222_t1;
    int64_t _1222_t2;
    struct struct0 _1222_t0;
    int64_t _1223_a;
    int64_t _1223_b;
    int64_t _1222_t5;
    int64_t _1222_t6;
    uint8_t _1222_t8;
    int64_t _1222_t4;
    int64_t _1222_$retval;
    _1222_t1 = 0;
    _1222_t2 = 0;
    _1222_t0 = (struct struct0) {_1222_t1, _1222_t2};
    _1223_a = _1222_t0._0;
    _1223_b = _1222_t0._1;
    _1222_t5 = $add_int64_t(_1223_a, _1223_b, "tests/integration/pattern/let-product-default.orng:4:11:\n    if a + b == 0 {\n         ^");
    _1222_t6 = 0;
    _1222_t8 = _1222_t5==_1222_t6;
    if (_1222_t8) {
        goto BB1393;
    } else {
        goto BB1397;
    }
BB1393:
    _1222_t4 = 160;
    goto BB1396;
BB1397:
    _1222_t4 = 61;
    goto BB1396;
BB1396:
    _1222_$retval = _1222_t4;
    return _1222_$retval;
}


int main(void) {
  printf("%ld",_1222_main());
  return 0;
}
