/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef uint8_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _234_main(void);
uint8_t _239_f(int64_t _239_x);

/* Function definitions */
int64_t _234_main(void) {
    function0 _234_t1;
    int64_t _234_t3;
    uint8_t _234_t2;
    int64_t _234_t0;
    int64_t _234_$retval;
    _234_t1 = _239_f;
    _234_t3 = 4;
    $lines[$line_idx++] = "tests/integration/expressions/self-lesser.orng:3:10:\n    if f(4) {\n        ^";
    _234_t2 = _234_t1(_234_t3);
    $line_idx--;
    if (_234_t2) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _234_t0 = 0;
    goto BB4;
BB5:
    _234_t0 = 226;
    goto BB4;
BB4:
    _234_$retval = _234_t0;
    return _234_$retval;
}

uint8_t _239_f(int64_t _239_x) {
    uint8_t _239_$retval;
    (void)_239_x;
    _239_$retval = 0;
    return _239_$retval;
}

int main(void) {
  printf("%ld",_234_main());
  return 0;
}
