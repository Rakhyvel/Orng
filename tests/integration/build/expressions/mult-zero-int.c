/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef uint8_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _498_main(void);
uint8_t _503_f(int64_t _503_x);

/* Function definitions */
int64_t _498_main(void) {
    function0 _498_t1;
    int64_t _498_t3;
    uint8_t _498_t2;
    int64_t _498_t0;
    int64_t _498_$retval;
    _498_t1 = _503_f;
    _498_t3 = 4;
    $lines[$line_idx++] = "tests/integration/expressions/mult-zero-int.orng:3:10:\n    if f(4) {\n        ^";
    _498_t2 = _498_t1(_498_t3);
    $line_idx--;
    if (_498_t2) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _498_t0 = 187;
    goto BB4;
BB5:
    _498_t0 = 4;
    goto BB4;
BB4:
    _498_$retval = _498_t0;
    return _498_$retval;
}

uint8_t _503_f(int64_t _503_x) {
    uint8_t _503_$retval;
    (void)_503_x;
    _503_$retval = 1;
    return _503_$retval;
}

int main(void) {
  printf("%ld",_498_main());
  return 0;
}
