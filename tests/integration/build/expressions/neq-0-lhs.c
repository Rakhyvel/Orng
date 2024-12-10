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
int64_t _809_main(void);
int64_t _811_f(int64_t _811_x);


/* Function definitions */
int64_t _809_main(void){
    function0 _809_t0;
    int64_t _809_t2;
    int64_t _809_t1;
    int64_t _809_$retval;
    _809_t0 = (function0) _811_f;
    _809_t2 = 1;
    $lines[$line_idx++] = "tests/integration/expressions/neq-0-lhs.orng:3:7:\n    f(1)\n     ^";
    _809_t1 = _809_t0(_809_t2);
    $line_idx--;
    _809_$retval = _809_t1;
    return _809_$retval;
}

int64_t _811_f(int64_t _811_x){
    int64_t _811_t1;
    uint8_t _811_t3;
    int64_t _811_t0;
    int64_t _811_$retval;
    _811_t1 = 0;
    _811_t3 = _811_t1==_811_x;
    if (_811_t3) {
        goto BB977;
    } else {
        goto BB973;
    }
BB977:
    _811_t0 = 3;
    goto BB976;
BB973:
    _811_t0 = 174;
    goto BB976;
BB976:
    _811_$retval = _811_t0;
    return _811_$retval;
}


int main(void) {
  printf("%ld",_809_main());
  return 0;
}
