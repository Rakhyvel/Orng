/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef uint8_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _833_main(void);
uint8_t _838_f(int64_t _838_x);

/* Function definitions */
int64_t _833_main(void){
    function0 _833_t1;
    int64_t _833_t3;
    uint8_t _833_t2;
    int64_t _833_t0;
    int64_t _833_$retval;
    _833_t1 = _838_f;
    _833_t3 = 4;
    $lines[$line_idx++] = "tests/integration/expressions/self-greater-equal.orng:3:10:\n    if f(4) {\n        ^";
    _833_t2 = _833_t1(_833_t3);
    $line_idx--;
    if (_833_t2) {
        goto BB1049;
    } else {
        goto BB1053;
    }
BB1049:
    _833_t0 = 227;
    goto BB1052;
BB1053:
    _833_t0 = 0;
    goto BB1052;
BB1052:
    _833_$retval = _833_t0;
    return _833_$retval;
}

uint8_t _838_f(int64_t _838_x){
    uint8_t _838_$retval;
    (void)_838_x;
    _838_$retval = 1;
    return _838_$retval;
}

int main(void) {
  printf("%ld",_833_main());
  return 0;
}
