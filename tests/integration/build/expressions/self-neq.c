/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef uint8_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _776_main(void);
uint8_t _781_f(int64_t _781_x);

/* Function definitions */
int64_t _776_main(void) {
    function0 _776_t1;
    int64_t _776_t3;
    uint8_t _776_t2;
    int64_t _776_t0;
    int64_t _776_$retval;
    _776_t1 = _781_f;
    _776_t3 = 4;
    $lines[$line_idx++] = "tests/integration/expressions/self-neq.orng:3:10:\n    if f(4) {\n        ^";
    _776_t2 = _776_t1(_776_t3);
    $line_idx--;
    if (_776_t2) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _776_t0 = 0;
    goto BB4;
BB5:
    _776_t0 = 223;
    goto BB4;
BB4:
    _776_$retval = _776_t0;
    return _776_$retval;
}

uint8_t _781_f(int64_t _781_x) {
    uint8_t _781_$retval;
    (void)_781_x;
    _781_$retval = 0;
    return _781_$retval;
}

int main(void) {
  printf("%ld",_776_main());
  return 0;
}
