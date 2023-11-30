/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef uint8_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _772_main(void);
uint8_t _777_f(int64_t _777_x);

/* Function definitions */
int64_t _772_main(void) {
    function0 _772_t1;
    int64_t _772_t3;
    uint8_t _772_t2;
    int64_t _772_t0;
    int64_t _772_$retval;
    _772_t1 = _777_f;
    _772_t3 = 4;
    $lines[$line_idx++] = "tests/integration/expressions/self-greater.orng:3:10:\n    if f(4) {\n        ^";
    _772_t2 = _772_t1(_772_t3);
    $line_idx--;
    if (_772_t2) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _772_t0 = 0;
    goto BB4;
BB5:
    _772_t0 = 224;
    goto BB4;
BB4:
    _772_$retval = _772_t0;
    return _772_$retval;
}

uint8_t _777_f(int64_t _777_x) {
    uint8_t _777_$retval;
    (void)_777_x;
    _777_$retval = 0;
    return _777_$retval;
}

int main(void) {
  printf("%ld",_772_main());
  return 0;
}
