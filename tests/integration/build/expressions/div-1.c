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
int64_t _688_main(void);
uint8_t _693_f(double _693_x);


/* Function definitions */
int64_t _688_main(void){
    function0 _688_t1;
    double _688_t3;
    uint8_t _688_t2;
    int64_t _688_t0;
    int64_t _688_$retval;
    _688_t1 = (function0) _693_f;
    _688_t3 = 4e0;
    $lines[$line_idx++] = "tests/integration/expressions/div-1.orng:3:10:\n    if f(4.0) {\n        ^";
    _688_t2 = _688_t1(_688_t3);
    $line_idx--;
    if (_688_t2) {
        goto BB799;
    } else {
        goto BB803;
    }
BB799:
    _688_t0 = 190;
    goto BB802;
BB803:
    _688_t0 = 4;
    goto BB802;
BB802:
    _688_$retval = _688_t0;
    return _688_$retval;
}

uint8_t _693_f(double _693_x){
    uint8_t _693_t3;
    uint8_t _693_t2;
    uint8_t _693_$retval;
    _693_t3 = _693_x==_693_x;
    if (_693_t3) {
        goto BB794;
    } else {
        goto BB797;
    }
BB794:
    _693_t2 = 1;
    goto BB796;
BB797:
    _693_t2 = 0;
    goto BB796;
BB796:
    _693_$retval = _693_t2;
    return _693_$retval;
}


int main(void) {
  printf("%ld",_688_main());
  return 0;
}
