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
int64_t _1255_main(void);


/* Function definitions */
int64_t _1255_main(void){
    int64_t _1255_t1;
    int64_t _1255_t2;
    struct struct0 _1255_t0;
    int64_t _1256_a;
    int64_t _1256_b;
    int64_t _1255_t5;
    int64_t _1255_t6;
    uint8_t _1255_t8;
    int64_t _1255_t4;
    int64_t _1255_$retval;
    _1255_t1 = 0;
    _1255_t2 = 0;
    _1255_t0 = (struct struct0) {_1255_t1, _1255_t2};
    _1256_a = _1255_t0._0;
    _1256_b = _1255_t0._1;
    _1255_t5 = $add_int64_t(_1256_a, _1256_b, "tests/integration/pattern/let-product-default.orng:4:11:\n    if a + b == 0 {\n         ^");
    _1255_t6 = 0;
    _1255_t8 = _1255_t5==_1255_t6;
    if (_1255_t8) {
        goto BB1429;
    } else {
        goto BB1433;
    }
BB1429:
    _1255_t4 = 160;
    goto BB1432;
BB1433:
    _1255_t4 = 61;
    goto BB1432;
BB1432:
    _1255_$retval = _1255_t4;
    return _1255_$retval;
}


int main(void) {
  printf("%ld",_1255_main());
  return 0;
}
