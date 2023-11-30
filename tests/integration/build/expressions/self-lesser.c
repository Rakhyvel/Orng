/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef uint8_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _790_main(void);
uint8_t _795_f(int64_t _795_x);

/* Function definitions */
int64_t _790_main(void) {
    function0 _790_t1;
    int64_t _790_t3;
    uint8_t _790_t2;
    int64_t _790_t0;
    int64_t _790_$retval;
    _790_t1 = _795_f;
    _790_t3 = 4;
    $lines[$line_idx++] = "tests/integration/expressions/self-lesser.orng:3:10:\n    if f(4) {\n        ^";
    _790_t2 = _790_t1(_790_t3);
    $line_idx--;
    if (_790_t2) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _790_t0 = 0;
    goto BB4;
BB5:
    _790_t0 = 226;
    goto BB4;
BB4:
    _790_$retval = _790_t0;
    return _790_$retval;
}

uint8_t _795_f(int64_t _795_x) {
    uint8_t _795_$retval;
    (void)_795_x;
    _795_$retval = 0;
    return _795_$retval;
}

int main(void) {
  printf("%ld",_790_main());
  return 0;
}
