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
int64_t _842_main(void);
uint8_t _847_f(int64_t _847_x);


/* Function definitions */
int64_t _842_main(void){
    function0 _842_t1;
    int64_t _842_t3;
    uint8_t _842_t2;
    int64_t _842_t0;
    int64_t _842_$retval;
    _842_t1 = (function0) _847_f;
    _842_t3 = 4;
    $lines[$line_idx++] = "tests/integration/expressions/self-greater.orng:3:10:\n    if f(4) {\n        ^";
    _842_t2 = _842_t1(_842_t3);
    $line_idx--;
    if (_842_t2) {
        goto BB1016;
    } else {
        goto BB1020;
    }
BB1016:
    _842_t0 = 0;
    goto BB1019;
BB1020:
    _842_t0 = 224;
    goto BB1019;
BB1019:
    _842_$retval = _842_t0;
    return _842_$retval;
}

uint8_t _847_f(int64_t _847_x){
    uint8_t _847_$retval;
    (void)_847_x;
    _847_$retval = 0;
    return _847_$retval;
}


int main(void) {
  printf("%ld",_842_main());
  return 0;
}
