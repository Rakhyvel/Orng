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
int64_t _855_main(void);
uint8_t _860_f(int64_t _860_x);


/* Function definitions */
int64_t _855_main(void){
    function0 _855_t1;
    int64_t _855_t3;
    uint8_t _855_t2;
    int64_t _855_t0;
    int64_t _855_$retval;
    _855_t1 = (function0) _860_f;
    _855_t3 = 4;
    $lines[$line_idx++] = "tests/integration/expressions/self-lesser.orng:3:10:\n    if f(4) {\n        ^";
    _855_t2 = _855_t1(_855_t3);
    $line_idx--;
    if (_855_t2) {
        goto BB1031;
    } else {
        goto BB1035;
    }
BB1031:
    _855_t0 = 0;
    goto BB1034;
BB1035:
    _855_t0 = 226;
    goto BB1034;
BB1034:
    _855_$retval = _855_t0;
    return _855_$retval;
}

uint8_t _860_f(int64_t _860_x){
    uint8_t _860_$retval;
    (void)_860_x;
    _860_$retval = 0;
    return _860_$retval;
}


int main(void) {
  printf("%ld",_855_main());
  return 0;
}
