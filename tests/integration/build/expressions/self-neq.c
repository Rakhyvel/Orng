/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef uint8_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _242_main(void);
uint8_t _247_f(int64_t _247_x);

/* Function definitions */
int64_t _242_main(void) {
    function0 _242_t1;
    int64_t _242_t3;
    uint8_t _242_t2;
    int64_t _242_t0;
    int64_t _242_$retval;
    _242_t1 = _247_f;
    _242_t3 = 4;
    $lines[$line_idx++] = "tests/integration/expressions/self-neq.orng:3:10:\n    if f(4) {\n        ^";
    _242_t2 = _242_t1(_242_t3);
    $line_idx--;
    if (_242_t2) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _242_t0 = 0;
    goto BB4;
BB5:
    _242_t0 = 223;
    goto BB4;
BB4:
    _242_$retval = _242_t0;
    return _242_$retval;
}

uint8_t _247_f(int64_t _247_x) {
    uint8_t _247_$retval;
    (void)_247_x;
    _247_$retval = 0;
    return _247_$retval;
}

int main(void) {
  printf("%ld",_242_main());
  return 0;
}
