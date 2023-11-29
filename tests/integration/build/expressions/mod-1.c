/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef uint8_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _540_main(void);
uint8_t _545_f(int64_t _545_x);

/* Function definitions */
int64_t _540_main(void) {
    function0 _540_t1;
    int64_t _540_t3;
    uint8_t _540_t2;
    int64_t _540_t0;
    int64_t _540_$retval;
    _540_t1 = _545_f;
    _540_t3 = 4;
    $lines[$line_idx++] = "tests/integration/expressions/mod-1.orng:3:10:\n    if f(4) {\n        ^";
    _540_t2 = _540_t1(_540_t3);
    $line_idx--;
    if (_540_t2) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _540_t0 = 192;
    goto BB4;
BB5:
    _540_t0 = 4;
    goto BB4;
BB4:
    _540_$retval = _540_t0;
    return _540_$retval;
}

uint8_t _545_f(int64_t _545_x) {
    uint8_t _545_$retval;
    (void)_545_x;
    _545_$retval = 1;
    return _545_$retval;
}

int main(void) {
  printf("%ld",_540_main());
  return 0;
}
