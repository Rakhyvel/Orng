/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef uint8_t(*function0)(double);

/* Function forward definitions */
int64_t _679_main(void);
uint8_t _684_f(double _684_x);

/* Function definitions */
int64_t _679_main(void) {
    function0 _679_t1;
    double _679_t3;
    uint8_t _679_t2;
    int64_t _679_t0;
    int64_t _679_$retval;
    _679_t1 = _684_f;
    _679_t3 = 4.0e+00;
    $lines[$line_idx++] = "tests/integration/expressions/mult-zero-float.orng:3:10:\n    if f(4.0) {\n        ^";
    _679_t2 = _679_t1(_679_t3);
    $line_idx--;
    if (_679_t2) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _679_t0 = 188;
    goto BB4;
BB5:
    _679_t0 = 4;
    goto BB4;
BB4:
    _679_$retval = _679_t0;
    return _679_$retval;
}

uint8_t _684_f(double _684_x) {
    uint8_t _684_$retval;
    (void)_684_x;
    _684_$retval = 1;
    return _684_$retval;
}

int main(void) {
  printf("%ld",_679_main());
  return 0;
}
