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
int64_t _671_main(void);
uint8_t _676_f(double _676_x);


/* Function definitions */
int64_t _671_main(void){
    function0 _671_t1;
    double _671_t3;
    uint8_t _671_t2;
    int64_t _671_t0;
    int64_t _671_$retval;
    _671_t1 = (function0) _676_f;
    _671_t3 = 4e0;
    $lines[$line_idx++] = "tests/integration/expressions/div-1.orng:3:10:\n    if f(4.0) {\n        ^";
    _671_t2 = _671_t1(_671_t3);
    $line_idx--;
    if (_671_t2) {
        goto BB781;
    } else {
        goto BB785;
    }
BB781:
    _671_t0 = 190;
    goto BB784;
BB785:
    _671_t0 = 4;
    goto BB784;
BB784:
    _671_$retval = _671_t0;
    return _671_$retval;
}

uint8_t _676_f(double _676_x){
    uint8_t _676_t3;
    uint8_t _676_t2;
    uint8_t _676_$retval;
    _676_t3 = _676_x==_676_x;
    if (_676_t3) {
        goto BB776;
    } else {
        goto BB779;
    }
BB776:
    _676_t2 = 1;
    goto BB778;
BB779:
    _676_t2 = 0;
    goto BB778;
BB778:
    _676_$retval = _676_t2;
    return _676_$retval;
}


int main(void) {
  printf("%ld",_671_main());
  return 0;
}
