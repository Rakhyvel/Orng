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
int64_t _792_main(void);
uint8_t _797_f(double _797_x);


/* Function definitions */
int64_t _792_main(void){
    function0 _792_t1;
    double _792_t3;
    uint8_t _792_t2;
    int64_t _792_t0;
    int64_t _792_$retval;
    _792_t1 = (function0) _797_f;
    _792_t3 = 4e0;
    $lines[$line_idx++] = "tests/integration/expressions/mult-zero-float.orng:3:10:\n    if f(4.0) {\n        ^";
    _792_t2 = _792_t1(_792_t3);
    $line_idx--;
    if (_792_t2) {
        goto BB945;
    } else {
        goto BB949;
    }
BB945:
    _792_t0 = 188;
    goto BB948;
BB949:
    _792_t0 = 4;
    goto BB948;
BB948:
    _792_$retval = _792_t0;
    return _792_$retval;
}

uint8_t _797_f(double _797_x){
    uint8_t _797_$retval;
    (void)_797_x;
    goto BB938;
BB938:
    _797_$retval = 1;
    return _797_$retval;
}


int main(void) {
  printf("%ld",_792_main());
  return 0;
}
