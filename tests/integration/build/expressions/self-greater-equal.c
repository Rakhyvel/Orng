/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef uint8_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _210_main(void);
uint8_t _215_f(int64_t _215_x);

/* Function definitions */
int64_t _210_main(void) {
    function0 _210_t1;
    int64_t _210_t3;
    uint8_t _210_t2;
    int64_t _210_t0;
    int64_t _210_$retval;
    _210_t1 = _215_f;
    _210_t3 = 4;
    $lines[$line_idx++] = "tests/integration/expressions/self-greater-equal.orng:3:10:\n    if f(4) {\n        ^";
    _210_t2 = _210_t1(_210_t3);
    $line_idx--;
    if (_210_t2) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _210_t0 = 227;
    goto BB4;
BB5:
    _210_t0 = 0;
    goto BB4;
BB4:
    _210_$retval = _210_t0;
    return _210_$retval;
}

uint8_t _215_f(int64_t _215_x) {
    uint8_t _215_$retval;
    (void)_215_x;
    _215_$retval = 1;
    return _215_$retval;
}

int main(void) {
  printf("%ld",_210_main());
  return 0;
}
