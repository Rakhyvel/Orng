/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef uint8_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _667_main(void);
uint8_t _672_f(int64_t _672_x);

/* Function definitions */
int64_t _667_main(void) {
    function0 _667_t1;
    int64_t _667_t3;
    uint8_t _667_t2;
    int64_t _667_t0;
    int64_t _667_$retval;
    _667_t1 = _672_f;
    _667_t3 = 4;
    $lines[$line_idx++] = "tests/integration/expressions/mod-0.orng:3:10:\n    if f(4) {\n        ^";
    _667_t2 = _667_t1(_667_t3);
    $line_idx--;
    if (_667_t2) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _667_t0 = 191;
    goto BB4;
BB5:
    _667_t0 = 4;
    goto BB4;
BB4:
    _667_$retval = _667_t0;
    return _667_$retval;
}

uint8_t _672_f(int64_t _672_x) {
    uint8_t _672_$retval;
    (void)_672_x;
    _672_$retval = 1;
    return _672_$retval;
}

int main(void) {
  printf("%ld",_667_main());
  return 0;
}
