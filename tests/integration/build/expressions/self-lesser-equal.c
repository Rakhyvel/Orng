/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef uint8_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _758_main(void);
uint8_t _763_f(int64_t _763_x);

/* Function definitions */
int64_t _758_main(void) {
    function0 _758_t1;
    int64_t _758_t3;
    uint8_t _758_t2;
    int64_t _758_t0;
    int64_t _758_$retval;
    _758_t1 = _763_f;
    _758_t3 = 4;
    $lines[$line_idx++] = "tests/integration/expressions/self-lesser-equal.orng:3:10:\n    if f(4) {\n        ^";
    _758_t2 = _758_t1(_758_t3);
    $line_idx--;
    if (_758_t2) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _758_t0 = 228;
    goto BB4;
BB5:
    _758_t0 = 0;
    goto BB4;
BB4:
    _758_$retval = _758_t0;
    return _758_$retval;
}

uint8_t _763_f(int64_t _763_x) {
    uint8_t _763_$retval;
    (void)_763_x;
    _763_$retval = 1;
    return _763_$retval;
}

int main(void) {
  printf("%ld",_758_main());
  return 0;
}
