/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef uint8_t(*function0)(double);

/* Function forward definitions */
int64_t _702_main(void);
uint8_t _707_f(double _707_x);

/* Function definitions */
int64_t _702_main(void) {
    function0 _702_t1;
    double _702_t3;
    uint8_t _702_t2;
    int64_t _702_t0;
    int64_t _702_$retval;
    _702_t1 = _707_f;
    _702_t3 = 4.0e+00;
    $lines[$line_idx++] = "tests/integration/expressions/mult-zero-float.orng:3:10:\n    if f(4.0) {\n        ^";
    _702_t2 = _702_t1(_702_t3);
    $line_idx--;
    if (_702_t2) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _702_t0 = 188;
    goto BB4;
BB5:
    _702_t0 = 4;
    goto BB4;
BB4:
    _702_$retval = _702_t0;
    return _702_$retval;
}

uint8_t _707_f(double _707_x) {
    uint8_t _707_$retval;
    (void)_707_x;
    _707_$retval = 1;
    return _707_$retval;
}

int main(void) {
  printf("%ld",_702_main());
  return 0;
}
