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
int64_t _1275_main(void);


/* Function definitions */
int64_t _1275_main(void){
    int64_t _1275_t1;
    int64_t _1275_t2;
    struct struct0 _1275_t0;
    int64_t _1276_a;
    int64_t _1276_b;
    int64_t _1275_t5;
    int64_t _1275_t6;
    uint8_t _1275_t8;
    int64_t _1275_t4;
    int64_t _1275_$retval;
    _1275_t1 = 0;
    _1275_t2 = 0;
    _1275_t0 = (struct struct0) {_1275_t1, _1275_t2};
    _1276_a = _1275_t0._0;
    _1276_b = _1275_t0._1;
    _1275_t5 = $add_int64_t(_1276_a, _1276_b, "tests/integration/pattern/let-product-default.orng:4:11:\n    if a + b == 0 {\n         ^");
    _1275_t6 = 0;
    _1275_t8 = _1275_t5==_1275_t6;
    if (_1275_t8) {
        goto BB1448;
    } else {
        goto BB1452;
    }
BB1448:
    _1275_t4 = 160;
    goto BB1451;
BB1452:
    _1275_t4 = 61;
    goto BB1451;
BB1451:
    _1275_$retval = _1275_t4;
    return _1275_$retval;
}


int main(void) {
  printf("%ld",_1275_main());
  return 0;
}
