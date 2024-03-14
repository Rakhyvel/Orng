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
int64_t _884_main(void);
uint8_t _889_f(int64_t _889_x);


/* Function definitions */
int64_t _884_main(void){
    function0 _884_t1;
    int64_t _884_t3;
    uint8_t _884_t2;
    int64_t _884_t0;
    int64_t _884_$retval;
    _884_t1 = (function0) _889_f;
    _884_t3 = 4;
    $lines[$line_idx++] = "tests/integration/expressions/self-lesser.orng:3:10:\n    if f(4) {\n        ^";
    _884_t2 = _884_t1(_884_t3);
    $line_idx--;
    if (_884_t2) {
        goto BB1081;
    } else {
        goto BB1085;
    }
BB1081:
    _884_t0 = 0;
    goto BB1084;
BB1085:
    _884_t0 = 226;
    goto BB1084;
BB1084:
    _884_$retval = _884_t0;
    return _884_$retval;
}

uint8_t _889_f(int64_t _889_x){
    uint8_t _889_$retval;
    (void)_889_x;
    _889_$retval = 0;
    return _889_$retval;
}


int main(void) {
  printf("%ld",_884_main());
  return 0;
}
