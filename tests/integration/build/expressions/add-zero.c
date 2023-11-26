/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef uint8_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _313_main(void);
uint8_t _318_f(int64_t _318_x);

/* Function definitions */
int64_t _313_main(void) {
    function0 _313_t1;
    int64_t _313_t3;
    uint8_t _313_t2;
    int64_t _313_t0;
    int64_t _313_$retval;
    _313_t1 = _318_f;
    _313_t3 = 4;
    $lines[$line_idx++] = "tests/integration/expressions/add-zero.orng:3:10:\n    if f(4) {\n        ^";
    _313_t2 = _313_t1(_313_t3);
    $line_idx--;
    if (_313_t2) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _313_t0 = 182;
    goto BB4;
BB5:
    _313_t0 = 4;
    goto BB4;
BB4:
    _313_$retval = _313_t0;
    return _313_$retval;
}

uint8_t _318_f(int64_t _318_x) {
    uint8_t _318_t5;
    uint8_t _318_t4;
    uint8_t _318_$retval;
    (void)_318_x;
    _318_t5 = 1;
    if (_318_t5) {
        goto BB1;
    } else {
        goto BB4;
    }
BB1:
    _318_t4 = 1;
    goto BB3;
BB4:
    _318_t4 = 0;
    goto BB3;
BB3:
    _318_$retval = _318_t4;
    return _318_$retval;
}

int main(void) {
  printf("%ld",_313_main());
  return 0;
}
