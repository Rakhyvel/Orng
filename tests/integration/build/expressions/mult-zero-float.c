/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef uint8_t(*function0)(double);

/* Function forward definitions */
int64_t _490_main(void);
uint8_t _495_f(double _495_x);

/* Function definitions */
int64_t _490_main(void) {
    function0 _490_t1;
    double _490_t3;
    uint8_t _490_t2;
    int64_t _490_t0;
    int64_t _490_$retval;
    _490_t1 = _495_f;
    _490_t3 = 4.0e+00;
    $lines[$line_idx++] = "tests/integration/expressions/mult-zero-float.orng:3:10:\n    if f(4.0) {\n        ^";
    _490_t2 = _490_t1(_490_t3);
    $line_idx--;
    if (_490_t2) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _490_t0 = 188;
    goto BB4;
BB5:
    _490_t0 = 4;
    goto BB4;
BB4:
    _490_$retval = _490_t0;
    return _490_$retval;
}

uint8_t _495_f(double _495_x) {
    uint8_t _495_$retval;
    (void)_495_x;
    _495_$retval = 1;
    return _495_$retval;
}

int main(void) {
  printf("%ld",_490_main());
  return 0;
}
