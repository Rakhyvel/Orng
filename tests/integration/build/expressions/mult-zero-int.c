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
int64_t _800_main(void);
uint8_t _805_f(int64_t _805_x);


/* Function definitions */
int64_t _800_main(void){
    function0 _800_t1;
    int64_t _800_t3;
    uint8_t _800_t2;
    int64_t _800_t0;
    int64_t _800_$retval;
    _800_t1 = (function0) _805_f;
    _800_t3 = 4;
    $lines[$line_idx++] = "tests/integration/expressions/mult-zero-int.orng:3:10:\n    if f(4) {\n        ^";
    _800_t2 = _800_t1(_800_t3);
    $line_idx--;
    if (_800_t2) {
        goto BB964;
    } else {
        goto BB968;
    }
BB964:
    _800_t0 = 187;
    goto BB967;
BB968:
    _800_t0 = 4;
    goto BB967;
BB967:
    _800_$retval = _800_t0;
    return _800_$retval;
}

uint8_t _805_f(int64_t _805_x){
    uint8_t _805_$retval;
    (void)_805_x;
    goto BB957;
BB957:
    _805_$retval = 1;
    return _805_$retval;
}


int main(void) {
  printf("%ld",_800_main());
  return 0;
}
