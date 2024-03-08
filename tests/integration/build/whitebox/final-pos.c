/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _1761_main(void);


/* Function definitions */
int64_t _1761_main(void){
    int64_t _1762_x;
    int64_t _1761_t2;
    uint8_t _1761_t3;
    int64_t _1761_t5;
    uint8_t _1761_t7;
    int64_t _1761_t10;
    int64_t _1761_$retval;
    int64_t _1761_t8;
    _1762_x = 0;
    goto BB2000;
BB2000:
    _1761_t2 = 100;
    _1761_t3 = _1762_x<_1761_t2;
    if (_1761_t3) {
        goto BB2001;
    } else {
        goto BB2006;
    }
BB2001:
    _1761_t5 = 40;
    _1761_t7 = _1762_x==_1761_t5;
    if (_1761_t7) {
        goto BB2004;
    } else {
        goto BB2010;
    }
BB2006:
    _1761_$retval = _1762_x;
    return _1761_$retval;
BB2004:
    _1761_t8 = 1;
    _1762_x = $add_int64_t(_1762_x, _1761_t8, "tests/integration/whitebox/final-pos.orng:6:17:\n            x += 1\n               ^");
    goto BB2006;
BB2010:
    _1761_t10 = 1;
    _1762_x = $add_int64_t(_1762_x, _1761_t10, "tests/integration/whitebox/final-pos.orng:4:24:\n    while x < 100; x += 1 {\n                      ^");
    goto BB2000;
}


int main(void) {
  printf("%ld",_1761_main());
  return 0;
}
