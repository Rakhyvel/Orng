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
int64_t _848_main(void);
uint8_t _853_f(int64_t _853_x);


/* Function definitions */
int64_t _848_main(void){
    function0 _848_t1;
    int64_t _848_t3;
    uint8_t _848_t2;
    int64_t _848_t0;
    int64_t _848_$retval;
    _848_t1 = (function0) _853_f;
    _848_t3 = 4;
    $lines[$line_idx++] = "tests/integration/expressions/self-greater-equal.orng:3:10:\n    if f(4) {\n        ^";
    _848_t2 = _848_t1(_848_t3);
    $line_idx--;
    if (_848_t2) {
        goto BB1022;
    } else {
        goto BB1026;
    }
BB1022:
    _848_t0 = 227;
    goto BB1025;
BB1026:
    _848_t0 = 0;
    goto BB1025;
BB1025:
    _848_$retval = _848_t0;
    return _848_$retval;
}

uint8_t _853_f(int64_t _853_x){
    uint8_t _853_$retval;
    (void)_853_x;
    _853_$retval = 1;
    return _853_$retval;
}


int main(void) {
  printf("%ld",_848_main());
  return 0;
}
