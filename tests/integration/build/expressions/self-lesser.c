/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef uint8_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _642_main(void);
uint8_t _647_f(int64_t _647_x);

/* Function definitions */
int64_t _642_main(void) {
    function0 _642_t1;
    int64_t _642_t3;
    uint8_t _642_t2;
    int64_t _642_t0;
    int64_t _642_$retval;
    _642_t1 = _647_f;
    _642_t3 = 4;
    $lines[$line_idx++] = "tests/integration/expressions/self-lesser.orng:3:10:\n    if f(4) {\n        ^";
    _642_t2 = _642_t1(_642_t3);
    $line_idx--;
    if (_642_t2) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _642_t0 = 0;
    goto BB4;
BB5:
    _642_t0 = 226;
    goto BB4;
BB4:
    _642_$retval = _642_t0;
    return _642_$retval;
}

uint8_t _647_f(int64_t _647_x) {
    uint8_t _647_$retval;
    (void)_647_x;
    _647_$retval = 0;
    return _647_$retval;
}

int main(void) {
  printf("%ld",_642_main());
  return 0;
}
