/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef uint8_t(*function0)(double);

/* Function forward definitions */
int64_t _531_main(void);
uint8_t _536_f(double _536_x);

/* Function definitions */
int64_t _531_main(void) {
    function0 _531_t1;
    double _531_t3;
    uint8_t _531_t2;
    int64_t _531_t0;
    int64_t _531_$retval;
    _531_t1 = _536_f;
    _531_t3 = 4.0e+00;
    $lines[$line_idx++] = "tests/integration/expressions/mult-zero-float.orng:3:10:\n    if f(4.0) {\n        ^";
    _531_t2 = _531_t1(_531_t3);
    $line_idx--;
    if (_531_t2) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _531_t0 = 188;
    goto BB4;
BB5:
    _531_t0 = 4;
    goto BB4;
BB4:
    _531_$retval = _531_t0;
    return _531_$retval;
}

uint8_t _536_f(double _536_x) {
    uint8_t _536_$retval;
    (void)_536_x;
    _536_$retval = 1;
    return _536_$retval;
}

int main(void) {
  printf("%ld",_531_main());
  return 0;
}
