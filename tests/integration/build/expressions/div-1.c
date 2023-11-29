/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef uint8_t(*function0)(double);

/* Function forward definitions */
int64_t _590_main(void);
uint8_t _595_f(double _595_x);

/* Function definitions */
int64_t _590_main(void) {
    function0 _590_t1;
    double _590_t3;
    uint8_t _590_t2;
    int64_t _590_t0;
    int64_t _590_$retval;
    _590_t1 = _595_f;
    _590_t3 = 4.0e+00;
    $lines[$line_idx++] = "tests/integration/expressions/div-1.orng:3:10:\n    if f(4.0) {\n        ^";
    _590_t2 = _590_t1(_590_t3);
    $line_idx--;
    if (_590_t2) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _590_t0 = 190;
    goto BB4;
BB5:
    _590_t0 = 4;
    goto BB4;
BB4:
    _590_$retval = _590_t0;
    return _590_$retval;
}

uint8_t _595_f(double _595_x) {
    uint8_t _595_$retval;
    (void)_595_x;
    _595_$retval = 1;
    return _595_$retval;
}

int main(void) {
  printf("%ld",_590_main());
  return 0;
}
