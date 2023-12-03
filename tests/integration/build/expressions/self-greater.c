/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef uint8_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _587_main(void);
uint8_t _592_f(int64_t _592_x);

/* Function definitions */
int64_t _587_main(void) {
    function0 _587_t1;
    int64_t _587_t3;
    uint8_t _587_t2;
    int64_t _587_t0;
    int64_t _587_$retval;
    _587_t1 = _592_f;
    _587_t3 = 4;
    $lines[$line_idx++] = "tests/integration/expressions/self-greater.orng:3:10:\n    if f(4) {\n        ^";
    _587_t2 = _587_t1(_587_t3);
    $line_idx--;
    if (_587_t2) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _587_t0 = 0;
    goto BB4;
BB5:
    _587_t0 = 224;
    goto BB4;
BB4:
    _587_$retval = _587_t0;
    return _587_$retval;
}

uint8_t _592_f(int64_t _592_x) {
    uint8_t _592_$retval;
    (void)_592_x;
    _592_$retval = 0;
    return _592_$retval;
}

int main(void) {
  printf("%ld",_587_main());
  return 0;
}
