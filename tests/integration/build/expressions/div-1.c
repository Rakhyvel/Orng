/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef uint8_t(*function0)(double);

/* Function forward definitions */
int64_t _785_main(void);
uint8_t _790_f(double _790_x);

/* Function definitions */
int64_t _785_main(void){
    function0 _785_t1;
    double _785_t3;
    uint8_t _785_t2;
    int64_t _785_t0;
    int64_t _785_$retval;
    _785_t1 = _790_f;
    _785_t3 = 4.0e+00;
    $lines[$line_idx++] = "tests/integration/expressions/div-1.orng:3:10:\n    if f(4.0) {\n        ^";
    _785_t2 = _785_t1(_785_t3);
    $line_idx--;
    if (_785_t2) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _785_t0 = 190;
    goto BB4;
BB5:
    _785_t0 = 4;
    goto BB4;
BB4:
    _785_$retval = _785_t0;
    return _785_$retval;
}

uint8_t _790_f(double _790_x){
    uint8_t _790_t3;
    uint8_t _790_t2;
    uint8_t _790_$retval;
    _790_t3 = _790_x == _790_x;
    if (_790_t3) {
        goto BB1;
    } else {
        goto BB4;
    }
BB1:
    _790_t2 = 1;
    goto BB3;
BB4:
    _790_t2 = 0;
    goto BB3;
BB3:
    _790_$retval = _790_t2;
    return _790_$retval;
}

int main(void) {
  printf("%ld",_785_main());
  return 0;
}
