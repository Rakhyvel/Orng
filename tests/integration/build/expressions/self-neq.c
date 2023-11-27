/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef uint8_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _578_main(void);
uint8_t _583_f(int64_t _583_x);

/* Function definitions */
int64_t _578_main(void) {
    function0 _578_t1;
    int64_t _578_t3;
    uint8_t _578_t2;
    int64_t _578_t0;
    int64_t _578_$retval;
    _578_t1 = _583_f;
    _578_t3 = 4;
    $lines[$line_idx++] = "tests/integration/expressions/self-neq.orng:3:10:\n    if f(4) {\n        ^";
    _578_t2 = _578_t1(_578_t3);
    $line_idx--;
    if (_578_t2) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _578_t0 = 0;
    goto BB4;
BB5:
    _578_t0 = 223;
    goto BB4;
BB4:
    _578_$retval = _578_t0;
    return _578_$retval;
}

uint8_t _583_f(int64_t _583_x) {
    uint8_t _583_$retval;
    (void)_583_x;
    _583_$retval = 0;
    return _583_$retval;
}

int main(void) {
  printf("%ld",_578_main());
  return 0;
}
