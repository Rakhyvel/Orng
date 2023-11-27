/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef int64_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _517_main(void);
int64_t _519_f(int64_t _519_x);

/* Function definitions */
int64_t _517_main(void) {
    function0 _517_t0;
    int64_t _517_t2;
    int64_t _517_t1;
    int64_t _517_$retval;
    _517_t0 = _519_f;
    _517_t2 = 1;
    $lines[$line_idx++] = "tests/integration/expressions/neq-0-rhs.orng:3:7:\n    f(1)\n     ^";
    _517_t1 = _517_t0(_517_t2);
    $line_idx--;
    _517_$retval = _517_t1;
    return _517_$retval;
}

int64_t _519_f(int64_t _519_x) {
    int64_t _519_t1;
    uint8_t _519_t2;
    int64_t _519_t0;
    int64_t _519_$retval;
    _519_t1 = 0;
    _519_t2 = _519_x != _519_t1;
    if (_519_t2) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _519_t0 = 173;
    goto BB4;
BB5:
    _519_t0 = 3;
    goto BB4;
BB4:
    _519_$retval = _519_t0;
    return _519_$retval;
}

int main(void) {
  printf("%ld",_517_main());
  return 0;
}
