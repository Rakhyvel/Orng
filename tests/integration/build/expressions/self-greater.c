/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef uint8_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _595_main(void);
uint8_t _600_f(int64_t _600_x);

/* Function definitions */
int64_t _595_main(void) {
    function0 _595_t1;
    int64_t _595_t3;
    uint8_t _595_t2;
    int64_t _595_t0;
    int64_t _595_$retval;
    _595_t1 = _600_f;
    _595_t3 = 4;
    $lines[$line_idx++] = "tests/integration/expressions/self-greater.orng:3:10:\n    if f(4) {\n        ^";
    _595_t2 = _595_t1(_595_t3);
    $line_idx--;
    if (_595_t2) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _595_t0 = 0;
    goto BB4;
BB5:
    _595_t0 = 224;
    goto BB4;
BB4:
    _595_$retval = _595_t0;
    return _595_$retval;
}

uint8_t _600_f(int64_t _600_x) {
    uint8_t _600_$retval;
    (void)_600_x;
    _600_$retval = 0;
    return _600_$retval;
}

int main(void) {
  printf("%ld",_595_main());
  return 0;
}
