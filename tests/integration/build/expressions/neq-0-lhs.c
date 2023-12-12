/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef int64_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _569_main(void);
int64_t _571_f(int64_t _571_x);

/* Function definitions */
int64_t _569_main(void) {
    function0 _569_t0;
    int64_t _569_t2;
    int64_t _569_t1;
    int64_t _569_$retval;
    _569_t0 = _571_f;
    _569_t2 = 1;
    $lines[$line_idx++] = "tests/integration/expressions/neq-0-lhs.orng:3:7:\n    f(1)\n     ^";
    _569_t1 = _569_t0(_569_t2);
    $line_idx--;
    _569_$retval = _569_t1;
    return _569_$retval;
}

int64_t _571_f(int64_t _571_x) {
    int64_t _571_t1;
    uint8_t _571_t2;
    int64_t _571_t0;
    int64_t _571_$retval;
    _571_t1 = 0;
    _571_t2 = _571_t1 != _571_x;
    if (_571_t2) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _571_t0 = 174;
    goto BB4;
BB5:
    _571_t0 = 3;
    goto BB4;
BB4:
    _571_$retval = _571_t0;
    return _571_$retval;
}

int main(void) {
  printf("%ld",_569_main());
  return 0;
}
