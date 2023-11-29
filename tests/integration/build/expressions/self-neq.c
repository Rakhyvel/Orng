/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef uint8_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _650_main(void);
uint8_t _655_f(int64_t _655_x);

/* Function definitions */
int64_t _650_main(void) {
    function0 _650_t1;
    int64_t _650_t3;
    uint8_t _650_t2;
    int64_t _650_t0;
    int64_t _650_$retval;
    _650_t1 = _655_f;
    _650_t3 = 4;
    $lines[$line_idx++] = "tests/integration/expressions/self-neq.orng:3:10:\n    if f(4) {\n        ^";
    _650_t2 = _650_t1(_650_t3);
    $line_idx--;
    if (_650_t2) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _650_t0 = 0;
    goto BB4;
BB5:
    _650_t0 = 223;
    goto BB4;
BB4:
    _650_$retval = _650_t0;
    return _650_$retval;
}

uint8_t _655_f(int64_t _655_x) {
    uint8_t _655_$retval;
    (void)_655_x;
    _655_$retval = 0;
    return _655_$retval;
}

int main(void) {
  printf("%ld",_650_main());
  return 0;
}
