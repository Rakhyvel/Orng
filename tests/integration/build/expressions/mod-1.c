/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef uint8_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _676_main(void);
uint8_t _681_f(int64_t _681_x);

/* Function definitions */
int64_t _676_main(void) {
    function0 _676_t1;
    int64_t _676_t3;
    uint8_t _676_t2;
    int64_t _676_t0;
    int64_t _676_$retval;
    _676_t1 = _681_f;
    _676_t3 = 4;
    $lines[$line_idx++] = "tests/integration/expressions/mod-1.orng:3:10:\n    if f(4) {\n        ^";
    _676_t2 = _676_t1(_676_t3);
    $line_idx--;
    if (_676_t2) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _676_t0 = 192;
    goto BB4;
BB5:
    _676_t0 = 4;
    goto BB4;
BB4:
    _676_$retval = _676_t0;
    return _676_$retval;
}

uint8_t _681_f(int64_t _681_x) {
    uint8_t _681_$retval;
    (void)_681_x;
    _681_$retval = 1;
    return _681_$retval;
}

int main(void) {
  printf("%ld",_676_main());
  return 0;
}
