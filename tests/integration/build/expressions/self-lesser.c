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
int64_t _870_main(void);
uint8_t _875_f(int64_t _875_x);


/* Function definitions */
int64_t _870_main(void){
    function0 _870_t1;
    int64_t _870_t3;
    uint8_t _870_t2;
    int64_t _870_t0;
    int64_t _870_$retval;
    _870_t1 = (function0) _875_f;
    _870_t3 = 4;
    $lines[$line_idx++] = "tests/integration/expressions/self-lesser.orng:3:10:\n    if f(4) {\n        ^";
    _870_t2 = _870_t1(_870_t3);
    $line_idx--;
    if (_870_t2) {
        goto BB1047;
    } else {
        goto BB1051;
    }
BB1047:
    _870_t0 = 0;
    goto BB1050;
BB1051:
    _870_t0 = 226;
    goto BB1050;
BB1050:
    _870_$retval = _870_t0;
    return _870_$retval;
}

uint8_t _875_f(int64_t _875_x){
    uint8_t _875_$retval;
    (void)_875_x;
    _875_$retval = 0;
    return _875_$retval;
}


int main(void) {
  printf("%ld",_870_main());
  return 0;
}
