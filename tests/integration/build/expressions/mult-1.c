/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef uint8_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _664_main(void);
uint8_t _669_f(int64_t _669_x);

/* Function definitions */
int64_t _664_main(void) {
    function0 _664_t1;
    int64_t _664_t3;
    uint8_t _664_t2;
    int64_t _664_t0;
    int64_t _664_$retval;
    _664_t1 = _669_f;
    _664_t3 = 4;
    $lines[$line_idx++] = "tests/integration/expressions/mult-1.orng:3:10:\n    if f(4) {\n        ^";
    _664_t2 = _664_t1(_664_t3);
    $line_idx--;
    if (_664_t2) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _664_t0 = 186;
    goto BB4;
BB5:
    _664_t0 = 4;
    goto BB4;
BB4:
    _664_$retval = _664_t0;
    return _664_$retval;
}

uint8_t _669_f(int64_t _669_x) {
    uint8_t _669_$retval;
    (void)_669_x;
    _669_$retval = 1;
    return _669_$retval;
}

int main(void) {
  printf("%ld",_664_main());
  return 0;
}
