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
int64_t _847_main(void);
uint8_t _852_f(int64_t _852_x);


/* Function definitions */
int64_t _847_main(void){
    function0 _847_t1;
    int64_t _847_t3;
    uint8_t _847_t2;
    int64_t _847_t0;
    int64_t _847_$retval;
    _847_t1 = (function0) _852_f;
    _847_t3 = 4;
    $lines[$line_idx++] = "tests/integration/expressions/self-lesser-equal.orng:3:10:\n    if f(4) {\n        ^";
    _847_t2 = _847_t1(_847_t3);
    $line_idx--;
    if (_847_t2) {
        goto BB1022;
    } else {
        goto BB1026;
    }
BB1022:
    _847_t0 = 228;
    goto BB1025;
BB1026:
    _847_t0 = 0;
    goto BB1025;
BB1025:
    _847_$retval = _847_t0;
    return _847_$retval;
}

uint8_t _852_f(int64_t _852_x){
    uint8_t _852_$retval;
    (void)_852_x;
    _852_$retval = 1;
    return _852_$retval;
}


int main(void) {
  printf("%ld",_847_main());
  return 0;
}
