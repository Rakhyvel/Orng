/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef uint8_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _655_main(void);
uint8_t _660_f(int64_t _660_x);

/* Function definitions */
int64_t _655_main(void) {
    function0 _655_t1;
    int64_t _655_t3;
    uint8_t _655_t2;
    int64_t _655_t0;
    int64_t _655_$retval;
    _655_t1 = _660_f;
    _655_t3 = 4;
    $lines[$line_idx++] = "tests/integration/expressions/mod-1.orng:3:10:\n    if f(4) {\n        ^";
    _655_t2 = _655_t1(_655_t3);
    $line_idx--;
    if (_655_t2) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _655_t0 = 192;
    goto BB4;
BB5:
    _655_t0 = 4;
    goto BB4;
BB4:
    _655_$retval = _655_t0;
    return _655_$retval;
}

uint8_t _660_f(int64_t _660_x) {
    uint8_t _660_$retval;
    (void)_660_x;
    _660_$retval = 1;
    return _660_$retval;
}

int main(void) {
  printf("%ld",_655_main());
  return 0;
}
