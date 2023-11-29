/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef uint8_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _548_main(void);
uint8_t _553_f(int64_t _553_x);

/* Function definitions */
int64_t _548_main(void) {
    function0 _548_t1;
    int64_t _548_t3;
    uint8_t _548_t2;
    int64_t _548_t0;
    int64_t _548_$retval;
    _548_t1 = _553_f;
    _548_t3 = 4;
    $lines[$line_idx++] = "tests/integration/expressions/mult-1.orng:3:10:\n    if f(4) {\n        ^";
    _548_t2 = _548_t1(_548_t3);
    $line_idx--;
    if (_548_t2) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _548_t0 = 186;
    goto BB4;
BB5:
    _548_t0 = 4;
    goto BB4;
BB4:
    _548_$retval = _548_t0;
    return _548_$retval;
}

uint8_t _553_f(int64_t _553_x) {
    uint8_t _553_$retval;
    (void)_553_x;
    _553_$retval = 1;
    return _553_$retval;
}

int main(void) {
  printf("%ld",_548_main());
  return 0;
}
