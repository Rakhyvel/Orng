/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef uint8_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _634_main(void);
uint8_t _639_f(int64_t _639_x);

/* Function definitions */
int64_t _634_main(void) {
    function0 _634_t1;
    int64_t _634_t3;
    uint8_t _634_t2;
    int64_t _634_t0;
    int64_t _634_$retval;
    _634_t1 = _639_f;
    _634_t3 = 4;
    $lines[$line_idx++] = "tests/integration/expressions/self-lesser-equal.orng:3:10:\n    if f(4) {\n        ^";
    _634_t2 = _634_t1(_634_t3);
    $line_idx--;
    if (_634_t2) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _634_t0 = 228;
    goto BB4;
BB5:
    _634_t0 = 0;
    goto BB4;
BB4:
    _634_$retval = _634_t0;
    return _634_$retval;
}

uint8_t _639_f(int64_t _639_x) {
    uint8_t _639_$retval;
    (void)_639_x;
    _639_$retval = 1;
    return _639_$retval;
}

int main(void) {
  printf("%ld",_634_main());
  return 0;
}
