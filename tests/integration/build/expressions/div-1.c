/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef uint8_t(*function0)(double);

/* Function forward definitions */
int64_t _355_main(void);
uint8_t _360_f(double _360_x);

/* Function definitions */
int64_t _355_main(void) {
    function0 _355_t1;
    double _355_t3;
    uint8_t _355_t2;
    int64_t _355_t0;
    int64_t _355_$retval;
    _355_t1 = _360_f;
    _355_t3 = 4.0e+00;
    $lines[$line_idx++] = "tests/integration/expressions/div-1.orng:3:10:\n    if f(4.0) {\n        ^";
    _355_t2 = _355_t1(_355_t3);
    $line_idx--;
    if (_355_t2) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _355_t0 = 190;
    goto BB4;
BB5:
    _355_t0 = 4;
    goto BB4;
BB4:
    _355_$retval = _355_t0;
    return _355_$retval;
}

uint8_t _360_f(double _360_x) {
    uint8_t _360_t3;
    uint8_t _360_t2;
    uint8_t _360_$retval;
    (void)_360_x;
    _360_t3 = 1;
    if (_360_t3) {
        goto BB1;
    } else {
        goto BB4;
    }
BB1:
    _360_t2 = 1;
    goto BB3;
BB4:
    _360_t2 = 0;
    goto BB3;
BB3:
    _360_$retval = _360_t2;
    return _360_$retval;
}

int main(void) {
  printf("%ld",_355_main());
  return 0;
}
