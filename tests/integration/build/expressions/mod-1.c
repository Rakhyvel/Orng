/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward struct, union, and function declarations */

/* Struct, union, and function definitions */
typedef uint8_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _782_main(void);
uint8_t _787_f(int64_t _787_x);


/* Function definitions */
int64_t _782_main(void){
    function0 _782_t1;
    int64_t _782_t3;
    uint8_t _782_t2;
    int64_t _782_t0;
    int64_t _782_$retval;
    _782_t1 = (function0) _787_f;
    _782_t3 = 4;
    $lines[$line_idx++] = "tests/integration/expressions/mod-1.orng:3:10:\n    if f(4) {\n        ^";
    _782_t2 = _782_t1(_782_t3);
    $line_idx--;
    if (_782_t2) {
        goto BB936;
    } else {
        goto BB940;
    }
BB936:
    _782_t0 = 192;
    goto BB939;
BB940:
    _782_t0 = 4;
    goto BB939;
BB939:
    _782_$retval = _782_t0;
    return _782_$retval;
}

uint8_t _787_f(int64_t _787_x){
    uint8_t _787_$retval;
    (void)_787_x;
    _787_$retval = 1;
    return _787_$retval;
}


int main(void) {
  printf("%ld",_782_main());
  return 0;
}
