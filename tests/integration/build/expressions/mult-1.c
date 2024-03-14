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
int64_t _790_main(void);
uint8_t _795_f(int64_t _795_x);


/* Function definitions */
int64_t _790_main(void){
    function0 _790_t1;
    int64_t _790_t3;
    uint8_t _790_t2;
    int64_t _790_t0;
    int64_t _790_$retval;
    _790_t1 = (function0) _795_f;
    _790_t3 = 4;
    $lines[$line_idx++] = "tests/integration/expressions/mult-1.orng:3:10:\n    if f(4) {\n        ^";
    _790_t2 = _790_t1(_790_t3);
    $line_idx--;
    if (_790_t2) {
        goto BB948;
    } else {
        goto BB952;
    }
BB948:
    _790_t0 = 186;
    goto BB951;
BB952:
    _790_t0 = 4;
    goto BB951;
BB951:
    _790_$retval = _790_t0;
    return _790_$retval;
}

uint8_t _795_f(int64_t _795_x){
    uint8_t _795_$retval;
    (void)_795_x;
    _795_$retval = 1;
    return _795_$retval;
}


int main(void) {
  printf("%ld",_790_main());
  return 0;
}
