/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef int64_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _709_main(void);
int64_t _711_f(int64_t _711_x);

/* Function definitions */
int64_t _709_main(void) {
    function0 _709_t0;
    int64_t _709_t2;
    int64_t _709_t1;
    int64_t _709_$retval;
    _709_t0 = _711_f;
    _709_t2 = 1;
    $lines[$line_idx++] = "tests/integration/expressions/neq-0-rhs.orng:3:7:\n    f(1)\n     ^";
    _709_t1 = _709_t0(_709_t2);
    $line_idx--;
    _709_$retval = _709_t1;
    return _709_$retval;
}

int64_t _711_f(int64_t _711_x) {
    int64_t _711_t1;
    uint8_t _711_t2;
    int64_t _711_t0;
    int64_t _711_$retval;
    _711_t1 = 0;
    _711_t2 = _711_x != _711_t1;
    if (_711_t2) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _711_t0 = 173;
    goto BB4;
BB5:
    _711_t0 = 3;
    goto BB4;
BB4:
    _711_$retval = _711_t0;
    return _711_$retval;
}

int main(void) {
  printf("%ld",_709_main());
  return 0;
}
