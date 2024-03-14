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
int64_t _876_main(void);
uint8_t _881_f(int64_t _881_x);


/* Function definitions */
int64_t _876_main(void){
    function0 _876_t1;
    int64_t _876_t3;
    uint8_t _876_t2;
    int64_t _876_t0;
    int64_t _876_$retval;
    _876_t1 = (function0) _881_f;
    _876_t3 = 4;
    $lines[$line_idx++] = "tests/integration/expressions/self-lesser-equal.orng:3:10:\n    if f(4) {\n        ^";
    _876_t2 = _876_t1(_876_t3);
    $line_idx--;
    if (_876_t2) {
        goto BB1072;
    } else {
        goto BB1076;
    }
BB1072:
    _876_t0 = 228;
    goto BB1075;
BB1076:
    _876_t0 = 0;
    goto BB1075;
BB1075:
    _876_$retval = _876_t0;
    return _876_$retval;
}

uint8_t _881_f(int64_t _881_x){
    uint8_t _881_$retval;
    (void)_881_x;
    _881_$retval = 1;
    return _881_$retval;
}


int main(void) {
  printf("%ld",_876_main());
  return 0;
}
