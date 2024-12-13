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
int64_t _872_main(void);
uint8_t _877_f(int64_t _877_x);


/* Function definitions */
int64_t _872_main(void){
    function0 _872_t1;
    int64_t _872_t3;
    uint8_t _872_t2;
    int64_t _872_t0;
    int64_t _872_$retval;
    _872_t1 = (function0) _877_f;
    _872_t3 = 4;
    $lines[$line_idx++] = "tests/integration/expressions/self-lesser.orng:3:10:\n    if f(4) {\n        ^";
    _872_t2 = _872_t1(_872_t3);
    $line_idx--;
    if (_872_t2) {
        goto BB1049;
    } else {
        goto BB1053;
    }
BB1049:
    _872_t0 = 0;
    goto BB1052;
BB1053:
    _872_t0 = 226;
    goto BB1052;
BB1052:
    _872_$retval = _872_t0;
    return _872_$retval;
}

uint8_t _877_f(int64_t _877_x){
    uint8_t _877_$retval;
    (void)_877_x;
    _877_$retval = 0;
    return _877_$retval;
}


int main(void) {
  printf("%ld",_872_main());
  return 0;
}
