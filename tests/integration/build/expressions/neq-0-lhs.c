/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef int64_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _723_main(void);
int64_t _725_f(int64_t _725_x);

/* Function definitions */
int64_t _723_main(void) {
    function0 _723_t0;
    int64_t _723_t2;
    int64_t _723_t1;
    int64_t _723_$retval;
    _723_t0 = _725_f;
    _723_t2 = 1;
    $lines[$line_idx++] = "tests/integration/expressions/neq-0-lhs.orng:3:7:\n    f(1)\n     ^";
    _723_t1 = _723_t0(_723_t2);
    $line_idx--;
    _723_$retval = _723_t1;
    return _723_$retval;
}

int64_t _725_f(int64_t _725_x) {
    int64_t _725_t1;
    uint8_t _725_t2;
    int64_t _725_t0;
    int64_t _725_$retval;
    _725_t1 = 0;
    _725_t2 = _725_t1 != _725_x;
    if (_725_t2) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _725_t0 = 174;
    goto BB4;
BB5:
    _725_t0 = 3;
    goto BB4;
BB4:
    _725_$retval = _725_t0;
    return _725_$retval;
}

int main(void) {
  printf("%ld",_723_main());
  return 0;
}
