/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef uint8_t(*function0)(double);

/* Function forward definitions */
int64_t _592_main(void);
uint8_t _597_f(double _597_x);

/* Function definitions */
int64_t _592_main(void) {
    function0 _592_t1;
    double _592_t3;
    uint8_t _592_t2;
    int64_t _592_t0;
    int64_t _592_$retval;
    _592_t1 = _597_f;
    _592_t3 = 4.0e+00;
    $lines[$line_idx++] = "tests/integration/expressions/div-1.orng:3:10:\n    if f(4.0) {\n        ^";
    _592_t2 = _592_t1(_592_t3);
    $line_idx--;
    if (_592_t2) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _592_t0 = 190;
    goto BB4;
BB5:
    _592_t0 = 4;
    goto BB4;
BB4:
    _592_$retval = _592_t0;
    return _592_$retval;
}

uint8_t _597_f(double _597_x) {
    uint8_t _597_$retval;
    (void)_597_x;
    _597_$retval = 1;
    return _597_$retval;
}

int main(void) {
  printf("%ld",_592_main());
  return 0;
}
