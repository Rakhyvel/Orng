/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef uint8_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _646_main(void);
uint8_t _651_f(int64_t _651_x);

/* Function definitions */
int64_t _646_main(void) {
    function0 _646_t1;
    int64_t _646_t3;
    uint8_t _646_t2;
    int64_t _646_t0;
    int64_t _646_$retval;
    _646_t1 = _651_f;
    _646_t3 = 4;
    $lines[$line_idx++] = "tests/integration/expressions/mod-0.orng:3:10:\n    if f(4) {\n        ^";
    _646_t2 = _646_t1(_646_t3);
    $line_idx--;
    if (_646_t2) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _646_t0 = 191;
    goto BB4;
BB5:
    _646_t0 = 4;
    goto BB4;
BB4:
    _646_$retval = _646_t0;
    return _646_$retval;
}

uint8_t _651_f(int64_t _651_x) {
    uint8_t _651_$retval;
    (void)_651_x;
    _651_$retval = 1;
    return _651_$retval;
}

int main(void) {
  printf("%ld",_646_main());
  return 0;
}
