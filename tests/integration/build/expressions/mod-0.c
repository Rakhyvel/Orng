/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef uint8_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _669_main(void);
uint8_t _674_f(int64_t _674_x);

/* Function definitions */
int64_t _669_main(void) {
    function0 _669_t1;
    int64_t _669_t3;
    uint8_t _669_t2;
    int64_t _669_t0;
    int64_t _669_$retval;
    _669_t1 = _674_f;
    _669_t3 = 4;
    $lines[$line_idx++] = "tests/integration/expressions/mod-0.orng:3:10:\n    if f(4) {\n        ^";
    _669_t2 = _669_t1(_669_t3);
    $line_idx--;
    if (_669_t2) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _669_t0 = 191;
    goto BB4;
BB5:
    _669_t0 = 4;
    goto BB4;
BB4:
    _669_$retval = _669_t0;
    return _669_$retval;
}

uint8_t _674_f(int64_t _674_x) {
    uint8_t _674_$retval;
    (void)_674_x;
    _674_$retval = 1;
    return _674_$retval;
}

int main(void) {
  printf("%ld",_669_main());
  return 0;
}
