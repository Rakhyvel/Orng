/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef uint8_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _749_main(void);
uint8_t _754_f(int64_t _754_x);

/* Function definitions */
int64_t _749_main(void) {
    function0 _749_t1;
    int64_t _749_t3;
    uint8_t _749_t2;
    int64_t _749_t0;
    int64_t _749_$retval;
    _749_t1 = _754_f;
    _749_t3 = 4;
    $lines[$line_idx++] = "tests/integration/expressions/self-greater.orng:3:10:\n    if f(4) {\n        ^";
    _749_t2 = _749_t1(_749_t3);
    $line_idx--;
    if (_749_t2) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _749_t0 = 0;
    goto BB4;
BB5:
    _749_t0 = 224;
    goto BB4;
BB4:
    _749_$retval = _749_t0;
    return _749_$retval;
}

uint8_t _754_f(int64_t _754_x) {
    uint8_t _754_$retval;
    (void)_754_x;
    _754_$retval = 0;
    return _754_$retval;
}

int main(void) {
  printf("%ld",_749_main());
  return 0;
}
