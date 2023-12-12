/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef uint8_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _520_main(void);
uint8_t _525_f(int64_t _525_x);

/* Function definitions */
int64_t _520_main(void) {
    function0 _520_t1;
    int64_t _520_t3;
    uint8_t _520_t2;
    int64_t _520_t0;
    int64_t _520_$retval;
    _520_t1 = _525_f;
    _520_t3 = 4;
    $lines[$line_idx++] = "tests/integration/expressions/mod-0.orng:3:10:\n    if f(4) {\n        ^";
    _520_t2 = _520_t1(_520_t3);
    $line_idx--;
    if (_520_t2) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _520_t0 = 191;
    goto BB4;
BB5:
    _520_t0 = 4;
    goto BB4;
BB4:
    _520_$retval = _520_t0;
    return _520_$retval;
}

uint8_t _525_f(int64_t _525_x) {
    uint8_t _525_$retval;
    (void)_525_x;
    _525_$retval = 1;
    return _525_$retval;
}

int main(void) {
  printf("%ld",_520_main());
  return 0;
}
