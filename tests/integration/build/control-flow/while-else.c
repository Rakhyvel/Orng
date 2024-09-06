/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _512_main(void);


/* Function definitions */
int64_t _512_main(void){
    int64_t _514_x;
    int64_t _512_t3;
    uint8_t _512_t4;
    int64_t _512_t5;
    int64_t _512_t8;
    int64_t _512_$retval;
    _514_x = 0;
    goto BB580;
BB580:
    _512_t3 = 10;
    _512_t4 = _514_x<_512_t3;
    if (_512_t4) {
        goto BB581;
    } else {
        goto BB585;
    }
BB581:
    _512_t5 = 1;
    _514_x = $add_int64_t(_514_x, _512_t5, "tests/integration/control-flow/while-else.orng:4:13:\n        x += 1\n           ^");
    _512_t8 = 1;
    _514_x = $add_int64_t(_514_x, _512_t8, "tests/integration/control-flow/while-else.orng:3:43:\n    while let mut x: Int = 0; x < 10; x += 1 {\n                                         ^");
    goto BB580;
BB585:
    _512_$retval = _514_x;
    return _512_$retval;
}


int main(void) {
  printf("%ld",_512_main());
  return 0;
}
