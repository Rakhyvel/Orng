/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef uint8_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _774_main(void);
uint8_t _779_f(int64_t _779_x);

/* Function definitions */
int64_t _774_main(void) {
    function0 _774_t1;
    int64_t _774_t3;
    uint8_t _774_t2;
    int64_t _774_t0;
    int64_t _774_$retval;
    _774_t1 = _779_f;
    _774_t3 = 4;
    $lines[$line_idx++] = "tests/integration/expressions/self-greater-equal.orng:3:10:\n    if f(4) {\n        ^";
    _774_t2 = _774_t1(_774_t3);
    $line_idx--;
    if (_774_t2) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _774_t0 = 227;
    goto BB4;
BB5:
    _774_t0 = 0;
    goto BB4;
BB4:
    _774_$retval = _774_t0;
    return _774_$retval;
}

uint8_t _779_f(int64_t _779_x) {
    uint8_t _779_$retval;
    (void)_779_x;
    _779_$retval = 1;
    return _779_$retval;
}

int main(void) {
  printf("%ld",_774_main());
  return 0;
}
