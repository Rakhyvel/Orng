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
int64_t _846_main(void);
uint8_t _851_f(int64_t _851_x);


/* Function definitions */
int64_t _846_main(void){
    function0 _846_t1;
    int64_t _846_t3;
    uint8_t _846_t2;
    int64_t _846_t0;
    int64_t _846_$retval;
    _846_t1 = (function0) _851_f;
    _846_t3 = 4;
    $lines[$line_idx++] = "tests/integration/expressions/self-greater-equal.orng:3:10:\n    if f(4) {\n        ^";
    _846_t2 = _846_t1(_846_t3);
    $line_idx--;
    if (_846_t2) {
        goto BB1020;
    } else {
        goto BB1024;
    }
BB1020:
    _846_t0 = 227;
    goto BB1023;
BB1024:
    _846_t0 = 0;
    goto BB1023;
BB1023:
    _846_$retval = _846_t0;
    return _846_$retval;
}

uint8_t _851_f(int64_t _851_x){
    uint8_t _851_$retval;
    (void)_851_x;
    _851_$retval = 1;
    return _851_$retval;
}


int main(void) {
  printf("%ld",_846_main());
  return 0;
}
