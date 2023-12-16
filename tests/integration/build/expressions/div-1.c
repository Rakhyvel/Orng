/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef uint8_t(*function0)(double);

/* Function forward definitions */
int64_t _633_main(void);
uint8_t _638_f(double _638_x);

/* Function definitions */
int64_t _633_main(void){
    function0 _633_t1;
    double _633_t3;
    uint8_t _633_t2;
    int64_t _633_t0;
    int64_t _633_$retval;
    _633_t1 = _638_f;
    _633_t3 = 4.0e+00;
    $lines[$line_idx++] = "tests/integration/expressions/div-1.orng:3:10:\n    if f(4.0) {\n        ^";
    _633_t2 = _633_t1(_633_t3);
    $line_idx--;
    if (_633_t2) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _633_t0 = 190;
    goto BB4;
BB5:
    _633_t0 = 4;
    goto BB4;
BB4:
    _633_$retval = _633_t0;
    return _633_$retval;
}

uint8_t _638_f(double _638_x){
    uint8_t _638_t3;
    uint8_t _638_t2;
    uint8_t _638_$retval;
    _638_t3 = _638_x == _638_x;
    if (_638_t3) {
        goto BB1;
    } else {
        goto BB4;
    }
BB1:
    _638_t2 = 1;
    goto BB3;
BB4:
    _638_t2 = 0;
    goto BB3;
BB3:
    _638_$retval = _638_t2;
    return _638_$retval;
}

int main(void) {
  printf("%ld",_633_main());
  return 0;
}
