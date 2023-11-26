/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef uint8_t(*function0)(double);

/* Function forward definitions */
int64_t _50_main(void);
uint8_t _55_f(double _55_x);

/* Function definitions */
int64_t _50_main(void) {
    function0 _50_t1;
    double _50_t3;
    uint8_t _50_t2;
    int64_t _50_t0;
    int64_t _50_$retval;
    _50_t1 = _55_f;
    _50_t3 = 4.0e+00;
    $lines[$line_idx++] = "tests/integration/expressions/div-1.orng:3:10:\n    if f(4.0) {\n        ^";
    _50_t2 = _50_t1(_50_t3);
    $line_idx--;
    if (_50_t2) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _50_t0 = 190;
    goto BB4;
BB5:
    _50_t0 = 4;
    goto BB4;
BB4:
    _50_$retval = _50_t0;
    return _50_$retval;
}

uint8_t _55_f(double _55_x) {
    uint8_t _55_t3;
    uint8_t _55_t2;
    uint8_t _55_$retval;
    (void)_55_x;
    _55_t3 = 1;
    if (_55_t3) {
        goto BB1;
    } else {
        goto BB4;
    }
BB1:
    _55_t2 = 1;
    goto BB3;
BB4:
    _55_t2 = 0;
    goto BB3;
BB3:
    _55_$retval = _55_t2;
    return _55_$retval;
}

int main(void) {
  printf("%ld",_50_main());
  return 0;
}
