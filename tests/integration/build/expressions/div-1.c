/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef uint8_t(*function0)(double);

/* Function forward definitions */
int64_t _622_main(void);
uint8_t _627_f(double _627_x);

/* Function definitions */
int64_t _622_main(void){
    function0 _622_t1;
    double _622_t3;
    uint8_t _622_t2;
    int64_t _622_t0;
    int64_t _622_$retval;
    _622_t1 = _627_f;
    _622_t3 = 4.0e+00;
    $lines[$line_idx++] = "tests/integration/expressions/div-1.orng:3:10:\n    if f(4.0) {\n        ^";
    _622_t2 = _622_t1(_622_t3);
    $line_idx--;
    if (_622_t2) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _622_t0 = 190;
    goto BB4;
BB5:
    _622_t0 = 4;
    goto BB4;
BB4:
    _622_$retval = _622_t0;
    return _622_$retval;
}

uint8_t _627_f(double _627_x){
    uint8_t _627_t3;
    uint8_t _627_t2;
    uint8_t _627_$retval;
    _627_t3 = _627_x == _627_x;
    if (_627_t3) {
        goto BB1;
    } else {
        goto BB4;
    }
BB1:
    _627_t2 = 1;
    goto BB3;
BB4:
    _627_t2 = 0;
    goto BB3;
BB3:
    _627_$retval = _627_t2;
    return _627_$retval;
}

int main(void) {
  printf("%ld",_622_main());
  return 0;
}
