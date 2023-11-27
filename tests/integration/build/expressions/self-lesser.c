/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef uint8_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _570_main(void);
uint8_t _575_f(int64_t _575_x);

/* Function definitions */
int64_t _570_main(void) {
    function0 _570_t1;
    int64_t _570_t3;
    uint8_t _570_t2;
    int64_t _570_t0;
    int64_t _570_$retval;
    _570_t1 = _575_f;
    _570_t3 = 4;
    $lines[$line_idx++] = "tests/integration/expressions/self-lesser.orng:3:10:\n    if f(4) {\n        ^";
    _570_t2 = _570_t1(_570_t3);
    $line_idx--;
    if (_570_t2) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _570_t0 = 0;
    goto BB4;
BB5:
    _570_t0 = 226;
    goto BB4;
BB4:
    _570_$retval = _570_t0;
    return _570_$retval;
}

uint8_t _575_f(int64_t _575_x) {
    uint8_t _575_$retval;
    (void)_575_x;
    _575_$retval = 0;
    return _575_$retval;
}

int main(void) {
  printf("%ld",_570_main());
  return 0;
}
