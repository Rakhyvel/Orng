/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef uint8_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _678_main(void);
uint8_t _683_f(int64_t _683_x);

/* Function definitions */
int64_t _678_main(void) {
    function0 _678_t1;
    int64_t _678_t3;
    uint8_t _678_t2;
    int64_t _678_t0;
    int64_t _678_$retval;
    _678_t1 = _683_f;
    _678_t3 = 4;
    $lines[$line_idx++] = "tests/integration/expressions/mod-1.orng:3:10:\n    if f(4) {\n        ^";
    _678_t2 = _678_t1(_678_t3);
    $line_idx--;
    if (_678_t2) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _678_t0 = 192;
    goto BB4;
BB5:
    _678_t0 = 4;
    goto BB4;
BB4:
    _678_$retval = _678_t0;
    return _678_$retval;
}

uint8_t _683_f(int64_t _683_x) {
    uint8_t _683_$retval;
    (void)_683_x;
    _683_$retval = 1;
    return _683_$retval;
}

int main(void) {
  printf("%ld",_678_main());
  return 0;
}
