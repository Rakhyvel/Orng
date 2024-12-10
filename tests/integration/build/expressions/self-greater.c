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
int64_t _854_main(void);
uint8_t _859_f(int64_t _859_x);


/* Function definitions */
int64_t _854_main(void){
    function0 _854_t1;
    int64_t _854_t3;
    uint8_t _854_t2;
    int64_t _854_t0;
    int64_t _854_$retval;
    _854_t1 = (function0) _859_f;
    _854_t3 = 4;
    $lines[$line_idx++] = "tests/integration/expressions/self-greater.orng:3:10:\n    if f(4) {\n        ^";
    _854_t2 = _854_t1(_854_t3);
    $line_idx--;
    if (_854_t2) {
        goto BB1029;
    } else {
        goto BB1033;
    }
BB1029:
    _854_t0 = 0;
    goto BB1032;
BB1033:
    _854_t0 = 224;
    goto BB1032;
BB1032:
    _854_$retval = _854_t0;
    return _854_$retval;
}

uint8_t _859_f(int64_t _859_x){
    uint8_t _859_$retval;
    (void)_859_x;
    _859_$retval = 0;
    return _859_$retval;
}


int main(void) {
  printf("%ld",_854_main());
  return 0;
}
