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
int64_t _686_main(void);
uint8_t _691_f(double _691_x);


/* Function definitions */
int64_t _686_main(void){
    function0 _686_t1;
    double _686_t3;
    uint8_t _686_t2;
    int64_t _686_t0;
    int64_t _686_$retval;
    _686_t1 = (function0) _691_f;
    _686_t3 = 4e0;
    $lines[$line_idx++] = "tests/integration/expressions/div-1.orng:3:10:\n    if f(4.0) {\n        ^";
    _686_t2 = _686_t1(_686_t3);
    $line_idx--;
    if (_686_t2) {
        goto BB797;
    } else {
        goto BB801;
    }
BB797:
    _686_t0 = 190;
    goto BB800;
BB801:
    _686_t0 = 4;
    goto BB800;
BB800:
    _686_$retval = _686_t0;
    return _686_$retval;
}

uint8_t _691_f(double _691_x){
    uint8_t _691_t3;
    uint8_t _691_t2;
    uint8_t _691_$retval;
    _691_t3 = _691_x==_691_x;
    if (_691_t3) {
        goto BB792;
    } else {
        goto BB795;
    }
BB792:
    _691_t2 = 1;
    goto BB794;
BB795:
    _691_t2 = 0;
    goto BB794;
BB794:
    _691_$retval = _691_t2;
    return _691_$retval;
}


int main(void) {
  printf("%ld",_686_main());
  return 0;
}
