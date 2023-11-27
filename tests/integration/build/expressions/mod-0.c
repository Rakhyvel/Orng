/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef uint8_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _460_main(void);
uint8_t _465_f(int64_t _465_x);

/* Function definitions */
int64_t _460_main(void) {
    function0 _460_t1;
    int64_t _460_t3;
    uint8_t _460_t2;
    int64_t _460_t0;
    int64_t _460_$retval;
    _460_t1 = _465_f;
    _460_t3 = 4;
    $lines[$line_idx++] = "tests/integration/expressions/mod-0.orng:3:10:\n    if f(4) {\n        ^";
    _460_t2 = _460_t1(_460_t3);
    $line_idx--;
    if (_460_t2) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _460_t0 = 191;
    goto BB4;
BB5:
    _460_t0 = 4;
    goto BB4;
BB4:
    _460_$retval = _460_t0;
    return _460_$retval;
}

uint8_t _465_f(int64_t _465_x) {
    uint8_t _465_$retval;
    (void)_465_x;
    _465_$retval = 1;
    return _465_$retval;
}

int main(void) {
  printf("%ld",_460_main());
  return 0;
}
