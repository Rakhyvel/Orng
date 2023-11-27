/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef uint8_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _344_main(void);
uint8_t _349_f(int64_t _349_x);

/* Function definitions */
int64_t _344_main(void) {
    function0 _344_t1;
    int64_t _344_t3;
    uint8_t _344_t2;
    int64_t _344_t0;
    int64_t _344_$retval;
    _344_t1 = _349_f;
    _344_t3 = 4;
    $lines[$line_idx++] = "tests/integration/expressions/add-zero.orng:3:10:\n    if f(4) {\n        ^";
    _344_t2 = _344_t1(_344_t3);
    $line_idx--;
    if (_344_t2) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _344_t0 = 182;
    goto BB4;
BB5:
    _344_t0 = 4;
    goto BB4;
BB4:
    _344_$retval = _344_t0;
    return _344_$retval;
}

uint8_t _349_f(int64_t _349_x) {
    uint8_t _349_$retval;
    (void)_349_x;
    _349_$retval = 1;
    return _349_$retval;
}

int main(void) {
  printf("%ld",_344_main());
  return 0;
}
