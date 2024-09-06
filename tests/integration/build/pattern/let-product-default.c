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
int64_t _1236_main(void);


/* Function definitions */
int64_t _1236_main(void){
    int64_t _1236_t1;
    int64_t _1236_t2;
    struct struct0 _1236_t0;
    int64_t _1237_a;
    int64_t _1237_b;
    int64_t _1236_t5;
    int64_t _1236_t6;
    uint8_t _1236_t8;
    int64_t _1236_t4;
    int64_t _1236_$retval;
    _1236_t1 = 0;
    _1236_t2 = 0;
    _1236_t0 = (struct struct0) {_1236_t1, _1236_t2};
    _1237_a = _1236_t0._0;
    _1237_b = _1236_t0._1;
    _1236_t5 = $add_int64_t(_1237_a, _1237_b, "tests/integration/pattern/let-product-default.orng:4:11:\n    if a + b == 0 {\n         ^");
    _1236_t6 = 0;
    _1236_t8 = _1236_t5==_1236_t6;
    if (_1236_t8) {
        goto BB1406;
    } else {
        goto BB1410;
    }
BB1406:
    _1236_t4 = 160;
    goto BB1409;
BB1410:
    _1236_t4 = 61;
    goto BB1409;
BB1409:
    _1236_$retval = _1236_t4;
    return _1236_$retval;
}


int main(void) {
  printf("%ld",_1236_main());
  return 0;
}
