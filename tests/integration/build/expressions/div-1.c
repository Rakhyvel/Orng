/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef uint8_t(*function0)(double);

/* Function forward definitions */
int64_t _661_main(void);
uint8_t _666_f(double _666_x);

/* Function definitions */
int64_t _661_main(void){
    function0 _661_t1;
    double _661_t3;
    uint8_t _661_t2;
    int64_t _661_t0;
    int64_t _661_$retval;
    _661_t1 = _666_f;
    _661_t3 = 4.0e+00;
    $lines[$line_idx++] = "tests/integration/expressions/div-1.orng:3:10:\n    if f(4.0) {\n        ^";
    _661_t2 = _661_t1(_661_t3);
    $line_idx--;
    if (_661_t2) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _661_t0 = 190;
    goto BB4;
BB5:
    _661_t0 = 4;
    goto BB4;
BB4:
    _661_$retval = _661_t0;
    return _661_$retval;
}

uint8_t _666_f(double _666_x){
    uint8_t _666_t3;
    uint8_t _666_t2;
    uint8_t _666_$retval;
    _666_t3 = _666_x == _666_x;
    if (_666_t3) {
        goto BB1;
    } else {
        goto BB4;
    }
BB1:
    _666_t2 = 1;
    goto BB3;
BB4:
    _666_t2 = 0;
    goto BB3;
BB3:
    _666_$retval = _666_t2;
    return _666_$retval;
}

int main(void) {
  printf("%ld",_661_main());
  return 0;
}
