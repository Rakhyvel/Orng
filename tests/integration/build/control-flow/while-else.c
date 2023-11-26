/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _88_main(void);

/* Function definitions */
int64_t _88_main(void) {
    int64_t _90_x;
    int64_t _88_t2;
    uint8_t _88_t3;
    int64_t _88_t4;
    int64_t _88_t7;
    int64_t _88_$retval;
    _90_x = 0;
    goto BB1;
BB1:
    _88_t2 = 10;
    _88_t3 = _90_x < _88_t2;
    if (_88_t3) {
        goto BB2;
    } else {
        goto BB6;
    }
BB2:
    _88_t4 = 1;
    _90_x = $add_int64_t(_90_x, _88_t4, "tests/integration/control-flow/while-else.orng:4:13:\n        x += 1\n           ^");
    _88_t7 = 1;
    _90_x = $add_int64_t(_90_x, _88_t7, "tests/integration/control-flow/while-else.orng:3:43:\n    while let mut x: Int = 0; x < 10; x += 1 {\n                                         ^");
    goto BB1;
BB6:
    _88_$retval = _90_x;
    return _88_$retval;
}

int main(void) {
  printf("%ld",_88_main());
  return 0;
}
