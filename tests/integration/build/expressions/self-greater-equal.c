/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef uint8_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _618_main(void);
uint8_t _623_f(int64_t _623_x);

/* Function definitions */
int64_t _618_main(void) {
    function0 _618_t1;
    int64_t _618_t3;
    uint8_t _618_t2;
    int64_t _618_t0;
    int64_t _618_$retval;
    _618_t1 = _623_f;
    _618_t3 = 4;
    $lines[$line_idx++] = "tests/integration/expressions/self-greater-equal.orng:3:10:\n    if f(4) {\n        ^";
    _618_t2 = _618_t1(_618_t3);
    $line_idx--;
    if (_618_t2) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _618_t0 = 227;
    goto BB4;
BB5:
    _618_t0 = 0;
    goto BB4;
BB4:
    _618_$retval = _618_t0;
    return _618_$retval;
}

uint8_t _623_f(int64_t _623_x) {
    uint8_t _623_$retval;
    (void)_623_x;
    _623_$retval = 1;
    return _623_$retval;
}

int main(void) {
  printf("%ld",_618_main());
  return 0;
}
