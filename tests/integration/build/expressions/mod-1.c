/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef uint8_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _468_main(void);
uint8_t _473_f(int64_t _473_x);

/* Function definitions */
int64_t _468_main(void) {
    function0 _468_t1;
    int64_t _468_t3;
    uint8_t _468_t2;
    int64_t _468_t0;
    int64_t _468_$retval;
    _468_t1 = _473_f;
    _468_t3 = 4;
    $lines[$line_idx++] = "tests/integration/expressions/mod-1.orng:3:10:\n    if f(4) {\n        ^";
    _468_t2 = _468_t1(_468_t3);
    $line_idx--;
    if (_468_t2) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _468_t0 = 192;
    goto BB4;
BB5:
    _468_t0 = 4;
    goto BB4;
BB4:
    _468_$retval = _468_t0;
    return _468_$retval;
}

uint8_t _473_f(int64_t _473_x) {
    uint8_t _473_$retval;
    (void)_473_x;
    _473_$retval = 1;
    return _473_$retval;
}

int main(void) {
  printf("%ld",_468_main());
  return 0;
}
