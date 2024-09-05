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
int64_t _1233_main(void);


/* Function definitions */
int64_t _1233_main(void){
    int64_t _1233_t1;
    int64_t _1233_t2;
    struct struct0 _1233_t0;
    int64_t _1234_a;
    int64_t _1234_b;
    int64_t _1233_t5;
    int64_t _1233_t6;
    uint8_t _1233_t8;
    int64_t _1233_t4;
    int64_t _1233_$retval;
    _1233_t1 = 0;
    _1233_t2 = 0;
    _1233_t0 = (struct struct0) {_1233_t1, _1233_t2};
    _1234_a = _1233_t0._0;
    _1234_b = _1233_t0._1;
    _1233_t5 = $add_int64_t(_1234_a, _1234_b, "tests/integration/pattern/let-product-default.orng:4:11:\n    if a + b == 0 {\n         ^");
    _1233_t6 = 0;
    _1233_t8 = _1233_t5==_1233_t6;
    if (_1233_t8) {
        goto BB1404;
    } else {
        goto BB1408;
    }
BB1404:
    _1233_t4 = 160;
    goto BB1407;
BB1408:
    _1233_t4 = 61;
    goto BB1407;
BB1407:
    _1233_$retval = _1233_t4;
    return _1233_$retval;
}


int main(void) {
  printf("%ld",_1233_main());
  return 0;
}
