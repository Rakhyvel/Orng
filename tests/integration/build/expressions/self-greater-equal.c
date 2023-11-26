/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef uint8_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _515_main(void);
uint8_t _520_f(int64_t _520_x);

/* Function definitions */
int64_t _515_main(void) {
    function0 _515_t1;
    int64_t _515_t3;
    uint8_t _515_t2;
    int64_t _515_t0;
    int64_t _515_$retval;
    _515_t1 = _520_f;
    _515_t3 = 4;
    $lines[$line_idx++] = "tests/integration/expressions/self-greater-equal.orng:3:10:\n    if f(4) {\n        ^";
    _515_t2 = _515_t1(_515_t3);
    $line_idx--;
    if (_515_t2) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _515_t0 = 227;
    goto BB4;
BB5:
    _515_t0 = 0;
    goto BB4;
BB4:
    _515_$retval = _515_t0;
    return _515_$retval;
}

uint8_t _520_f(int64_t _520_x) {
    uint8_t _520_$retval;
    (void)_520_x;
    _520_$retval = 1;
    return _520_$retval;
}

int main(void) {
  printf("%ld",_515_main());
  return 0;
}
