/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef uint8_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _788_main(void);
uint8_t _793_f(int64_t _793_x);

/* Function definitions */
int64_t _788_main(void) {
    function0 _788_t1;
    int64_t _788_t3;
    uint8_t _788_t2;
    int64_t _788_t0;
    int64_t _788_$retval;
    _788_t1 = _793_f;
    _788_t3 = 4;
    $lines[$line_idx++] = "tests/integration/expressions/self-lesser.orng:3:10:\n    if f(4) {\n        ^";
    _788_t2 = _788_t1(_788_t3);
    $line_idx--;
    if (_788_t2) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _788_t0 = 0;
    goto BB4;
BB5:
    _788_t0 = 226;
    goto BB4;
BB4:
    _788_$retval = _788_t0;
    return _788_$retval;
}

uint8_t _793_f(int64_t _793_x) {
    uint8_t _793_$retval;
    (void)_793_x;
    _793_$retval = 0;
    return _793_$retval;
}

int main(void) {
  printf("%ld",_788_main());
  return 0;
}
