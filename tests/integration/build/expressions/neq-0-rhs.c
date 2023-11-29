/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef int64_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _730_main(void);
int64_t _732_f(int64_t _732_x);

/* Function definitions */
int64_t _730_main(void) {
    function0 _730_t0;
    int64_t _730_t2;
    int64_t _730_t1;
    int64_t _730_$retval;
    _730_t0 = _732_f;
    _730_t2 = 1;
    $lines[$line_idx++] = "tests/integration/expressions/neq-0-rhs.orng:3:7:\n    f(1)\n     ^";
    _730_t1 = _730_t0(_730_t2);
    $line_idx--;
    _730_$retval = _730_t1;
    return _730_$retval;
}

int64_t _732_f(int64_t _732_x) {
    int64_t _732_t1;
    uint8_t _732_t2;
    int64_t _732_t0;
    int64_t _732_$retval;
    _732_t1 = 0;
    _732_t2 = _732_x != _732_t1;
    if (_732_t2) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _732_t0 = 173;
    goto BB4;
BB5:
    _732_t0 = 3;
    goto BB4;
BB4:
    _732_$retval = _732_t0;
    return _732_$retval;
}

int main(void) {
  printf("%ld",_730_main());
  return 0;
}
