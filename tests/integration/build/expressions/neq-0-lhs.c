/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward typedefs */

/* Typedefs */
typedef int64_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _796_main(void);
int64_t _798_f(int64_t _798_x);

/* Function definitions */
int64_t _796_main(void){
    function0 _796_t0;
    int64_t _796_t2;
    int64_t _796_t1;
    int64_t _796_$retval;
    _796_t0 = _798_f;
    _796_t2 = 1;
    $lines[$line_idx++] = "tests/integration/expressions/neq-0-lhs.orng:3:7:\n    f(1)\n     ^";
    _796_t1 = _796_t0(_796_t2);
    $line_idx--;
    _796_$retval = _796_t1;
    return _796_$retval;
}

int64_t _798_f(int64_t _798_x){
    int64_t _798_t1;
    uint8_t _798_t3;
    int64_t _798_t0;
    int64_t _798_$retval;
    _798_t1 = 0;
    _798_t3 = _798_t1==_798_x;
    if (_798_t3) {
        goto BB996;
    } else {
        goto BB992;
    }
BB996:
    _798_t0 = 3;
    goto BB995;
BB992:
    _798_t0 = 174;
    goto BB995;
BB995:
    _798_$retval = _798_t0;
    return _798_$retval;
}

int main(void) {
  printf("%ld",_796_main());
  return 0;
}
