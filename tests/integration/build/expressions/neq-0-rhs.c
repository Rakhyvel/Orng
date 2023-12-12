/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef int64_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _577_main(void);
int64_t _579_f(int64_t _579_x);

/* Function definitions */
int64_t _577_main(void) {
    function0 _577_t0;
    int64_t _577_t2;
    int64_t _577_t1;
    int64_t _577_$retval;
    _577_t0 = _579_f;
    _577_t2 = 1;
    $lines[$line_idx++] = "tests/integration/expressions/neq-0-rhs.orng:3:7:\n    f(1)\n     ^";
    _577_t1 = _577_t0(_577_t2);
    $line_idx--;
    _577_$retval = _577_t1;
    return _577_$retval;
}

int64_t _579_f(int64_t _579_x) {
    int64_t _579_t1;
    uint8_t _579_t2;
    int64_t _579_t0;
    int64_t _579_$retval;
    _579_t1 = 0;
    _579_t2 = _579_x != _579_t1;
    if (_579_t2) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _579_t0 = 173;
    goto BB4;
BB5:
    _579_t0 = 3;
    goto BB4;
BB4:
    _579_$retval = _579_t0;
    return _579_$retval;
}

int main(void) {
  printf("%ld",_577_main());
  return 0;
}
