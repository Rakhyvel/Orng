/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef uint8_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _563_main(void);
uint8_t _568_f(int64_t _568_x);

/* Function definitions */
int64_t _563_main(void) {
    function0 _563_t1;
    int64_t _563_t3;
    uint8_t _563_t2;
    int64_t _563_t0;
    int64_t _563_$retval;
    _563_t1 = _568_f;
    _563_t3 = 4;
    $lines[$line_idx++] = "tests/integration/expressions/add-zero.orng:3:10:\n    if f(4) {\n        ^";
    _563_t2 = _563_t1(_563_t3);
    $line_idx--;
    if (_563_t2) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _563_t0 = 182;
    goto BB4;
BB5:
    _563_t0 = 4;
    goto BB4;
BB4:
    _563_$retval = _563_t0;
    return _563_$retval;
}

uint8_t _568_f(int64_t _568_x) {
    uint8_t _568_$retval;
    (void)_568_x;
    _568_$retval = 1;
    return _568_$retval;
}

int main(void) {
  printf("%ld",_563_main());
  return 0;
}
