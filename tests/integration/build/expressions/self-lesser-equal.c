/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef uint8_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _779_main(void);
uint8_t _784_f(int64_t _784_x);

/* Function definitions */
int64_t _779_main(void) {
    function0 _779_t1;
    int64_t _779_t3;
    uint8_t _779_t2;
    int64_t _779_t0;
    int64_t _779_$retval;
    _779_t1 = _784_f;
    _779_t3 = 4;
    $lines[$line_idx++] = "tests/integration/expressions/self-lesser-equal.orng:3:10:\n    if f(4) {\n        ^";
    _779_t2 = _779_t1(_779_t3);
    $line_idx--;
    if (_779_t2) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _779_t0 = 228;
    goto BB4;
BB5:
    _779_t0 = 0;
    goto BB4;
BB4:
    _779_$retval = _779_t0;
    return _779_$retval;
}

uint8_t _784_f(int64_t _784_x) {
    uint8_t _784_$retval;
    (void)_784_x;
    _784_$retval = 1;
    return _784_$retval;
}

int main(void) {
  printf("%ld",_779_main());
  return 0;
}
