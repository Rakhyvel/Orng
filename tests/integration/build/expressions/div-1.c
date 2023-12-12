/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef uint8_t(*function0)(double);

/* Function forward definitions */
int64_t _446_main(void);
uint8_t _451_f(double _451_x);

/* Function definitions */
int64_t _446_main(void) {
    function0 _446_t1;
    double _446_t3;
    uint8_t _446_t2;
    int64_t _446_t0;
    int64_t _446_$retval;
    _446_t1 = _451_f;
    _446_t3 = 4.0e+00;
    $lines[$line_idx++] = "tests/integration/expressions/div-1.orng:3:10:\n    if f(4.0) {\n        ^";
    _446_t2 = _446_t1(_446_t3);
    $line_idx--;
    if (_446_t2) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _446_t0 = 190;
    goto BB4;
BB5:
    _446_t0 = 4;
    goto BB4;
BB4:
    _446_$retval = _446_t0;
    return _446_$retval;
}

uint8_t _451_f(double _451_x) {
    uint8_t _451_$retval;
    (void)_451_x;
    _451_$retval = 1;
    return _451_$retval;
}

int main(void) {
  printf("%ld",_446_main());
  return 0;
}
