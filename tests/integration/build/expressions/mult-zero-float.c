/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef uint8_t(*function0)(double);

/* Function forward definitions */
int64_t _718_main(void);
uint8_t _723_f(double _723_x);

/* Function definitions */
int64_t _718_main(void) {
    function0 _718_t1;
    double _718_t3;
    uint8_t _718_t2;
    int64_t _718_t0;
    int64_t _718_$retval;
    _718_t1 = _723_f;
    _718_t3 = 4.0e+00;
    $lines[$line_idx++] = "tests/integration/expressions/mult-zero-float.orng:3:10:\n    if f(4.0) {\n        ^";
    _718_t2 = _718_t1(_718_t3);
    $line_idx--;
    if (_718_t2) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _718_t0 = 188;
    goto BB4;
BB5:
    _718_t0 = 4;
    goto BB4;
BB4:
    _718_$retval = _718_t0;
    return _718_$retval;
}

uint8_t _723_f(double _723_x) {
    uint8_t _723_$retval;
    (void)_723_x;
    _723_$retval = 1;
    return _723_$retval;
}

int main(void) {
  printf("%ld",_718_main());
  return 0;
}
