/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef uint8_t(*function0)(double);

/* Function forward definitions */
int64_t _550_main(void);
uint8_t _555_f(double _555_x);

/* Function definitions */
int64_t _550_main(void) {
    function0 _550_t1;
    double _550_t3;
    uint8_t _550_t2;
    int64_t _550_t0;
    int64_t _550_$retval;
    _550_t1 = _555_f;
    _550_t3 = 4.0e+00;
    $lines[$line_idx++] = "tests/integration/expressions/mult-zero-float.orng:3:10:\n    if f(4.0) {\n        ^";
    _550_t2 = _550_t1(_550_t3);
    $line_idx--;
    if (_550_t2) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _550_t0 = 188;
    goto BB4;
BB5:
    _550_t0 = 4;
    goto BB4;
BB4:
    _550_$retval = _550_t0;
    return _550_$retval;
}

uint8_t _555_f(double _555_x) {
    uint8_t _555_$retval;
    (void)_555_x;
    _555_$retval = 1;
    return _555_$retval;
}

int main(void) {
  printf("%ld",_550_main());
  return 0;
}
