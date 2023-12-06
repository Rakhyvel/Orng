/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef int64_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _173_main(void);
int64_t _175_f(int64_t _175_x);

/* Function definitions */
int64_t _173_main(void) {
    function0 _173_t0;
    int64_t _173_t2;
    int64_t _173_t1;
    int64_t _173_$retval;
    _173_t0 = _175_f;
    _173_t2 = 1;
    $lines[$line_idx++] = "tests/integration/expressions/neq-0-lhs.orng:3:7:\n    f(1)\n     ^";
    _173_t1 = _173_t0(_173_t2);
    $line_idx--;
    _173_$retval = _173_t1;
    return _173_$retval;
}

int64_t _175_f(int64_t _175_x) {
    int64_t _175_t1;
    uint8_t _175_t2;
    int64_t _175_t0;
    int64_t _175_$retval;
    _175_t1 = 0;
    _175_t2 = _175_t1 != _175_x;
    if (_175_t2) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _175_t0 = 174;
    goto BB4;
BB5:
    _175_t0 = 3;
    goto BB4;
BB4:
    _175_$retval = _175_t0;
    return _175_$retval;
}

int main(void) {
  printf("%ld",_173_main());
  return 0;
}
