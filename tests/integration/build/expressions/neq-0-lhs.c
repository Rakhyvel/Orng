/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef int64_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _700_main(void);
int64_t _702_f(int64_t _702_x);

/* Function definitions */
int64_t _700_main(void) {
    function0 _700_t0;
    int64_t _700_t2;
    int64_t _700_t1;
    int64_t _700_$retval;
    _700_t0 = _702_f;
    _700_t2 = 1;
    $lines[$line_idx++] = "tests/integration/expressions/neq-0-lhs.orng:3:7:\n    f(1)\n     ^";
    _700_t1 = _700_t0(_700_t2);
    $line_idx--;
    _700_$retval = _700_t1;
    return _700_$retval;
}

int64_t _702_f(int64_t _702_x) {
    int64_t _702_t1;
    uint8_t _702_t2;
    int64_t _702_t0;
    int64_t _702_$retval;
    _702_t1 = 0;
    _702_t2 = _702_t1 != _702_x;
    if (_702_t2) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _702_t0 = 174;
    goto BB4;
BB5:
    _702_t0 = 3;
    goto BB4;
BB4:
    _702_$retval = _702_t0;
    return _702_$retval;
}

int main(void) {
  printf("%ld",_700_main());
  return 0;
}
