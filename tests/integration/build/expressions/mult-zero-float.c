/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef uint8_t(*function0)(double);

/* Function forward definitions */
int64_t _523_main(void);
uint8_t _528_f(double _528_x);

/* Function definitions */
int64_t _523_main(void) {
    function0 _523_t1;
    double _523_t3;
    uint8_t _523_t2;
    int64_t _523_t0;
    int64_t _523_$retval;
    _523_t1 = _528_f;
    _523_t3 = 4.0e+00;
    $lines[$line_idx++] = "tests/integration/expressions/mult-zero-float.orng:3:10:\n    if f(4.0) {\n        ^";
    _523_t2 = _523_t1(_523_t3);
    $line_idx--;
    if (_523_t2) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _523_t0 = 188;
    goto BB4;
BB5:
    _523_t0 = 4;
    goto BB4;
BB4:
    _523_$retval = _523_t0;
    return _523_$retval;
}

uint8_t _528_f(double _528_x) {
    uint8_t _528_$retval;
    (void)_528_x;
    _528_$retval = 1;
    return _528_$retval;
}

int main(void) {
  printf("%ld",_523_main());
  return 0;
}
