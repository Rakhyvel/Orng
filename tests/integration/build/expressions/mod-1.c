/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef uint8_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _132_main(void);
uint8_t _137_f(int64_t _137_x);

/* Function definitions */
int64_t _132_main(void) {
    function0 _132_t1;
    int64_t _132_t3;
    uint8_t _132_t2;
    int64_t _132_t0;
    int64_t _132_$retval;
    _132_t1 = _137_f;
    _132_t3 = 4;
    $lines[$line_idx++] = "tests/integration/expressions/mod-1.orng:3:10:\n    if f(4) {\n        ^";
    _132_t2 = _132_t1(_132_t3);
    $line_idx--;
    if (_132_t2) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _132_t0 = 192;
    goto BB4;
BB5:
    _132_t0 = 4;
    goto BB4;
BB4:
    _132_$retval = _132_t0;
    return _132_$retval;
}

uint8_t _137_f(int64_t _137_x) {
    uint8_t _137_t4;
    uint8_t _137_t3;
    uint8_t _137_$retval;
    (void)_137_x;
    _137_t4 = 1;
    if (_137_t4) {
        goto BB1;
    } else {
        goto BB4;
    }
BB1:
    _137_t3 = 1;
    goto BB3;
BB4:
    _137_t3 = 0;
    goto BB3;
BB3:
    _137_$retval = _137_t3;
    return _137_$retval;
}

int main(void) {
  printf("%ld",_132_main());
  return 0;
}
