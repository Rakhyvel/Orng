/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef uint8_t(*function0)(double);

/* Function forward definitions */
int64_t _427_main(void);
uint8_t _432_f(double _432_x);

/* Function definitions */
int64_t _427_main(void) {
    function0 _427_t1;
    double _427_t3;
    uint8_t _427_t2;
    int64_t _427_t0;
    int64_t _427_$retval;
    _427_t1 = _432_f;
    _427_t3 = 4.0e+00;
    $lines[$line_idx++] = "tests/integration/expressions/div-1.orng:3:10:\n    if f(4.0) {\n        ^";
    _427_t2 = _427_t1(_427_t3);
    $line_idx--;
    if (_427_t2) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _427_t0 = 190;
    goto BB4;
BB5:
    _427_t0 = 4;
    goto BB4;
BB4:
    _427_$retval = _427_t0;
    return _427_$retval;
}

uint8_t _432_f(double _432_x) {
    uint8_t _432_$retval;
    (void)_432_x;
    _432_$retval = 1;
    return _432_$retval;
}

int main(void) {
  printf("%ld",_427_main());
  return 0;
}
