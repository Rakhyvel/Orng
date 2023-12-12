/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef uint8_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _517_main(void);
uint8_t _522_f(int64_t _522_x);

/* Function definitions */
int64_t _517_main(void) {
    function0 _517_t1;
    int64_t _517_t3;
    uint8_t _517_t2;
    int64_t _517_t0;
    int64_t _517_$retval;
    _517_t1 = _522_f;
    _517_t3 = 4;
    $lines[$line_idx++] = "tests/integration/expressions/mult-1.orng:3:10:\n    if f(4) {\n        ^";
    _517_t2 = _517_t1(_517_t3);
    $line_idx--;
    if (_517_t2) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _517_t0 = 186;
    goto BB4;
BB5:
    _517_t0 = 4;
    goto BB4;
BB4:
    _517_$retval = _517_t0;
    return _517_$retval;
}

uint8_t _522_f(int64_t _522_x) {
    uint8_t _522_$retval;
    (void)_522_x;
    _522_$retval = 1;
    return _522_$retval;
}

int main(void) {
  printf("%ld",_517_main());
  return 0;
}
