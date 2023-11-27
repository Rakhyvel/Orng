/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef uint8_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _476_main(void);
uint8_t _481_f(int64_t _481_x);

/* Function definitions */
int64_t _476_main(void) {
    function0 _476_t1;
    int64_t _476_t3;
    uint8_t _476_t2;
    int64_t _476_t0;
    int64_t _476_$retval;
    _476_t1 = _481_f;
    _476_t3 = 4;
    $lines[$line_idx++] = "tests/integration/expressions/mult-1.orng:3:10:\n    if f(4) {\n        ^";
    _476_t2 = _476_t1(_476_t3);
    $line_idx--;
    if (_476_t2) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _476_t0 = 186;
    goto BB4;
BB5:
    _476_t0 = 4;
    goto BB4;
BB4:
    _476_$retval = _476_t0;
    return _476_$retval;
}

uint8_t _481_f(int64_t _481_x) {
    uint8_t _481_$retval;
    (void)_481_x;
    _481_$retval = 1;
    return _481_$retval;
}

int main(void) {
  printf("%ld",_476_main());
  return 0;
}
