/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef uint8_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _535_main(void);
uint8_t _540_f(int64_t _540_x);

/* Function definitions */
int64_t _535_main(void) {
    function0 _535_t1;
    int64_t _535_t3;
    uint8_t _535_t2;
    int64_t _535_t0;
    int64_t _535_$retval;
    _535_t1 = _540_f;
    _535_t3 = 4;
    $lines[$line_idx++] = "tests/integration/expressions/add-zero.orng:3:10:\n    if f(4) {\n        ^";
    _535_t2 = _535_t1(_535_t3);
    $line_idx--;
    if (_535_t2) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _535_t0 = 182;
    goto BB4;
BB5:
    _535_t0 = 4;
    goto BB4;
BB4:
    _535_$retval = _535_t0;
    return _535_$retval;
}

uint8_t _540_f(int64_t _540_x) {
    uint8_t _540_$retval;
    (void)_540_x;
    _540_$retval = 1;
    return _540_$retval;
}

int main(void) {
  printf("%ld",_535_main());
  return 0;
}
