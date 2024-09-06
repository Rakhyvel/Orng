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
int64_t _770_main(void);
uint8_t _775_f(double _775_x);


/* Function definitions */
int64_t _770_main(void){
    function0 _770_t1;
    double _770_t3;
    uint8_t _770_t2;
    int64_t _770_t0;
    int64_t _770_$retval;
    _770_t1 = (function0) _775_f;
    _770_t3 = 4e0;
    $lines[$line_idx++] = "tests/integration/expressions/mult-zero-float.orng:3:10:\n    if f(4.0) {\n        ^";
    _770_t2 = _770_t1(_770_t3);
    $line_idx--;
    if (_770_t2) {
        goto BB924;
    } else {
        goto BB928;
    }
BB924:
    _770_t0 = 188;
    goto BB927;
BB928:
    _770_t0 = 4;
    goto BB927;
BB927:
    _770_$retval = _770_t0;
    return _770_$retval;
}

uint8_t _775_f(double _775_x){
    uint8_t _775_$retval;
    (void)_775_x;
    goto BB917;
BB917:
    _775_$retval = 1;
    return _775_$retval;
}


int main(void) {
  printf("%ld",_770_main());
  return 0;
}
