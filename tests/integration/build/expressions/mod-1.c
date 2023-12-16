/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef uint8_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _696_main(void);
uint8_t _701_f(int64_t _701_x);

/* Function definitions */
int64_t _696_main(void) {
    function0 _696_t1;
    int64_t _696_t3;
    uint8_t _696_t2;
    int64_t _696_t0;
    int64_t _696_$retval;
    _696_t1 = _701_f;
    _696_t3 = 4;
    $lines[$line_idx++] = "tests/integration/expressions/mod-1.orng:3:10:\n    if f(4) {\n        ^";
    _696_t2 = _696_t1(_696_t3);
    $line_idx--;
    if (_696_t2) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _696_t0 = 192;
    goto BB4;
BB5:
    _696_t0 = 4;
    goto BB4;
BB4:
    _696_$retval = _696_t0;
    return _696_$retval;
}

uint8_t _701_f(int64_t _701_x) {
    uint8_t _701_$retval;
    (void)_701_x;
    _701_$retval = 1;
    return _701_$retval;
}

int main(void) {
  printf("%ld",_696_main());
  return 0;
}
