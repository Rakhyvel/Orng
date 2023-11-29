/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef uint8_t(*function0)(double);

/* Function forward definitions */
int64_t _458_main(void);
uint8_t _463_f(double _463_x);

/* Function definitions */
int64_t _458_main(void) {
    function0 _458_t1;
    double _458_t3;
    uint8_t _458_t2;
    int64_t _458_t0;
    int64_t _458_$retval;
    _458_t1 = _463_f;
    _458_t3 = 4.0e+00;
    $lines[$line_idx++] = "tests/integration/expressions/div-1.orng:3:10:\n    if f(4.0) {\n        ^";
    _458_t2 = _458_t1(_458_t3);
    $line_idx--;
    if (_458_t2) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _458_t0 = 190;
    goto BB4;
BB5:
    _458_t0 = 4;
    goto BB4;
BB4:
    _458_$retval = _458_t0;
    return _458_$retval;
}

uint8_t _463_f(double _463_x) {
    uint8_t _463_$retval;
    (void)_463_x;
    _463_$retval = 1;
    return _463_$retval;
}

int main(void) {
  printf("%ld",_458_main());
  return 0;
}
