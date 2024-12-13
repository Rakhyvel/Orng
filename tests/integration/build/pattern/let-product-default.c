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
int64_t _1277_main(void);


/* Function definitions */
int64_t _1277_main(void){
    int64_t _1277_t1;
    int64_t _1277_t2;
    struct struct0 _1277_t0;
    int64_t _1278_a;
    int64_t _1278_b;
    int64_t _1277_t5;
    int64_t _1277_t6;
    uint8_t _1277_t8;
    int64_t _1277_t4;
    int64_t _1277_$retval;
    _1277_t1 = 0;
    _1277_t2 = 0;
    _1277_t0 = (struct struct0) {_1277_t1, _1277_t2};
    _1278_a = _1277_t0._0;
    _1278_b = _1277_t0._1;
    _1277_t5 = $add_int64_t(_1278_a, _1278_b, "tests/integration/pattern/let-product-default.orng:4:11:\n    if a + b == 0 {\n         ^");
    _1277_t6 = 0;
    _1277_t8 = _1277_t5==_1277_t6;
    if (_1277_t8) {
        goto BB1450;
    } else {
        goto BB1454;
    }
BB1450:
    _1277_t4 = 160;
    goto BB1453;
BB1454:
    _1277_t4 = 61;
    goto BB1453;
BB1453:
    _1277_$retval = _1277_t4;
    return _1277_$retval;
}


int main(void) {
  printf("%ld",_1277_main());
  return 0;
}
