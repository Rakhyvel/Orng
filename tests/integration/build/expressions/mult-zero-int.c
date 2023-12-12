/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef uint8_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _558_main(void);
uint8_t _563_f(int64_t _563_x);

/* Function definitions */
int64_t _558_main(void) {
    function0 _558_t1;
    int64_t _558_t3;
    uint8_t _558_t2;
    int64_t _558_t0;
    int64_t _558_$retval;
    _558_t1 = _563_f;
    _558_t3 = 4;
    $lines[$line_idx++] = "tests/integration/expressions/mult-zero-int.orng:3:10:\n    if f(4) {\n        ^";
    _558_t2 = _558_t1(_558_t3);
    $line_idx--;
    if (_558_t2) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _558_t0 = 187;
    goto BB4;
BB5:
    _558_t0 = 4;
    goto BB4;
BB4:
    _558_$retval = _558_t0;
    return _558_$retval;
}

uint8_t _563_f(int64_t _563_x) {
    uint8_t _563_$retval;
    (void)_563_x;
    _563_$retval = 1;
    return _563_$retval;
}

int main(void) {
  printf("%ld",_558_main());
  return 0;
}
