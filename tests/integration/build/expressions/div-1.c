/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef uint8_t(*function0)(double);

/* Function forward definitions */
int64_t _419_main(void);
uint8_t _424_f(double _424_x);

/* Function definitions */
int64_t _419_main(void) {
    function0 _419_t1;
    double _419_t3;
    uint8_t _419_t2;
    int64_t _419_t0;
    int64_t _419_$retval;
    _419_t1 = _424_f;
    _419_t3 = 4.0e+00;
    $lines[$line_idx++] = "tests/integration/expressions/div-1.orng:3:10:\n    if f(4.0) {\n        ^";
    _419_t2 = _419_t1(_419_t3);
    $line_idx--;
    if (_419_t2) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _419_t0 = 190;
    goto BB4;
BB5:
    _419_t0 = 4;
    goto BB4;
BB4:
    _419_$retval = _419_t0;
    return _419_$retval;
}

uint8_t _424_f(double _424_x) {
    uint8_t _424_$retval;
    (void)_424_x;
    _424_$retval = 1;
    return _424_$retval;
}

int main(void) {
  printf("%ld",_419_main());
  return 0;
}
