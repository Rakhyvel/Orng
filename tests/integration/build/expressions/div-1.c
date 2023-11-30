/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef uint8_t(*function0)(double);

/* Function forward definitions */
int64_t _569_main(void);
uint8_t _574_f(double _574_x);

/* Function definitions */
int64_t _569_main(void) {
    function0 _569_t1;
    double _569_t3;
    uint8_t _569_t2;
    int64_t _569_t0;
    int64_t _569_$retval;
    _569_t1 = _574_f;
    _569_t3 = 4.0e+00;
    $lines[$line_idx++] = "tests/integration/expressions/div-1.orng:3:10:\n    if f(4.0) {\n        ^";
    _569_t2 = _569_t1(_569_t3);
    $line_idx--;
    if (_569_t2) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _569_t0 = 190;
    goto BB4;
BB5:
    _569_t0 = 4;
    goto BB4;
BB4:
    _569_$retval = _569_t0;
    return _569_$retval;
}

uint8_t _574_f(double _574_x) {
    uint8_t _574_$retval;
    (void)_574_x;
    _574_$retval = 1;
    return _574_$retval;
}

int main(void) {
  printf("%ld",_569_main());
  return 0;
}
