/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward struct, union, and function declarations */

/* Struct, union, and function definitions */
typedef uint8_t(*function0)(double);

/* Function forward definitions */
int64_t _674_main(void);
uint8_t _679_f(double _679_x);


/* Function definitions */
int64_t _674_main(void){
    function0 _674_t1;
    double _674_t3;
    uint8_t _674_t2;
    int64_t _674_t0;
    int64_t _674_$retval;
    _674_t1 = (function0) _679_f;
    _674_t3 = 4e0;
    $lines[$line_idx++] = "tests/integration/expressions/div-1.orng:3:10:\n    if f(4.0) {\n        ^";
    _674_t2 = _674_t1(_674_t3);
    $line_idx--;
    if (_674_t2) {
        goto BB784;
    } else {
        goto BB788;
    }
BB784:
    _674_t0 = 190;
    goto BB787;
BB788:
    _674_t0 = 4;
    goto BB787;
BB787:
    _674_$retval = _674_t0;
    return _674_$retval;
}

uint8_t _679_f(double _679_x){
    uint8_t _679_t3;
    uint8_t _679_t2;
    uint8_t _679_$retval;
    _679_t3 = _679_x==_679_x;
    if (_679_t3) {
        goto BB779;
    } else {
        goto BB782;
    }
BB779:
    _679_t2 = 1;
    goto BB781;
BB782:
    _679_t2 = 0;
    goto BB781;
BB781:
    _679_$retval = _679_t2;
    return _679_$retval;
}


int main(void) {
  printf("%ld",_674_main());
  return 0;
}
