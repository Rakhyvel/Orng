/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef uint8_t(*function0)(double);

/* Function forward definitions */
int64_t _700_main(void);
uint8_t _705_f(double _705_x);

/* Function definitions */
int64_t _700_main(void) {
    function0 _700_t1;
    double _700_t3;
    uint8_t _700_t2;
    int64_t _700_t0;
    int64_t _700_$retval;
    _700_t1 = _705_f;
    _700_t3 = 4.0e+00;
    $lines[$line_idx++] = "tests/integration/expressions/mult-zero-float.orng:3:10:\n    if f(4.0) {\n        ^";
    _700_t2 = _700_t1(_700_t3);
    $line_idx--;
    if (_700_t2) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _700_t0 = 188;
    goto BB4;
BB5:
    _700_t0 = 4;
    goto BB4;
BB4:
    _700_$retval = _700_t0;
    return _700_$retval;
}

uint8_t _705_f(double _705_x) {
    uint8_t _705_$retval;
    (void)_705_x;
    _705_$retval = 1;
    return _705_$retval;
}

int main(void) {
  printf("%ld",_700_main());
  return 0;
}
