/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef uint8_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _501_main(void);
uint8_t _506_f(int64_t _506_x);

/* Function definitions */
int64_t _501_main(void) {
    function0 _501_t1;
    int64_t _501_t3;
    uint8_t _501_t2;
    int64_t _501_t0;
    int64_t _501_$retval;
    _501_t1 = _506_f;
    _501_t3 = 4;
    $lines[$line_idx++] = "tests/integration/expressions/mod-0.orng:3:10:\n    if f(4) {\n        ^";
    _501_t2 = _501_t1(_501_t3);
    $line_idx--;
    if (_501_t2) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _501_t0 = 191;
    goto BB4;
BB5:
    _501_t0 = 4;
    goto BB4;
BB4:
    _501_$retval = _501_t0;
    return _501_$retval;
}

uint8_t _506_f(int64_t _506_x) {
    uint8_t _506_$retval;
    (void)_506_x;
    _506_$retval = 1;
    return _506_$retval;
}

int main(void) {
  printf("%ld",_501_main());
  return 0;
}
