/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef int64_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _486_main(void);
int64_t _488_f(int64_t _488_x);

/* Function definitions */
int64_t _486_main(void) {
    function0 _486_t0;
    int64_t _486_t2;
    int64_t _486_t1;
    int64_t _486_$retval;
    _486_t0 = _488_f;
    _486_t2 = 1;
    $lines[$line_idx++] = "tests/integration/expressions/neq-0-rhs.orng:3:7:\n    f(1)\n     ^";
    _486_t1 = _486_t0(_486_t2);
    $line_idx--;
    _486_$retval = _486_t1;
    return _486_$retval;
}

int64_t _488_f(int64_t _488_x) {
    int64_t _488_t1;
    uint8_t _488_t2;
    int64_t _488_t0;
    int64_t _488_$retval;
    _488_t1 = 0;
    _488_t2 = _488_x != _488_t1;
    if (_488_t2) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _488_t0 = 173;
    goto BB4;
BB5:
    _488_t0 = 3;
    goto BB4;
BB4:
    _488_$retval = _488_t0;
    return _488_$retval;
}

int main(void) {
  printf("%ld",_486_main());
  return 0;
}
