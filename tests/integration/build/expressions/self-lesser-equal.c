/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef uint8_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _226_main(void);
uint8_t _231_f(int64_t _231_x);

/* Function definitions */
int64_t _226_main(void) {
    function0 _226_t1;
    int64_t _226_t3;
    uint8_t _226_t2;
    int64_t _226_t0;
    int64_t _226_$retval;
    _226_t1 = _231_f;
    _226_t3 = 4;
    $lines[$line_idx++] = "tests/integration/expressions/self-lesser-equal.orng:3:10:\n    if f(4) {\n        ^";
    _226_t2 = _226_t1(_226_t3);
    $line_idx--;
    if (_226_t2) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _226_t0 = 228;
    goto BB4;
BB5:
    _226_t0 = 0;
    goto BB4;
BB4:
    _226_$retval = _226_t0;
    return _226_$retval;
}

uint8_t _231_f(int64_t _231_x) {
    uint8_t _231_$retval;
    (void)_231_x;
    _231_$retval = 1;
    return _231_$retval;
}

int main(void) {
  printf("%ld",_226_main());
  return 0;
}
