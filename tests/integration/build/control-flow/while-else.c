/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _526_main(void);


/* Function definitions */
int64_t _526_main(void){
    int64_t _528_x;
    int64_t _526_t3;
    uint8_t _526_t4;
    int64_t _526_t5;
    int64_t _526_t8;
    int64_t _526_$retval;
    _528_x = 0;
    goto BB595;
BB595:
    _526_t3 = 10;
    _526_t4 = _528_x<_526_t3;
    if (_526_t4) {
        goto BB596;
    } else {
        goto BB600;
    }
BB596:
    _526_t5 = 1;
    _528_x = $add_int64_t(_528_x, _526_t5, "tests/integration/control-flow/while-else.orng:4:13:\n        x += 1\n           ^");
    _526_t8 = 1;
    _528_x = $add_int64_t(_528_x, _526_t8, "tests/integration/control-flow/while-else.orng:3:43:\n    while let mut x: Int = 0; x < 10; x += 1 {\n                                         ^");
    goto BB595;
BB600:
    _526_$retval = _528_x;
    return _526_$retval;
}


int main(void) {
  printf("%ld",_526_main());
  return 0;
}
