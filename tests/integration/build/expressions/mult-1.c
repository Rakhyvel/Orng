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
int64_t _778_main(void);
uint8_t _783_f(int64_t _783_x);


/* Function definitions */
int64_t _778_main(void){
    function0 _778_t1;
    int64_t _778_t3;
    uint8_t _778_t2;
    int64_t _778_t0;
    int64_t _778_$retval;
    _778_t1 = (function0) _783_f;
    _778_t3 = 4;
    $lines[$line_idx++] = "tests/integration/expressions/mult-1.orng:3:10:\n    if f(4) {\n        ^";
    _778_t2 = _778_t1(_778_t3);
    $line_idx--;
    if (_778_t2) {
        goto BB916;
    } else {
        goto BB920;
    }
BB916:
    _778_t0 = 186;
    goto BB919;
BB920:
    _778_t0 = 4;
    goto BB919;
BB919:
    _778_$retval = _778_t0;
    return _778_$retval;
}

uint8_t _783_f(int64_t _783_x){
    uint8_t _783_$retval;
    (void)_783_x;
    goto BB909;
BB909:
    _783_$retval = 1;
    return _783_$retval;
}


int main(void) {
  printf("%ld",_778_main());
  return 0;
}
