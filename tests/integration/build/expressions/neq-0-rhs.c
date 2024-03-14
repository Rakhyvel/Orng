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
int64_t _831_main(void);
int64_t _833_f(int64_t _833_x);


/* Function definitions */
int64_t _831_main(void){
    function0 _831_t0;
    int64_t _831_t2;
    int64_t _831_t1;
    int64_t _831_$retval;
    _831_t0 = (function0) _833_f;
    _831_t2 = 1;
    $lines[$line_idx++] = "tests/integration/expressions/neq-0-rhs.orng:3:7:\n    f(1)\n     ^";
    _831_t1 = _831_t0(_831_t2);
    $line_idx--;
    _831_$retval = _831_t1;
    return _831_$retval;
}

int64_t _833_f(int64_t _833_x){
    int64_t _833_t1;
    uint8_t _833_t3;
    int64_t _833_t0;
    int64_t _833_$retval;
    _833_t1 = 0;
    _833_t3 = _833_x==_833_t1;
    if (_833_t3) {
        goto BB1023;
    } else {
        goto BB1019;
    }
BB1023:
    _833_t0 = 3;
    goto BB1022;
BB1019:
    _833_t0 = 173;
    goto BB1022;
BB1022:
    _833_$retval = _833_t0;
    return _833_$retval;
}


int main(void) {
  printf("%ld",_831_main());
  return 0;
}
