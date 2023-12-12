/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef uint8_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _536_main(void);
uint8_t _541_f(int64_t _541_x);

/* Function definitions */
int64_t _536_main(void) {
    function0 _536_t1;
    int64_t _536_t3;
    uint8_t _536_t2;
    int64_t _536_t0;
    int64_t _536_$retval;
    _536_t1 = _541_f;
    _536_t3 = 4;
    $lines[$line_idx++] = "tests/integration/expressions/mult-1.orng:3:10:\n    if f(4) {\n        ^";
    _536_t2 = _536_t1(_536_t3);
    $line_idx--;
    if (_536_t2) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _536_t0 = 186;
    goto BB4;
BB5:
    _536_t0 = 4;
    goto BB4;
BB4:
    _536_$retval = _536_t0;
    return _536_$retval;
}

uint8_t _541_f(int64_t _541_x) {
    uint8_t _541_$retval;
    (void)_541_x;
    _541_$retval = 1;
    return _541_$retval;
}

int main(void) {
  printf("%ld",_536_main());
  return 0;
}
