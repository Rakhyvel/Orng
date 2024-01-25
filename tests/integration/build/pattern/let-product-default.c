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
int64_t _1200_main(void);


/* Function definitions */
int64_t _1200_main(void){
    int64_t _1200_t1;
    int64_t _1200_t2;
    struct struct0 _1200_t0;
    int64_t _1201_a;
    int64_t _1201_b;
    int64_t _1200_t4;
    int64_t _1200_t5;
    uint8_t _1200_t7;
    int64_t _1200_t3;
    int64_t _1200_$retval;
    _1200_t1 = 0;
    _1200_t2 = 0;
    _1200_t0 = (struct struct0) {_1200_t1, _1200_t2};
    _1201_a = _1200_t0._0;
    _1201_b = _1200_t0._1;
    _1200_t4 = $add_int64_t(_1201_a, _1201_b, "tests/integration/pattern/let-product-default.orng:4:11:\n    if a + b == 0 {\n         ^");
    _1200_t5 = 0;
    _1200_t7 = _1200_t4==_1200_t5;
    if (_1200_t7) {
        goto BB1394;
    } else {
        goto BB1398;
    }
BB1394:
    _1200_t3 = 160;
    goto BB1397;
BB1398:
    _1200_t3 = 61;
    goto BB1397;
BB1397:
    _1200_$retval = _1200_t3;
    return _1200_$retval;
}


int main(void) {
  printf("%ld",_1200_main());
  return 0;
}
