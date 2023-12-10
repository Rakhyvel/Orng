/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef uint8_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _493_main(void);
uint8_t _498_f(int64_t _498_x);

/* Function definitions */
int64_t _493_main(void) {
    function0 _493_t1;
    int64_t _493_t3;
    uint8_t _493_t2;
    int64_t _493_t0;
    int64_t _493_$retval;
    _493_t1 = _498_f;
    _493_t3 = 4;
    $lines[$line_idx++] = "tests/integration/expressions/mod-0.orng:3:10:\n    if f(4) {\n        ^";
    _493_t2 = _493_t1(_493_t3);
    $line_idx--;
    if (_493_t2) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _493_t0 = 191;
    goto BB4;
BB5:
    _493_t0 = 4;
    goto BB4;
BB4:
    _493_$retval = _493_t0;
    return _493_$retval;
}

uint8_t _498_f(int64_t _498_x) {
    uint8_t _498_$retval;
    (void)_498_x;
    _498_$retval = 1;
    return _498_$retval;
}

int main(void) {
  printf("%ld",_493_main());
  return 0;
}
