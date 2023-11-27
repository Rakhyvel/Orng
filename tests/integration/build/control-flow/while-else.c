/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _211_main(void);

/* Function definitions */
int64_t _211_main(void) {
    int64_t _213_x;
    int64_t _211_t2;
    uint8_t _211_t3;
    int64_t _211_t4;
    int64_t _211_t7;
    int64_t _211_$retval;
    _213_x = 0;
    goto BB1;
BB1:
    _211_t2 = 10;
    _211_t3 = _213_x < _211_t2;
    if (_211_t3) {
        goto BB2;
    } else {
        goto BB6;
    }
BB2:
    _211_t4 = 1;
    _213_x = $add_int64_t(_213_x, _211_t4, "tests/integration/control-flow/while-else.orng:4:13:\n        x += 1\n           ^");
    _211_t7 = 1;
    _213_x = $add_int64_t(_213_x, _211_t7, "tests/integration/control-flow/while-else.orng:3:43:\n    while let mut x: Int = 0; x < 10; x += 1 {\n                                         ^");
    goto BB1;
BB6:
    _211_$retval = _213_x;
    return _211_$retval;
}

int main(void) {
  printf("%ld",_211_main());
  return 0;
}
