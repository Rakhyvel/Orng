/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef uint8_t(*function0)(double);

/* Function forward definitions */
int64_t _614_main(void);
uint8_t _619_f(double _619_x);

/* Function definitions */
int64_t _614_main(void) {
    function0 _614_t1;
    double _614_t3;
    uint8_t _614_t2;
    int64_t _614_t0;
    int64_t _614_$retval;
    _614_t1 = _619_f;
    _614_t3 = 4.0e+00;
    $lines[$line_idx++] = "tests/integration/expressions/div-1.orng:3:10:\n    if f(4.0) {\n        ^";
    _614_t2 = _614_t1(_614_t3);
    $line_idx--;
    if (_614_t2) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _614_t0 = 190;
    goto BB4;
BB5:
    _614_t0 = 4;
    goto BB4;
BB4:
    _614_$retval = _614_t0;
    return _614_$retval;
}

uint8_t _619_f(double _619_x) {
    uint8_t _619_$retval;
    (void)_619_x;
    _619_$retval = 1;
    return _619_$retval;
}

int main(void) {
  printf("%ld",_614_main());
  return 0;
}
