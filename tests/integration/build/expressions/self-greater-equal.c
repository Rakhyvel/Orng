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
int64_t _831_main(void);
uint8_t _836_f(int64_t _836_x);


/* Function definitions */
int64_t _831_main(void){
    function0 _831_t1;
    int64_t _831_t3;
    uint8_t _831_t2;
    int64_t _831_t0;
    int64_t _831_$retval;
    _831_t1 = (function0) _836_f;
    _831_t3 = 4;
    $lines[$line_idx++] = "tests/integration/expressions/self-greater-equal.orng:3:10:\n    if f(4) {\n        ^";
    _831_t2 = _831_t1(_831_t3);
    $line_idx--;
    if (_831_t2) {
        goto BB1004;
    } else {
        goto BB1008;
    }
BB1004:
    _831_t0 = 227;
    goto BB1007;
BB1008:
    _831_t0 = 0;
    goto BB1007;
BB1007:
    _831_$retval = _831_t0;
    return _831_$retval;
}

uint8_t _836_f(int64_t _836_x){
    uint8_t _836_$retval;
    (void)_836_x;
    _836_$retval = 1;
    return _836_$retval;
}


int main(void) {
  printf("%ld",_831_main());
  return 0;
}
