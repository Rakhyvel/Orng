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
int64_t _775_main(void);
uint8_t _780_f(double _780_x);


/* Function definitions */
int64_t _775_main(void){
    function0 _775_t1;
    double _775_t3;
    uint8_t _775_t2;
    int64_t _775_t0;
    int64_t _775_$retval;
    _775_t1 = (function0) _780_f;
    _775_t3 = 4e0;
    $lines[$line_idx++] = "tests/integration/expressions/mult-zero-float.orng:3:10:\n    if f(4.0) {\n        ^";
    _775_t2 = _775_t1(_775_t3);
    $line_idx--;
    if (_775_t2) {
        goto BB927;
    } else {
        goto BB931;
    }
BB927:
    _775_t0 = 188;
    goto BB930;
BB931:
    _775_t0 = 4;
    goto BB930;
BB930:
    _775_$retval = _775_t0;
    return _775_$retval;
}

uint8_t _780_f(double _780_x){
    uint8_t _780_$retval;
    (void)_780_x;
    goto BB920;
BB920:
    _780_$retval = 1;
    return _780_$retval;
}


int main(void) {
  printf("%ld",_775_main());
  return 0;
}
