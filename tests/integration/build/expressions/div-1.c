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
int64_t _666_main(void);
uint8_t _671_f(double _671_x);


/* Function definitions */
int64_t _666_main(void){
    function0 _666_t1;
    double _666_t3;
    uint8_t _666_t2;
    int64_t _666_t0;
    int64_t _666_$retval;
    _666_t1 = (function0) _671_f;
    _666_t3 = 4e0;
    $lines[$line_idx++] = "tests/integration/expressions/div-1.orng:3:10:\n    if f(4.0) {\n        ^";
    _666_t2 = _666_t1(_666_t3);
    $line_idx--;
    if (_666_t2) {
        goto BB778;
    } else {
        goto BB782;
    }
BB778:
    _666_t0 = 190;
    goto BB781;
BB782:
    _666_t0 = 4;
    goto BB781;
BB781:
    _666_$retval = _666_t0;
    return _666_$retval;
}

uint8_t _671_f(double _671_x){
    uint8_t _671_t3;
    uint8_t _671_t2;
    uint8_t _671_$retval;
    _671_t3 = _671_x==_671_x;
    if (_671_t3) {
        goto BB773;
    } else {
        goto BB776;
    }
BB773:
    _671_t2 = 1;
    goto BB775;
BB776:
    _671_t2 = 0;
    goto BB775;
BB775:
    _671_$retval = _671_t2;
    return _671_$retval;
}


int main(void) {
  printf("%ld",_666_main());
  return 0;
}
