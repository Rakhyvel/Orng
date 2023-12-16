/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef uint8_t(*function0)(double);

/* Function forward definitions */
int64_t _693_main(void);
uint8_t _698_f(double _698_x);

/* Function definitions */
int64_t _693_main(void){
    function0 _693_t1;
    double _693_t3;
    uint8_t _693_t2;
    int64_t _693_t0;
    int64_t _693_$retval;
    _693_t1 = _698_f;
    _693_t3 = 4.0e+00;
    $lines[$line_idx++] = "tests/integration/expressions/div-1.orng:3:10:\n    if f(4.0) {\n        ^";
    _693_t2 = _693_t1(_693_t3);
    $line_idx--;
    if (_693_t2) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _693_t0 = 190;
    goto BB4;
BB5:
    _693_t0 = 4;
    goto BB4;
BB4:
    _693_$retval = _693_t0;
    return _693_$retval;
}

uint8_t _698_f(double _698_x){
    uint8_t _698_t3;
    uint8_t _698_t2;
    uint8_t _698_$retval;
    _698_t3 = _698_x == _698_x;
    if (_698_t3) {
        goto BB1;
    } else {
        goto BB4;
    }
BB1:
    _698_t2 = 1;
    goto BB3;
BB4:
    _698_t2 = 0;
    goto BB3;
BB3:
    _698_$retval = _698_t2;
    return _698_$retval;
}

int main(void) {
  printf("%ld",_693_main());
  return 0;
}
