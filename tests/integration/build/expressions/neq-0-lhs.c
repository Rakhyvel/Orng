/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef int64_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _737_main(void);
int64_t _739_f(int64_t _739_x);

/* Function definitions */
int64_t _737_main(void) {
    function0 _737_t0;
    int64_t _737_t2;
    int64_t _737_t1;
    int64_t _737_$retval;
    _737_t0 = _739_f;
    _737_t2 = 1;
    $lines[$line_idx++] = "tests/integration/expressions/neq-0-lhs.orng:3:7:\n    f(1)\n     ^";
    _737_t1 = _737_t0(_737_t2);
    $line_idx--;
    _737_$retval = _737_t1;
    return _737_$retval;
}

int64_t _739_f(int64_t _739_x) {
    int64_t _739_t1;
    uint8_t _739_t2;
    int64_t _739_t0;
    int64_t _739_$retval;
    _739_t1 = 0;
    _739_t2 = _739_t1 != _739_x;
    if (_739_t2) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _739_t0 = 174;
    goto BB4;
BB5:
    _739_t0 = 3;
    goto BB4;
BB4:
    _739_$retval = _739_t0;
    return _739_$retval;
}

int main(void) {
  printf("%ld",_737_main());
  return 0;
}
