/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef struct {
        int64_t _0;
        int64_t _1;
} struct0;

/* Function forward definitions */
int64_t _1150_main(void);

/* Function definitions */
int64_t _1150_main(void){
    int64_t _1150_t1;
    int64_t _1150_t2;
    struct0 _1150_t0;
    int64_t _1151_a;
    int64_t _1151_b;
    int64_t _1150_t4;
    int64_t _1150_t5;
    uint8_t _1150_t7;
    int64_t _1150_t3;
    int64_t _1150_$retval;
    _1150_t1 = 0;
    _1150_t2 = 0;
    _1150_t0 = (struct0) {_1150_t1, _1150_t2};
    _1151_a = _1150_t0._0;
    _1151_b = _1150_t0._1;
    _1150_t4 = $add_int64_t(_1151_a, _1151_b, "tests/integration/pattern/let-product-default.orng:4:11:\n    if a + b == 0 {\n         ^");
    _1150_t5 = 0;
    _1150_t7 = _1150_t4==_1150_t5;
    if (_1150_t7) {
        goto BB1360;
    } else {
        goto BB1364;
    }
BB1360:
    _1150_t3 = 160;
    goto BB1363;
BB1364:
    _1150_t3 = 61;
    goto BB1363;
BB1363:
    _1150_$retval = _1150_t3;
    return _1150_$retval;
}

int main(void) {
  printf("%ld",_1150_main());
  return 0;
}
