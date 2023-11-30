/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef uint8_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _781_main(void);
uint8_t _786_f(int64_t _786_x);

/* Function definitions */
int64_t _781_main(void) {
    function0 _781_t1;
    int64_t _781_t3;
    uint8_t _781_t2;
    int64_t _781_t0;
    int64_t _781_$retval;
    _781_t1 = _786_f;
    _781_t3 = 4;
    $lines[$line_idx++] = "tests/integration/expressions/self-lesser-equal.orng:3:10:\n    if f(4) {\n        ^";
    _781_t2 = _781_t1(_781_t3);
    $line_idx--;
    if (_781_t2) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _781_t0 = 228;
    goto BB4;
BB5:
    _781_t0 = 0;
    goto BB4;
BB4:
    _781_$retval = _781_t0;
    return _781_$retval;
}

uint8_t _786_f(int64_t _786_x) {
    uint8_t _786_$retval;
    (void)_786_x;
    _786_$retval = 1;
    return _786_$retval;
}

int main(void) {
  printf("%ld",_781_main());
  return 0;
}
