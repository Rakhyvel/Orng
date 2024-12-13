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
int64_t _864_main(void);
uint8_t _869_f(int64_t _869_x);


/* Function definitions */
int64_t _864_main(void){
    function0 _864_t1;
    int64_t _864_t3;
    uint8_t _864_t2;
    int64_t _864_t0;
    int64_t _864_$retval;
    _864_t1 = (function0) _869_f;
    _864_t3 = 4;
    $lines[$line_idx++] = "tests/integration/expressions/self-lesser-equal.orng:3:10:\n    if f(4) {\n        ^";
    _864_t2 = _864_t1(_864_t3);
    $line_idx--;
    if (_864_t2) {
        goto BB1040;
    } else {
        goto BB1044;
    }
BB1040:
    _864_t0 = 228;
    goto BB1043;
BB1044:
    _864_t0 = 0;
    goto BB1043;
BB1043:
    _864_$retval = _864_t0;
    return _864_$retval;
}

uint8_t _869_f(int64_t _869_x){
    uint8_t _869_$retval;
    (void)_869_x;
    _869_$retval = 1;
    return _869_$retval;
}


int main(void) {
  printf("%ld",_864_main());
  return 0;
}
