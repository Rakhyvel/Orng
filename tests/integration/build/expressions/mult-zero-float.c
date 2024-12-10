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
int64_t _790_main(void);
uint8_t _795_f(double _795_x);


/* Function definitions */
int64_t _790_main(void){
    function0 _790_t1;
    double _790_t3;
    uint8_t _790_t2;
    int64_t _790_t0;
    int64_t _790_$retval;
    _790_t1 = (function0) _795_f;
    _790_t3 = 4e0;
    $lines[$line_idx++] = "tests/integration/expressions/mult-zero-float.orng:3:10:\n    if f(4.0) {\n        ^";
    _790_t2 = _790_t1(_790_t3);
    $line_idx--;
    if (_790_t2) {
        goto BB943;
    } else {
        goto BB947;
    }
BB943:
    _790_t0 = 188;
    goto BB946;
BB947:
    _790_t0 = 4;
    goto BB946;
BB946:
    _790_$retval = _790_t0;
    return _790_$retval;
}

uint8_t _795_f(double _795_x){
    uint8_t _795_$retval;
    (void)_795_x;
    goto BB936;
BB936:
    _795_$retval = 1;
    return _795_$retval;
}


int main(void) {
  printf("%ld",_790_main());
  return 0;
}
