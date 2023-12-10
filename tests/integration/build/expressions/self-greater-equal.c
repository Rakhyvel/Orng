/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef uint8_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _579_main(void);
uint8_t _584_f(int64_t _584_x);

/* Function definitions */
int64_t _579_main(void) {
    function0 _579_t1;
    int64_t _579_t3;
    uint8_t _579_t2;
    int64_t _579_t0;
    int64_t _579_$retval;
    _579_t1 = _584_f;
    _579_t3 = 4;
    $lines[$line_idx++] = "tests/integration/expressions/self-greater-equal.orng:3:10:\n    if f(4) {\n        ^";
    _579_t2 = _579_t1(_579_t3);
    $line_idx--;
    if (_579_t2) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _579_t0 = 227;
    goto BB4;
BB5:
    _579_t0 = 0;
    goto BB4;
BB4:
    _579_$retval = _579_t0;
    return _579_$retval;
}

uint8_t _584_f(int64_t _584_x) {
    uint8_t _584_$retval;
    (void)_584_x;
    _584_$retval = 1;
    return _584_$retval;
}

int main(void) {
  printf("%ld",_579_main());
  return 0;
}
