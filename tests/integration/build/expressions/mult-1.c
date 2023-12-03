/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef uint8_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _509_main(void);
uint8_t _514_f(int64_t _514_x);

/* Function definitions */
int64_t _509_main(void) {
    function0 _509_t1;
    int64_t _509_t3;
    uint8_t _509_t2;
    int64_t _509_t0;
    int64_t _509_$retval;
    _509_t1 = _514_f;
    _509_t3 = 4;
    $lines[$line_idx++] = "tests/integration/expressions/mult-1.orng:3:10:\n    if f(4) {\n        ^";
    _509_t2 = _509_t1(_509_t3);
    $line_idx--;
    if (_509_t2) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _509_t0 = 186;
    goto BB4;
BB5:
    _509_t0 = 4;
    goto BB4;
BB4:
    _509_$retval = _509_t0;
    return _509_$retval;
}

uint8_t _514_f(int64_t _514_x) {
    uint8_t _514_$retval;
    (void)_514_x;
    _514_$retval = 1;
    return _514_$retval;
}

int main(void) {
  printf("%ld",_509_main());
  return 0;
}
