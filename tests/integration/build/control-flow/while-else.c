/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _504_main(void);


/* Function definitions */
int64_t _504_main(void){
    int64_t _506_x;
    int64_t _504_t3;
    uint8_t _504_t4;
    int64_t _504_t5;
    int64_t _504_t8;
    int64_t _504_$retval;
    _506_x = 0;
    goto BB574;
BB574:
    _504_t3 = 10;
    _504_t4 = _506_x<_504_t3;
    if (_504_t4) {
        goto BB575;
    } else {
        goto BB579;
    }
BB575:
    _504_t5 = 1;
    _506_x = $add_int64_t(_506_x, _504_t5, "tests/integration/control-flow/while-else.orng:4:13:\n        x += 1\n           ^");
    _504_t8 = 1;
    _506_x = $add_int64_t(_506_x, _504_t8, "tests/integration/control-flow/while-else.orng:3:43:\n    while let mut x: Int = 0; x < 10; x += 1 {\n                                         ^");
    goto BB574;
BB579:
    _504_$retval = _506_x;
    return _504_$retval;
}


int main(void) {
  printf("%ld",_504_main());
  return 0;
}
