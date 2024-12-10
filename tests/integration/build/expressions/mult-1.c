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
int64_t _776_main(void);
uint8_t _781_f(int64_t _781_x);


/* Function definitions */
int64_t _776_main(void){
    function0 _776_t1;
    int64_t _776_t3;
    uint8_t _776_t2;
    int64_t _776_t0;
    int64_t _776_$retval;
    _776_t1 = (function0) _781_f;
    _776_t3 = 4;
    $lines[$line_idx++] = "tests/integration/expressions/mult-1.orng:3:10:\n    if f(4) {\n        ^";
    _776_t2 = _776_t1(_776_t3);
    $line_idx--;
    if (_776_t2) {
        goto BB914;
    } else {
        goto BB918;
    }
BB914:
    _776_t0 = 186;
    goto BB917;
BB918:
    _776_t0 = 4;
    goto BB917;
BB917:
    _776_$retval = _776_t0;
    return _776_$retval;
}

uint8_t _781_f(int64_t _781_x){
    uint8_t _781_$retval;
    (void)_781_x;
    goto BB907;
BB907:
    _781_$retval = 1;
    return _781_$retval;
}


int main(void) {
  printf("%ld",_776_main());
  return 0;
}
