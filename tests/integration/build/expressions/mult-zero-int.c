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
int64_t _786_main(void);
uint8_t _791_f(int64_t _791_x);


/* Function definitions */
int64_t _786_main(void){
    function0 _786_t1;
    int64_t _786_t3;
    uint8_t _786_t2;
    int64_t _786_t0;
    int64_t _786_$retval;
    _786_t1 = (function0) _791_f;
    _786_t3 = 4;
    $lines[$line_idx++] = "tests/integration/expressions/mult-zero-int.orng:3:10:\n    if f(4) {\n        ^";
    _786_t2 = _786_t1(_786_t3);
    $line_idx--;
    if (_786_t2) {
        goto BB949;
    } else {
        goto BB953;
    }
BB949:
    _786_t0 = 187;
    goto BB952;
BB953:
    _786_t0 = 4;
    goto BB952;
BB952:
    _786_$retval = _786_t0;
    return _786_$retval;
}

uint8_t _791_f(int64_t _791_x){
    uint8_t _791_$retval;
    (void)_791_x;
    goto BB942;
BB942:
    _791_$retval = 1;
    return _791_$retval;
}


int main(void) {
  printf("%ld",_786_main());
  return 0;
}
