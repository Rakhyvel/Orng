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
int64_t _1260_main(void);


/* Function definitions */
int64_t _1260_main(void){
    int64_t _1260_t1;
    int64_t _1260_t2;
    struct struct0 _1260_t0;
    int64_t _1261_a;
    int64_t _1261_b;
    int64_t _1260_t5;
    int64_t _1260_t6;
    uint8_t _1260_t8;
    int64_t _1260_t4;
    int64_t _1260_$retval;
    _1260_t1 = 0;
    _1260_t2 = 0;
    _1260_t0 = (struct struct0) {_1260_t1, _1260_t2};
    _1261_a = _1260_t0._0;
    _1261_b = _1260_t0._1;
    _1260_t5 = $add_int64_t(_1261_a, _1261_b, "tests/integration/pattern/let-product-default.orng:4:11:\n    if a + b == 0 {\n         ^");
    _1260_t6 = 0;
    _1260_t8 = _1260_t5==_1260_t6;
    if (_1260_t8) {
        goto BB1432;
    } else {
        goto BB1436;
    }
BB1432:
    _1260_t4 = 160;
    goto BB1435;
BB1436:
    _1260_t4 = 61;
    goto BB1435;
BB1435:
    _1260_$retval = _1260_t4;
    return _1260_$retval;
}


int main(void) {
  printf("%ld",_1260_main());
  return 0;
}
