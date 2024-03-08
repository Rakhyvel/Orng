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
int64_t _700_main(void);
uint8_t _705_f(double _705_x);


/* Function definitions */
int64_t _700_main(void){
    function0 _700_t1;
    double _700_t3;
    uint8_t _700_t2;
    int64_t _700_t0;
    int64_t _700_$retval;
    _700_t1 = (function0) _705_f;
    _700_t3 = 4.0e+00;
    $lines[$line_idx++] = "tests/integration/expressions/div-1.orng:3:10:\n    if f(4.0) {\n        ^";
    _700_t2 = _700_t1(_700_t3);
    $line_idx--;
    if (_700_t2) {
        goto BB838;
    } else {
        goto BB842;
    }
BB838:
    _700_t0 = 190;
    goto BB841;
BB842:
    _700_t0 = 4;
    goto BB841;
BB841:
    _700_$retval = _700_t0;
    return _700_$retval;
}

uint8_t _705_f(double _705_x){
    uint8_t _705_t3;
    uint8_t _705_t2;
    uint8_t _705_$retval;
    _705_t3 = _705_x==_705_x;
    if (_705_t3) {
        goto BB833;
    } else {
        goto BB836;
    }
BB833:
    _705_t2 = 1;
    goto BB835;
BB836:
    _705_t2 = 0;
    goto BB835;
BB835:
    _705_$retval = _705_t2;
    return _705_$retval;
}


int main(void) {
  printf("%ld",_700_main());
  return 0;
}
