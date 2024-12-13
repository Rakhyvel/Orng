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
int64_t _811_main(void);
int64_t _813_f(int64_t _813_x);


/* Function definitions */
int64_t _811_main(void){
    function0 _811_t0;
    int64_t _811_t2;
    int64_t _811_t1;
    int64_t _811_$retval;
    _811_t0 = (function0) _813_f;
    _811_t2 = 1;
    $lines[$line_idx++] = "tests/integration/expressions/neq-0-lhs.orng:3:7:\n    f(1)\n     ^";
    _811_t1 = _811_t0(_811_t2);
    $line_idx--;
    _811_$retval = _811_t1;
    return _811_$retval;
}

int64_t _813_f(int64_t _813_x){
    int64_t _813_t1;
    uint8_t _813_t3;
    int64_t _813_t0;
    int64_t _813_$retval;
    _813_t1 = 0;
    _813_t3 = _813_t1==_813_x;
    if (_813_t3) {
        goto BB979;
    } else {
        goto BB975;
    }
BB979:
    _813_t0 = 3;
    goto BB978;
BB975:
    _813_t0 = 174;
    goto BB978;
BB978:
    _813_$retval = _813_t0;
    return _813_$retval;
}


int main(void) {
  printf("%ld",_811_main());
  return 0;
}
