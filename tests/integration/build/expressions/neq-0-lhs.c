/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef int64_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _721_main(void);
int64_t _723_f(int64_t _723_x);

/* Function definitions */
int64_t _721_main(void) {
    function0 _721_t0;
    int64_t _721_t2;
    int64_t _721_t1;
    int64_t _721_$retval;
    _721_t0 = _723_f;
    _721_t2 = 1;
    $lines[$line_idx++] = "tests/integration/expressions/neq-0-lhs.orng:3:7:\n    f(1)\n     ^";
    _721_t1 = _721_t0(_721_t2);
    $line_idx--;
    _721_$retval = _721_t1;
    return _721_$retval;
}

int64_t _723_f(int64_t _723_x) {
    int64_t _723_t1;
    uint8_t _723_t2;
    int64_t _723_t0;
    int64_t _723_$retval;
    _723_t1 = 0;
    _723_t2 = _723_t1 != _723_x;
    if (_723_t2) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _723_t0 = 174;
    goto BB4;
BB5:
    _723_t0 = 3;
    goto BB4;
BB4:
    _723_$retval = _723_t0;
    return _723_$retval;
}

int main(void) {
  printf("%ld",_721_main());
  return 0;
}
