/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef uint8_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _528_main(void);
uint8_t _533_f(int64_t _533_x);

/* Function definitions */
int64_t _528_main(void) {
    function0 _528_t1;
    int64_t _528_t3;
    uint8_t _528_t2;
    int64_t _528_t0;
    int64_t _528_$retval;
    _528_t1 = _533_f;
    _528_t3 = 4;
    $lines[$line_idx++] = "tests/integration/expressions/mod-1.orng:3:10:\n    if f(4) {\n        ^";
    _528_t2 = _528_t1(_528_t3);
    $line_idx--;
    if (_528_t2) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _528_t0 = 192;
    goto BB4;
BB5:
    _528_t0 = 4;
    goto BB4;
BB4:
    _528_$retval = _528_t0;
    return _528_$retval;
}

uint8_t _533_f(int64_t _533_x) {
    uint8_t _533_$retval;
    (void)_533_x;
    _533_$retval = 1;
    return _533_$retval;
}

int main(void) {
  printf("%ld",_528_main());
  return 0;
}
