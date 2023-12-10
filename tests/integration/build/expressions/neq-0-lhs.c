/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef int64_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _542_main(void);
int64_t _544_f(int64_t _544_x);

/* Function definitions */
int64_t _542_main(void) {
    function0 _542_t0;
    int64_t _542_t2;
    int64_t _542_t1;
    int64_t _542_$retval;
    _542_t0 = _544_f;
    _542_t2 = 1;
    $lines[$line_idx++] = "tests/integration/expressions/neq-0-lhs.orng:3:7:\n    f(1)\n     ^";
    _542_t1 = _542_t0(_542_t2);
    $line_idx--;
    _542_$retval = _542_t1;
    return _542_$retval;
}

int64_t _544_f(int64_t _544_x) {
    int64_t _544_t1;
    uint8_t _544_t2;
    int64_t _544_t0;
    int64_t _544_$retval;
    _544_t1 = 0;
    _544_t2 = _544_t1 != _544_x;
    if (_544_t2) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _544_t0 = 174;
    goto BB4;
BB5:
    _544_t0 = 3;
    goto BB4;
BB4:
    _544_$retval = _544_t0;
    return _544_$retval;
}

int main(void) {
  printf("%ld",_542_main());
  return 0;
}
