/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef int64_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _589_main(void);
int64_t _591_f(int64_t _591_x);

/* Function definitions */
int64_t _589_main(void) {
    function0 _589_t0;
    int64_t _589_t2;
    int64_t _589_t1;
    int64_t _589_$retval;
    _589_t0 = _591_f;
    _589_t2 = 1;
    $lines[$line_idx++] = "tests/integration/expressions/neq-0-rhs.orng:3:7:\n    f(1)\n     ^";
    _589_t1 = _589_t0(_589_t2);
    $line_idx--;
    _589_$retval = _589_t1;
    return _589_$retval;
}

int64_t _591_f(int64_t _591_x) {
    int64_t _591_t1;
    uint8_t _591_t2;
    int64_t _591_t0;
    int64_t _591_$retval;
    _591_t1 = 0;
    _591_t2 = _591_x != _591_t1;
    if (_591_t2) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _591_t0 = 173;
    goto BB4;
BB5:
    _591_t0 = 3;
    goto BB4;
BB4:
    _591_$retval = _591_t0;
    return _591_$retval;
}

int main(void) {
  printf("%ld",_589_main());
  return 0;
}
