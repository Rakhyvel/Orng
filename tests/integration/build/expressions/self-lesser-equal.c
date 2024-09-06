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
int64_t _850_main(void);
uint8_t _855_f(int64_t _855_x);


/* Function definitions */
int64_t _850_main(void){
    function0 _850_t1;
    int64_t _850_t3;
    uint8_t _850_t2;
    int64_t _850_t0;
    int64_t _850_$retval;
    _850_t1 = (function0) _855_f;
    _850_t3 = 4;
    $lines[$line_idx++] = "tests/integration/expressions/self-lesser-equal.orng:3:10:\n    if f(4) {\n        ^";
    _850_t2 = _850_t1(_850_t3);
    $line_idx--;
    if (_850_t2) {
        goto BB1025;
    } else {
        goto BB1029;
    }
BB1025:
    _850_t0 = 228;
    goto BB1028;
BB1029:
    _850_t0 = 0;
    goto BB1028;
BB1028:
    _850_$retval = _850_t0;
    return _850_$retval;
}

uint8_t _855_f(int64_t _855_x){
    uint8_t _855_$retval;
    (void)_855_x;
    _855_$retval = 1;
    return _855_$retval;
}


int main(void) {
  printf("%ld",_850_main());
  return 0;
}
