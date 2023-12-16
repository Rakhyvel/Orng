/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef uint8_t(*function0)(double);

/* Function forward definitions */
int64_t _737_main(void);
uint8_t _742_f(double _742_x);

/* Function definitions */
int64_t _737_main(void){
    function0 _737_t1;
    double _737_t3;
    uint8_t _737_t2;
    int64_t _737_t0;
    int64_t _737_$retval;
    _737_t1 = _742_f;
    _737_t3 = 4.0e+00;
    $lines[$line_idx++] = "tests/integration/expressions/mult-zero-float.orng:3:10:\n    if f(4.0) {\n        ^";
    _737_t2 = _737_t1(_737_t3);
    $line_idx--;
    if (_737_t2) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _737_t0 = 188;
    goto BB4;
BB5:
    _737_t0 = 4;
    goto BB4;
BB4:
    _737_$retval = _737_t0;
    return _737_$retval;
}

uint8_t _742_f(double _742_x){
    uint8_t _742_$retval;
    (void)_742_x;
    _742_$retval = 1;
    return _742_$retval;
}

int main(void) {
  printf("%ld",_737_main());
  return 0;
}
