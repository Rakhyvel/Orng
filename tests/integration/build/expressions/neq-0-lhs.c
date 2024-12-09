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
int64_t _794_main(void);
int64_t _796_f(int64_t _796_x);


/* Function definitions */
int64_t _794_main(void){
    function0 _794_t0;
    int64_t _794_t2;
    int64_t _794_t1;
    int64_t _794_$retval;
    _794_t0 = (function0) _796_f;
    _794_t2 = 1;
    $lines[$line_idx++] = "tests/integration/expressions/neq-0-lhs.orng:3:7:\n    f(1)\n     ^";
    _794_t1 = _794_t0(_794_t2);
    $line_idx--;
    _794_$retval = _794_t1;
    return _794_$retval;
}

int64_t _796_f(int64_t _796_x){
    int64_t _796_t1;
    uint8_t _796_t3;
    int64_t _796_t0;
    int64_t _796_$retval;
    _796_t1 = 0;
    _796_t3 = _796_t1==_796_x;
    if (_796_t3) {
        goto BB961;
    } else {
        goto BB957;
    }
BB961:
    _796_t0 = 3;
    goto BB960;
BB957:
    _796_t0 = 174;
    goto BB960;
BB960:
    _796_$retval = _796_t0;
    return _796_$retval;
}


int main(void) {
  printf("%ld",_794_main());
  return 0;
}
