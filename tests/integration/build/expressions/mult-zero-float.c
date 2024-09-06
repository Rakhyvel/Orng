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
int64_t _778_main(void);
uint8_t _783_f(double _783_x);


/* Function definitions */
int64_t _778_main(void){
    function0 _778_t1;
    double _778_t3;
    uint8_t _778_t2;
    int64_t _778_t0;
    int64_t _778_$retval;
    _778_t1 = (function0) _783_f;
    _778_t3 = 4e0;
    $lines[$line_idx++] = "tests/integration/expressions/mult-zero-float.orng:3:10:\n    if f(4.0) {\n        ^";
    _778_t2 = _778_t1(_778_t3);
    $line_idx--;
    if (_778_t2) {
        goto BB930;
    } else {
        goto BB934;
    }
BB930:
    _778_t0 = 188;
    goto BB933;
BB934:
    _778_t0 = 4;
    goto BB933;
BB933:
    _778_$retval = _778_t0;
    return _778_$retval;
}

uint8_t _783_f(double _783_x){
    uint8_t _783_$retval;
    (void)_783_x;
    goto BB923;
BB923:
    _783_$retval = 1;
    return _783_$retval;
}


int main(void) {
  printf("%ld",_778_main());
  return 0;
}
