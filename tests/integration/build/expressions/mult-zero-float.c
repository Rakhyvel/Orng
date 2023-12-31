/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward typedefs */

/* Typedefs */
typedef uint8_t(*function0)(double);

/* Function forward definitions */
int64_t _777_main(void);
uint8_t _782_f(double _782_x);

/* Function definitions */
int64_t _777_main(void){
    function0 _777_t1;
    double _777_t3;
    uint8_t _777_t2;
    int64_t _777_t0;
    int64_t _777_$retval;
    _777_t1 = _782_f;
    _777_t3 = 4.0e+00;
    $lines[$line_idx++] = "tests/integration/expressions/mult-zero-float.orng:3:10:\n    if f(4.0) {\n        ^";
    _777_t2 = _777_t1(_777_t3);
    $line_idx--;
    if (_777_t2) {
        goto BB972;
    } else {
        goto BB976;
    }
BB972:
    _777_t0 = 188;
    goto BB975;
BB976:
    _777_t0 = 4;
    goto BB975;
BB975:
    _777_$retval = _777_t0;
    return _777_$retval;
}

uint8_t _782_f(double _782_x){
    uint8_t _782_$retval;
    (void)_782_x;
    _782_$retval = 1;
    return _782_$retval;
}

int main(void) {
  printf("%ld",_777_main());
  return 0;
}
