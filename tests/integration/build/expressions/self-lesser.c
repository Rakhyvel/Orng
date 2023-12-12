/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef uint8_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _630_main(void);
uint8_t _635_f(int64_t _635_x);

/* Function definitions */
int64_t _630_main(void) {
    function0 _630_t1;
    int64_t _630_t3;
    uint8_t _630_t2;
    int64_t _630_t0;
    int64_t _630_$retval;
    _630_t1 = _635_f;
    _630_t3 = 4;
    $lines[$line_idx++] = "tests/integration/expressions/self-lesser.orng:3:10:\n    if f(4) {\n        ^";
    _630_t2 = _630_t1(_630_t3);
    $line_idx--;
    if (_630_t2) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _630_t0 = 0;
    goto BB4;
BB5:
    _630_t0 = 226;
    goto BB4;
BB4:
    _630_$retval = _630_t0;
    return _630_$retval;
}

uint8_t _635_f(int64_t _635_x) {
    uint8_t _635_$retval;
    (void)_635_x;
    _635_$retval = 0;
    return _635_$retval;
}

int main(void) {
  printf("%ld",_630_main());
  return 0;
}
