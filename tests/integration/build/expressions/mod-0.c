/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef uint8_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _429_main(void);
uint8_t _434_f(int64_t _434_x);

/* Function definitions */
int64_t _429_main(void) {
    function0 _429_t1;
    int64_t _429_t3;
    uint8_t _429_t2;
    int64_t _429_t0;
    int64_t _429_$retval;
    _429_t1 = _434_f;
    _429_t3 = 4;
    $lines[$line_idx++] = "tests/integration/expressions/mod-0.orng:3:10:\n    if f(4) {\n        ^";
    _429_t2 = _429_t1(_429_t3);
    $line_idx--;
    if (_429_t2) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _429_t0 = 191;
    goto BB4;
BB5:
    _429_t0 = 4;
    goto BB4;
BB4:
    _429_$retval = _429_t0;
    return _429_$retval;
}

uint8_t _434_f(int64_t _434_x) {
    uint8_t _434_t4;
    uint8_t _434_t3;
    uint8_t _434_$retval;
    (void)_434_x;
    _434_t4 = 1;
    if (_434_t4) {
        goto BB1;
    } else {
        goto BB4;
    }
BB1:
    _434_t3 = 1;
    goto BB3;
BB4:
    _434_t3 = 0;
    goto BB3;
BB3:
    _434_$retval = _434_t3;
    return _434_$retval;
}

int main(void) {
  printf("%ld",_429_main());
  return 0;
}
