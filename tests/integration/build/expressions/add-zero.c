/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef uint8_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _514_main(void);
uint8_t _519_f(int64_t _519_x);

/* Function definitions */
int64_t _514_main(void) {
    function0 _514_t1;
    int64_t _514_t3;
    uint8_t _514_t2;
    int64_t _514_t0;
    int64_t _514_$retval;
    _514_t1 = _519_f;
    _514_t3 = 4;
    $lines[$line_idx++] = "tests/integration/expressions/add-zero.orng:3:10:\n    if f(4) {\n        ^";
    _514_t2 = _514_t1(_514_t3);
    $line_idx--;
    if (_514_t2) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _514_t0 = 182;
    goto BB4;
BB5:
    _514_t0 = 4;
    goto BB4;
BB4:
    _514_$retval = _514_t0;
    return _514_$retval;
}

uint8_t _519_f(int64_t _519_x) {
    uint8_t _519_$retval;
    (void)_519_x;
    _519_$retval = 1;
    return _519_$retval;
}

int main(void) {
  printf("%ld",_514_main());
  return 0;
}
