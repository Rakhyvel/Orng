/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _505_main(void);


/* Function definitions */
int64_t _505_main(void){
    int64_t _507_x;
    int64_t _505_t2;
    uint8_t _505_t3;
    int64_t _505_t4;
    int64_t _505_t7;
    int64_t _505_$retval;
    _507_x = 0;
    goto BB584;
BB584:
    _505_t2 = 10;
    _505_t3 = _507_x<_505_t2;
    if (_505_t3) {
        goto BB585;
    } else {
        goto BB589;
    }
BB585:
    _505_t4 = 1;
    _507_x = $add_int64_t(_507_x, _505_t4, "tests/integration/control-flow/while-else.orng:4:13:\n        x += 1\n           ^");
    _505_t7 = 1;
    _507_x = $add_int64_t(_507_x, _505_t7, "tests/integration/control-flow/while-else.orng:3:43:\n    while let mut x: Int = 0; x < 10; x += 1 {\n                                         ^");
    goto BB584;
BB589:
    _505_$retval = _507_x;
    return _505_$retval;
}


int main(void) {
  printf("%ld",_505_main());
  return 0;
}
