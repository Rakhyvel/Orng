/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef uint8_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _709_main(void);
uint8_t _714_f(int64_t _714_x);

/* Function definitions */
int64_t _709_main(void) {
    function0 _709_t1;
    int64_t _709_t3;
    uint8_t _709_t2;
    int64_t _709_t0;
    int64_t _709_$retval;
    _709_t1 = _714_f;
    _709_t3 = 4;
    $lines[$line_idx++] = "tests/integration/expressions/mult-zero-int.orng:3:10:\n    if f(4) {\n        ^";
    _709_t2 = _709_t1(_709_t3);
    $line_idx--;
    if (_709_t2) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _709_t0 = 187;
    goto BB4;
BB5:
    _709_t0 = 4;
    goto BB4;
BB4:
    _709_$retval = _709_t0;
    return _709_$retval;
}

uint8_t _714_f(int64_t _714_x) {
    uint8_t _714_$retval;
    (void)_714_x;
    _714_$retval = 1;
    return _714_$retval;
}

int main(void) {
  printf("%ld",_709_main());
  return 0;
}
