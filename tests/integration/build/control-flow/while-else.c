/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _509_main(void);


/* Function definitions */
int64_t _509_main(void){
    int64_t _511_x;
    int64_t _509_t3;
    uint8_t _509_t4;
    int64_t _509_t5;
    int64_t _509_t8;
    int64_t _509_$retval;
    _511_x = 0;
    goto BB577;
BB577:
    _509_t3 = 10;
    _509_t4 = _511_x<_509_t3;
    if (_509_t4) {
        goto BB578;
    } else {
        goto BB582;
    }
BB578:
    _509_t5 = 1;
    _511_x = $add_int64_t(_511_x, _509_t5, "tests/integration/control-flow/while-else.orng:4:13:\n        x += 1\n           ^");
    _509_t8 = 1;
    _511_x = $add_int64_t(_511_x, _509_t8, "tests/integration/control-flow/while-else.orng:3:43:\n    while let mut x: Int = 0; x < 10; x += 1 {\n                                         ^");
    goto BB577;
BB582:
    _509_$retval = _511_x;
    return _509_$retval;
}


int main(void) {
  printf("%ld",_509_main());
  return 0;
}
