/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef uint8_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _685_main(void);
uint8_t _690_f(int64_t _690_x);

/* Function definitions */
int64_t _685_main(void) {
    function0 _685_t1;
    int64_t _685_t3;
    uint8_t _685_t2;
    int64_t _685_t0;
    int64_t _685_$retval;
    _685_t1 = _690_f;
    _685_t3 = 4;
    $lines[$line_idx++] = "tests/integration/expressions/mult-1.orng:3:10:\n    if f(4) {\n        ^";
    _685_t2 = _685_t1(_685_t3);
    $line_idx--;
    if (_685_t2) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _685_t0 = 186;
    goto BB4;
BB5:
    _685_t0 = 4;
    goto BB4;
BB4:
    _685_$retval = _685_t0;
    return _685_$retval;
}

uint8_t _690_f(int64_t _690_x) {
    uint8_t _690_$retval;
    (void)_690_x;
    _690_$retval = 1;
    return _690_$retval;
}

int main(void) {
  printf("%ld",_685_main());
  return 0;
}
