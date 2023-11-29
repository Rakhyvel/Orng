/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef uint8_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _761_main(void);
uint8_t _766_f(int64_t _766_x);

/* Function definitions */
int64_t _761_main(void) {
    function0 _761_t1;
    int64_t _761_t3;
    uint8_t _761_t2;
    int64_t _761_t0;
    int64_t _761_$retval;
    _761_t1 = _766_f;
    _761_t3 = 4;
    $lines[$line_idx++] = "tests/integration/expressions/self-greater-equal.orng:3:10:\n    if f(4) {\n        ^";
    _761_t2 = _761_t1(_761_t3);
    $line_idx--;
    if (_761_t2) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _761_t0 = 227;
    goto BB4;
BB5:
    _761_t0 = 0;
    goto BB4;
BB4:
    _761_$retval = _761_t0;
    return _761_$retval;
}

uint8_t _766_f(int64_t _766_x) {
    uint8_t _766_$retval;
    (void)_766_x;
    _766_$retval = 1;
    return _766_$retval;
}

int main(void) {
  printf("%ld",_761_main());
  return 0;
}
