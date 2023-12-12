/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef uint8_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _611_main(void);
uint8_t _616_f(int64_t _616_x);

/* Function definitions */
int64_t _611_main(void) {
    function0 _611_t1;
    int64_t _611_t3;
    uint8_t _611_t2;
    int64_t _611_t0;
    int64_t _611_$retval;
    _611_t1 = _616_f;
    _611_t3 = 4;
    $lines[$line_idx++] = "tests/integration/expressions/self-lesser.orng:3:10:\n    if f(4) {\n        ^";
    _611_t2 = _611_t1(_611_t3);
    $line_idx--;
    if (_611_t2) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _611_t0 = 0;
    goto BB4;
BB5:
    _611_t0 = 226;
    goto BB4;
BB4:
    _611_$retval = _611_t0;
    return _611_$retval;
}

uint8_t _616_f(int64_t _616_x) {
    uint8_t _616_$retval;
    (void)_616_x;
    _616_$retval = 0;
    return _616_$retval;
}

int main(void) {
  printf("%ld",_611_main());
  return 0;
}
