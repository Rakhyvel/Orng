/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward struct, union, and function declarations */

/* Struct, union, and function definitions */
typedef int64_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _805_main(void);
int64_t _807_f(int64_t _807_x);


/* Function definitions */
int64_t _805_main(void){
    function0 _805_t0;
    int64_t _805_t2;
    int64_t _805_t1;
    int64_t _805_$retval;
    _805_t0 = (function0) _807_f;
    _805_t2 = 1;
    $lines[$line_idx++] = "tests/integration/expressions/neq-0-rhs.orng:3:7:\n    f(1)\n     ^";
    _805_t1 = _805_t0(_805_t2);
    $line_idx--;
    _805_$retval = _805_t1;
    return _805_$retval;
}

int64_t _807_f(int64_t _807_x){
    int64_t _807_t1;
    uint8_t _807_t3;
    int64_t _807_t0;
    int64_t _807_$retval;
    _807_t1 = 0;
    _807_t3 = _807_x==_807_t1;
    if (_807_t3) {
        goto BB976;
    } else {
        goto BB972;
    }
BB976:
    _807_t0 = 3;
    goto BB975;
BB972:
    _807_t0 = 173;
    goto BB975;
BB975:
    _807_$retval = _807_t0;
    return _807_$retval;
}


int main(void) {
  printf("%ld",_805_main());
  return 0;
}
