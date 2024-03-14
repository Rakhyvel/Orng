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
int64_t _804_main(void);
uint8_t _809_f(double _809_x);


/* Function definitions */
int64_t _804_main(void){
    function0 _804_t1;
    double _804_t3;
    uint8_t _804_t2;
    int64_t _804_t0;
    int64_t _804_$retval;
    _804_t1 = (function0) _809_f;
    _804_t3 = 4.0e+00;
    $lines[$line_idx++] = "tests/integration/expressions/mult-zero-float.orng:3:10:\n    if f(4.0) {\n        ^";
    _804_t2 = _804_t1(_804_t3);
    $line_idx--;
    if (_804_t2) {
        goto BB977;
    } else {
        goto BB981;
    }
BB977:
    _804_t0 = 188;
    goto BB980;
BB981:
    _804_t0 = 4;
    goto BB980;
BB980:
    _804_$retval = _804_t0;
    return _804_$retval;
}

uint8_t _809_f(double _809_x){
    uint8_t _809_$retval;
    (void)_809_x;
    _809_$retval = 1;
    return _809_$retval;
}


int main(void) {
  printf("%ld",_804_main());
  return 0;
}
