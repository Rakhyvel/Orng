/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef uint8_t(*function0)(double);

/* Function forward definitions */
int64_t _386_main(void);
uint8_t _391_f(double _391_x);

/* Function definitions */
int64_t _386_main(void) {
    function0 _386_t1;
    double _386_t3;
    uint8_t _386_t2;
    int64_t _386_t0;
    int64_t _386_$retval;
    _386_t1 = _391_f;
    _386_t3 = 4.0e+00;
    $lines[$line_idx++] = "tests/integration/expressions/div-1.orng:3:10:\n    if f(4.0) {\n        ^";
    _386_t2 = _386_t1(_386_t3);
    $line_idx--;
    if (_386_t2) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _386_t0 = 190;
    goto BB4;
BB5:
    _386_t0 = 4;
    goto BB4;
BB4:
    _386_$retval = _386_t0;
    return _386_$retval;
}

uint8_t _391_f(double _391_x) {
    uint8_t _391_$retval;
    (void)_391_x;
    _391_$retval = 1;
    return _391_$retval;
}

int main(void) {
  printf("%ld",_386_main());
  return 0;
}
