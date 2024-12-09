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
int64_t _839_main(void);
uint8_t _844_f(int64_t _844_x);


/* Function definitions */
int64_t _839_main(void){
    function0 _839_t1;
    int64_t _839_t3;
    uint8_t _839_t2;
    int64_t _839_t0;
    int64_t _839_$retval;
    _839_t1 = (function0) _844_f;
    _839_t3 = 4;
    $lines[$line_idx++] = "tests/integration/expressions/self-greater.orng:3:10:\n    if f(4) {\n        ^";
    _839_t2 = _839_t1(_839_t3);
    $line_idx--;
    if (_839_t2) {
        goto BB1013;
    } else {
        goto BB1017;
    }
BB1013:
    _839_t0 = 0;
    goto BB1016;
BB1017:
    _839_t0 = 224;
    goto BB1016;
BB1016:
    _839_$retval = _839_t0;
    return _839_$retval;
}

uint8_t _844_f(int64_t _844_x){
    uint8_t _844_$retval;
    (void)_844_x;
    _844_$retval = 0;
    return _844_$retval;
}


int main(void) {
  printf("%ld",_839_main());
  return 0;
}
