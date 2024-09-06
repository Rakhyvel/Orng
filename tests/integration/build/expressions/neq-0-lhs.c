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
int64_t _789_main(void);
int64_t _791_f(int64_t _791_x);


/* Function definitions */
int64_t _789_main(void){
    function0 _789_t0;
    int64_t _789_t2;
    int64_t _789_t1;
    int64_t _789_$retval;
    _789_t0 = (function0) _791_f;
    _789_t2 = 1;
    $lines[$line_idx++] = "tests/integration/expressions/neq-0-lhs.orng:3:7:\n    f(1)\n     ^";
    _789_t1 = _789_t0(_789_t2);
    $line_idx--;
    _789_$retval = _789_t1;
    return _789_$retval;
}

int64_t _791_f(int64_t _791_x){
    int64_t _791_t1;
    uint8_t _791_t3;
    int64_t _791_t0;
    int64_t _791_$retval;
    _791_t1 = 0;
    _791_t3 = _791_t1==_791_x;
    if (_791_t3) {
        goto BB958;
    } else {
        goto BB954;
    }
BB958:
    _791_t0 = 3;
    goto BB957;
BB954:
    _791_t0 = 174;
    goto BB957;
BB957:
    _791_$retval = _791_t0;
    return _791_$retval;
}


int main(void) {
  printf("%ld",_789_main());
  return 0;
}
