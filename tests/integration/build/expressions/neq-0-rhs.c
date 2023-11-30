/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef int64_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _732_main(void);
int64_t _734_f(int64_t _734_x);

/* Function definitions */
int64_t _732_main(void) {
    function0 _732_t0;
    int64_t _732_t2;
    int64_t _732_t1;
    int64_t _732_$retval;
    _732_t0 = _734_f;
    _732_t2 = 1;
    $lines[$line_idx++] = "tests/integration/expressions/neq-0-rhs.orng:3:7:\n    f(1)\n     ^";
    _732_t1 = _732_t0(_732_t2);
    $line_idx--;
    _732_$retval = _732_t1;
    return _732_$retval;
}

int64_t _734_f(int64_t _734_x) {
    int64_t _734_t1;
    uint8_t _734_t2;
    int64_t _734_t0;
    int64_t _734_$retval;
    _734_t1 = 0;
    _734_t2 = _734_x != _734_t1;
    if (_734_t2) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _734_t0 = 173;
    goto BB4;
BB5:
    _734_t0 = 3;
    goto BB4;
BB4:
    _734_$retval = _734_t0;
    return _734_$retval;
}

int main(void) {
  printf("%ld",_732_main());
  return 0;
}
