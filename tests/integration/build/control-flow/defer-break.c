/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _401_main(void);

/* Function definitions */
int64_t _401_main(void){
    int64_t _402_x;
    int64_t _401_t2;
    uint8_t _401_t3;
    int64_t _401_t5;
    uint8_t _401_t6;
    int64_t _401_$retval;
    int64_t _401_t9;
    int64_t _401_t7;
    int64_t _401_t13;
    _402_x = 0;
    goto BB496;
BB496:
    _401_t2 = 100;
    _401_t3 = _402_x < _401_t2;
    if (_401_t3) {
        goto BB497;
    } else {
        goto BB501;
    }
BB497:
    _401_t5 = 36;
    _401_t6 = _402_x >= _401_t5;
    if (_401_t6) {
        goto BB499;
    } else {
        goto BB504;
    }
BB501:
    _401_$retval = _402_x;
    return _401_$retval;
BB499:
    _401_t9 = 2;
    _402_x = $add_int64_t(_402_x, _401_t9, "tests/integration/control-flow/defer-break.orng:5:19:\n        defer x += 2\n                 ^");
    goto BB501;
BB504:
    _401_t7 = 2;
    _402_x = $add_int64_t(_402_x, _401_t7, "tests/integration/control-flow/defer-break.orng:5:19:\n        defer x += 2\n                 ^");
    _401_t13 = 1;
    _402_x = $add_int64_t(_402_x, _401_t13, "tests/integration/control-flow/defer-break.orng:4:24:\n    while x < 100; x += 1 {\n                      ^");
    goto BB496;
}

int main(void) {
  printf("%ld",_401_main());
  return 0;
}
