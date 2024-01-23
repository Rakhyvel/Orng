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
int64_t _1173_main(void);


/* Function definitions */
int64_t _1173_main(void){
    int64_t _1173_t1;
    int64_t _1173_t2;
    struct struct0 _1173_t0;
    int64_t _1174_a;
    int64_t _1174_b;
    int64_t _1173_t4;
    int64_t _1173_t5;
    uint8_t _1173_t7;
    int64_t _1173_t3;
    int64_t _1173_$retval;
    _1173_t1 = 0;
    _1173_t2 = 0;
    _1173_t0 = (struct struct0) {_1173_t1, _1173_t2};
    _1174_a = _1173_t0._0;
    _1174_b = _1173_t0._1;
    _1173_t4 = $add_int64_t(_1174_a, _1174_b, "tests/integration/pattern/let-product-default.orng:4:11:\n    if a + b == 0 {\n         ^");
    _1173_t5 = 0;
    _1173_t7 = _1173_t4==_1173_t5;
    if (_1173_t7) {
        goto BB1372;
    } else {
        goto BB1376;
    }
BB1372:
    _1173_t3 = 160;
    goto BB1375;
BB1376:
    _1173_t3 = 61;
    goto BB1375;
BB1375:
    _1173_$retval = _1173_t3;
    return _1173_$retval;
}


int main(void) {
  printf("%ld",_1173_main());
  return 0;
}
