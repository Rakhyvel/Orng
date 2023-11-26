/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef uint8_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _437_main(void);
uint8_t _442_f(int64_t _442_x);

/* Function definitions */
int64_t _437_main(void) {
    function0 _437_t1;
    int64_t _437_t3;
    uint8_t _437_t2;
    int64_t _437_t0;
    int64_t _437_$retval;
    _437_t1 = _442_f;
    _437_t3 = 4;
    $lines[$line_idx++] = "tests/integration/expressions/mod-1.orng:3:10:\n    if f(4) {\n        ^";
    _437_t2 = _437_t1(_437_t3);
    $line_idx--;
    if (_437_t2) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _437_t0 = 192;
    goto BB4;
BB5:
    _437_t0 = 4;
    goto BB4;
BB4:
    _437_$retval = _437_t0;
    return _437_$retval;
}

uint8_t _442_f(int64_t _442_x) {
    uint8_t _442_t4;
    uint8_t _442_t3;
    uint8_t _442_$retval;
    (void)_442_x;
    _442_t4 = 1;
    if (_442_t4) {
        goto BB1;
    } else {
        goto BB4;
    }
BB1:
    _442_t3 = 1;
    goto BB3;
BB4:
    _442_t3 = 0;
    goto BB3;
BB3:
    _442_$retval = _442_t3;
    return _442_$retval;
}

int main(void) {
  printf("%ld",_437_main());
  return 0;
}
