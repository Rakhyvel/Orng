/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _1666_main(void);


/* Function definitions */
int64_t _1666_main(void){
    int64_t _1667_x;
    int64_t _1666_t2;
    uint8_t _1666_t3;
    int64_t _1666_t5;
    uint8_t _1666_t7;
    int64_t _1666_t10;
    int64_t _1666_$retval;
    int64_t _1666_t8;
    _1667_x = 0;
    goto BB1926;
BB1926:
    _1666_t2 = 100;
    _1666_t3 = _1667_x<_1666_t2;
    if (_1666_t3) {
        goto BB1927;
    } else {
        goto BB1932;
    }
BB1927:
    _1666_t5 = 40;
    _1666_t7 = _1667_x==_1666_t5;
    if (_1666_t7) {
        goto BB1930;
    } else {
        goto BB1936;
    }
BB1932:
    _1666_$retval = _1667_x;
    return _1666_$retval;
BB1930:
    _1666_t8 = 1;
    _1667_x = $add_int64_t(_1667_x, _1666_t8, "tests/integration/whitebox/final-pos.orng:6:17:\n            x += 1\n               ^");
    goto BB1932;
BB1936:
    _1666_t10 = 1;
    _1667_x = $add_int64_t(_1667_x, _1666_t10, "tests/integration/whitebox/final-pos.orng:4:24:\n    while x < 100; x += 1 {\n                      ^");
    goto BB1926;
}


int main(void) {
  printf("%ld",_1666_main());
  return 0;
}
