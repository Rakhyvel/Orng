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
int64_t _764_main(void);
uint8_t _769_f(int64_t _769_x);


/* Function definitions */
int64_t _764_main(void){
    function0 _764_t1;
    int64_t _764_t3;
    uint8_t _764_t2;
    int64_t _764_t0;
    int64_t _764_$retval;
    _764_t1 = (function0) _769_f;
    _764_t3 = 4;
    $lines[$line_idx++] = "tests/integration/expressions/mult-1.orng:3:10:\n    if f(4) {\n        ^";
    _764_t2 = _764_t1(_764_t3);
    $line_idx--;
    if (_764_t2) {
        goto BB901;
    } else {
        goto BB905;
    }
BB901:
    _764_t0 = 186;
    goto BB904;
BB905:
    _764_t0 = 4;
    goto BB904;
BB904:
    _764_$retval = _764_t0;
    return _764_$retval;
}

uint8_t _769_f(int64_t _769_x){
    uint8_t _769_$retval;
    (void)_769_x;
    goto BB894;
BB894:
    _769_$retval = 1;
    return _769_$retval;
}


int main(void) {
  printf("%ld",_764_main());
  return 0;
}
