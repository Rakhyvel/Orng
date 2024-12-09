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
int64_t _745_main(void);
uint8_t _750_f(int64_t _750_x);


/* Function definitions */
int64_t _745_main(void){
    function0 _745_t1;
    int64_t _745_t3;
    uint8_t _745_t2;
    int64_t _745_t0;
    int64_t _745_$retval;
    _745_t1 = (function0) _750_f;
    _745_t3 = 4;
    $lines[$line_idx++] = "tests/integration/expressions/mod-0.orng:3:10:\n    if f(4) {\n        ^";
    _745_t2 = _745_t1(_745_t3);
    $line_idx--;
    if (_745_t2) {
        goto BB867;
    } else {
        goto BB871;
    }
BB867:
    _745_t0 = 191;
    goto BB870;
BB871:
    _745_t0 = 4;
    goto BB870;
BB870:
    _745_$retval = _745_t0;
    return _745_$retval;
}

uint8_t _750_f(int64_t _750_x){
    uint8_t _750_$retval;
    (void)_750_x;
    goto BB862;
BB862:
    _750_$retval = 1;
    return _750_$retval;
}


int main(void) {
  printf("%ld",_745_main());
  return 0;
}
