/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef uint8_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _218_main(void);
uint8_t _223_f(int64_t _223_x);

/* Function definitions */
int64_t _218_main(void) {
    function0 _218_t1;
    int64_t _218_t3;
    uint8_t _218_t2;
    int64_t _218_t0;
    int64_t _218_$retval;
    _218_t1 = _223_f;
    _218_t3 = 4;
    $lines[$line_idx++] = "tests/integration/expressions/self-greater.orng:3:10:\n    if f(4) {\n        ^";
    _218_t2 = _218_t1(_218_t3);
    $line_idx--;
    if (_218_t2) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _218_t0 = 0;
    goto BB4;
BB5:
    _218_t0 = 224;
    goto BB4;
BB4:
    _218_$retval = _218_t0;
    return _218_$retval;
}

uint8_t _223_f(int64_t _223_x) {
    uint8_t _223_$retval;
    (void)_223_x;
    _223_$retval = 0;
    return _223_$retval;
}

int main(void) {
  printf("%ld",_218_main());
  return 0;
}
