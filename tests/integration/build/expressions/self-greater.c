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
int64_t _856_main(void);
uint8_t _861_f(int64_t _861_x);


/* Function definitions */
int64_t _856_main(void){
    function0 _856_t1;
    int64_t _856_t3;
    uint8_t _856_t2;
    int64_t _856_t0;
    int64_t _856_$retval;
    _856_t1 = (function0) _861_f;
    _856_t3 = 4;
    $lines[$line_idx++] = "tests/integration/expressions/self-greater.orng:3:10:\n    if f(4) {\n        ^";
    _856_t2 = _856_t1(_856_t3);
    $line_idx--;
    if (_856_t2) {
        goto BB1031;
    } else {
        goto BB1035;
    }
BB1031:
    _856_t0 = 0;
    goto BB1034;
BB1035:
    _856_t0 = 224;
    goto BB1034;
BB1034:
    _856_$retval = _856_t0;
    return _856_$retval;
}

uint8_t _861_f(int64_t _861_x){
    uint8_t _861_$retval;
    (void)_861_x;
    _861_$retval = 0;
    return _861_$retval;
}


int main(void) {
  printf("%ld",_856_main());
  return 0;
}
