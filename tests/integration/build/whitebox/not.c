/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _1_main(void);
int64_t _3_f(uint8_t _3_b);

/* Function definitions */
int64_t _1_main(void) {
    int64_t _2_x;
    int64_t* _2_y;
    uint8_t _1_t5;
    int64_t _1_$retval;
    _2_x = 0;
    _2_y = &_2_x;
    if (*_2_y == 1) {
        goto BB1;
    } else {
        goto BB4;
    }
BB1:
    _1_t5 = 1;
    goto BB2;
BB4:
    _1_t5 = 0;
BB2:
    $lines[$line_idx++] = "tests/integration/whitebox/not.orng:5:7:\n    f(not (y^ == 1))\n     ^";
    $line_idx--;
    _1_$retval = _3_f(!_1_t5);
    return _1_$retval;
}

int64_t _3_f(uint8_t _3_b) {
    int64_t _3_t2;
    int64_t _3_$retval;
    if (_3_b) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _3_t2 = 31;
    goto BB4;
BB5:
    _3_t2 = 10;
BB4:
    _3_$retval = _3_t2;
    return _3_$retval;
}

int main(void)
{
  printf("%ld",_1_main());
  return 0;
}
