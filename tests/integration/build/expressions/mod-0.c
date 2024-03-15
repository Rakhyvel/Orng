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
int64_t _740_main(void);
uint8_t _745_f(int64_t _745_x);


/* Function definitions */
int64_t _740_main(void){
    function0 _740_t1;
    int64_t _740_t3;
    uint8_t _740_t2;
    int64_t _740_t0;
    int64_t _740_$retval;
    _740_t1 = (function0) _745_f;
    _740_t3 = 4;
    $lines[$line_idx++] = "tests/integration/expressions/mod-0.orng:3:10:\n    if f(4) {\n        ^";
    _740_t2 = _740_t1(_740_t3);
    $line_idx--;
    if (_740_t2) {
        goto BB864;
    } else {
        goto BB868;
    }
BB864:
    _740_t0 = 191;
    goto BB867;
BB868:
    _740_t0 = 4;
    goto BB867;
BB867:
    _740_$retval = _740_t0;
    return _740_$retval;
}

uint8_t _745_f(int64_t _745_x){
    uint8_t _745_$retval;
    (void)_745_x;
    _745_$retval = 1;
    return _745_$retval;
}


int main(void) {
  printf("%ld",_740_main());
  return 0;
}
