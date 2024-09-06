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
int64_t _797_main(void);
int64_t _799_f(int64_t _799_x);


/* Function definitions */
int64_t _797_main(void){
    function0 _797_t0;
    int64_t _797_t2;
    int64_t _797_t1;
    int64_t _797_$retval;
    _797_t0 = (function0) _799_f;
    _797_t2 = 1;
    $lines[$line_idx++] = "tests/integration/expressions/neq-0-rhs.orng:3:7:\n    f(1)\n     ^";
    _797_t1 = _797_t0(_797_t2);
    $line_idx--;
    _797_$retval = _797_t1;
    return _797_$retval;
}

int64_t _799_f(int64_t _799_x){
    int64_t _799_t1;
    uint8_t _799_t3;
    int64_t _799_t0;
    int64_t _799_$retval;
    _799_t1 = 0;
    _799_t3 = _799_x==_799_t1;
    if (_799_t3) {
        goto BB970;
    } else {
        goto BB966;
    }
BB970:
    _799_t0 = 3;
    goto BB969;
BB966:
    _799_t0 = 173;
    goto BB969;
BB969:
    _799_$retval = _799_t0;
    return _799_$retval;
}


int main(void) {
  printf("%ld",_797_main());
  return 0;
}
