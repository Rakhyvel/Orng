/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef int64_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _181_main(void);
int64_t _183_f(int64_t _183_x);

/* Function definitions */
int64_t _181_main(void) {
    function0 _181_t0;
    int64_t _181_t2;
    int64_t _181_t1;
    int64_t _181_$retval;
    _181_t0 = _183_f;
    _181_t2 = 1;
    $lines[$line_idx++] = "tests/integration/expressions/neq-0-rhs.orng:3:7:\n    f(1)\n     ^";
    _181_t1 = _181_t0(_181_t2);
    $line_idx--;
    _181_$retval = _181_t1;
    return _181_$retval;
}

int64_t _183_f(int64_t _183_x) {
    int64_t _183_t1;
    uint8_t _183_t2;
    int64_t _183_t0;
    int64_t _183_$retval;
    _183_t1 = 0;
    _183_t2 = _183_x != _183_t1;
    if (_183_t2) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _183_t0 = 173;
    goto BB4;
BB5:
    _183_t0 = 3;
    goto BB4;
BB4:
    _183_$retval = _183_t0;
    return _183_$retval;
}

int main(void) {
  printf("%ld",_181_main());
  return 0;
}
