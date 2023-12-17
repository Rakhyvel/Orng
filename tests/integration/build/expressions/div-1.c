/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef uint8_t(*function0)(double);

/* Function forward definitions */
int64_t _778_main(void);
uint8_t _783_f(double _783_x);

/* Function definitions */
int64_t _778_main(void){
    function0 _778_t1;
    double _778_t3;
    uint8_t _778_t2;
    int64_t _778_t0;
    int64_t _778_$retval;
    _778_t1 = _783_f;
    _778_t3 = 4.0e+00;
    $lines[$line_idx++] = "tests/integration/expressions/div-1.orng:3:10:\n    if f(4.0) {\n        ^";
    _778_t2 = _778_t1(_778_t3);
    $line_idx--;
    if (_778_t2) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _778_t0 = 190;
    goto BB4;
BB5:
    _778_t0 = 4;
    goto BB4;
BB4:
    _778_$retval = _778_t0;
    return _778_$retval;
}

uint8_t _783_f(double _783_x){
    uint8_t _783_t3;
    uint8_t _783_t2;
    uint8_t _783_$retval;
    _783_t3 = _783_x == _783_x;
    if (_783_t3) {
        goto BB1;
    } else {
        goto BB4;
    }
BB1:
    _783_t2 = 1;
    goto BB3;
BB4:
    _783_t2 = 0;
    goto BB3;
BB3:
    _783_$retval = _783_t2;
    return _783_$retval;
}

int main(void) {
  printf("%ld",_778_main());
  return 0;
}
