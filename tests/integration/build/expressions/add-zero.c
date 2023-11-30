/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef uint8_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _537_main(void);
uint8_t _542_f(int64_t _542_x);

/* Function definitions */
int64_t _537_main(void) {
    function0 _537_t1;
    int64_t _537_t3;
    uint8_t _537_t2;
    int64_t _537_t0;
    int64_t _537_$retval;
    _537_t1 = _542_f;
    _537_t3 = 4;
    $lines[$line_idx++] = "tests/integration/expressions/add-zero.orng:3:10:\n    if f(4) {\n        ^";
    _537_t2 = _537_t1(_537_t3);
    $line_idx--;
    if (_537_t2) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _537_t0 = 182;
    goto BB4;
BB5:
    _537_t0 = 4;
    goto BB4;
BB4:
    _537_$retval = _537_t0;
    return _537_$retval;
}

uint8_t _542_f(int64_t _542_x) {
    uint8_t _542_$retval;
    (void)_542_x;
    _542_$retval = 1;
    return _542_$retval;
}

int main(void) {
  printf("%ld",_537_main());
  return 0;
}
