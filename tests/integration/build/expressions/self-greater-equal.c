/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef uint8_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _606_main(void);
uint8_t _611_f(int64_t _611_x);

/* Function definitions */
int64_t _606_main(void) {
    function0 _606_t1;
    int64_t _606_t3;
    uint8_t _606_t2;
    int64_t _606_t0;
    int64_t _606_$retval;
    _606_t1 = _611_f;
    _606_t3 = 4;
    $lines[$line_idx++] = "tests/integration/expressions/self-greater-equal.orng:3:10:\n    if f(4) {\n        ^";
    _606_t2 = _606_t1(_606_t3);
    $line_idx--;
    if (_606_t2) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _606_t0 = 227;
    goto BB4;
BB5:
    _606_t0 = 0;
    goto BB4;
BB4:
    _606_$retval = _606_t0;
    return _606_$retval;
}

uint8_t _611_f(int64_t _611_x) {
    uint8_t _611_$retval;
    (void)_611_x;
    _611_$retval = 1;
    return _611_$retval;
}

int main(void) {
  printf("%ld",_606_main());
  return 0;
}
