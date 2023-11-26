/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef uint8_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _124_main(void);
uint8_t _129_f(int64_t _129_x);

/* Function definitions */
int64_t _124_main(void) {
    function0 _124_t1;
    int64_t _124_t3;
    uint8_t _124_t2;
    int64_t _124_t0;
    int64_t _124_$retval;
    _124_t1 = _129_f;
    _124_t3 = 4;
    $lines[$line_idx++] = "tests/integration/expressions/mod-0.orng:3:10:\n    if f(4) {\n        ^";
    _124_t2 = _124_t1(_124_t3);
    $line_idx--;
    if (_124_t2) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _124_t0 = 191;
    goto BB4;
BB5:
    _124_t0 = 4;
    goto BB4;
BB4:
    _124_$retval = _124_t0;
    return _124_$retval;
}

uint8_t _129_f(int64_t _129_x) {
    uint8_t _129_t4;
    uint8_t _129_t3;
    uint8_t _129_$retval;
    (void)_129_x;
    _129_t4 = 1;
    if (_129_t4) {
        goto BB1;
    } else {
        goto BB4;
    }
BB1:
    _129_t3 = 1;
    goto BB3;
BB4:
    _129_t3 = 0;
    goto BB3;
BB3:
    _129_$retval = _129_t3;
    return _129_$retval;
}

int main(void) {
  printf("%ld",_124_main());
  return 0;
}
