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
int64_t _862_main(void);
uint8_t _867_f(int64_t _867_x);


/* Function definitions */
int64_t _862_main(void){
    function0 _862_t1;
    int64_t _862_t3;
    uint8_t _862_t2;
    int64_t _862_t0;
    int64_t _862_$retval;
    _862_t1 = (function0) _867_f;
    _862_t3 = 4;
    $lines[$line_idx++] = "tests/integration/expressions/self-lesser-equal.orng:3:10:\n    if f(4) {\n        ^";
    _862_t2 = _862_t1(_862_t3);
    $line_idx--;
    if (_862_t2) {
        goto BB1038;
    } else {
        goto BB1042;
    }
BB1038:
    _862_t0 = 228;
    goto BB1041;
BB1042:
    _862_t0 = 0;
    goto BB1041;
BB1041:
    _862_$retval = _862_t0;
    return _862_$retval;
}

uint8_t _867_f(int64_t _867_x){
    uint8_t _867_$retval;
    (void)_867_x;
    _867_$retval = 1;
    return _867_$retval;
}


int main(void) {
  printf("%ld",_862_main());
  return 0;
}
