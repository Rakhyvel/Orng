/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef int64_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _558_main(void);
int64_t _560_f(int64_t _560_x);

/* Function definitions */
int64_t _558_main(void) {
    function0 _558_t0;
    int64_t _558_t2;
    int64_t _558_t1;
    int64_t _558_$retval;
    _558_t0 = _560_f;
    _558_t2 = 1;
    $lines[$line_idx++] = "tests/integration/expressions/neq-0-rhs.orng:3:7:\n    f(1)\n     ^";
    _558_t1 = _558_t0(_558_t2);
    $line_idx--;
    _558_$retval = _558_t1;
    return _558_$retval;
}

int64_t _560_f(int64_t _560_x) {
    int64_t _560_t1;
    uint8_t _560_t2;
    int64_t _560_t0;
    int64_t _560_$retval;
    _560_t1 = 0;
    _560_t2 = _560_x != _560_t1;
    if (_560_t2) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _560_t0 = 173;
    goto BB4;
BB5:
    _560_t0 = 3;
    goto BB4;
BB4:
    _560_$retval = _560_t0;
    return _560_$retval;
}

int main(void) {
  printf("%ld",_558_main());
  return 0;
}
