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
int64_t _1178_main(void);


/* Function definitions */
int64_t _1178_main(void){
    int64_t _1178_t1;
    int64_t _1178_t2;
    struct struct0 _1178_t0;
    int64_t _1179_a;
    int64_t _1179_b;
    int64_t _1178_t5;
    int64_t _1178_t6;
    uint8_t _1178_t8;
    int64_t _1178_t4;
    int64_t _1178_$retval;
    _1178_t1 = 0;
    _1178_t2 = 0;
    _1178_t0 = (struct struct0) {_1178_t1, _1178_t2};
    _1179_a = _1178_t0._0;
    _1179_b = _1178_t0._1;
    _1178_t5 = $add_int64_t(_1179_a, _1179_b, "tests/integration/pattern/let-product-default.orng:4:11:\n    if a + b == 0 {\n         ^");
    _1178_t6 = 0;
    _1178_t8 = _1178_t5==_1178_t6;
    if (_1178_t8) {
        goto BB1341;
    } else {
        goto BB1345;
    }
BB1341:
    _1178_t4 = 160;
    goto BB1344;
BB1345:
    _1178_t4 = 61;
    goto BB1344;
BB1344:
    _1178_$retval = _1178_t4;
    return _1178_$retval;
}


int main(void) {
  printf("%ld",_1178_main());
  return 0;
}
