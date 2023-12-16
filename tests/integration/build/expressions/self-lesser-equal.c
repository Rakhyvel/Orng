/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef uint8_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _809_main(void);
uint8_t _814_f(int64_t _814_x);

/* Function definitions */
int64_t _809_main(void){
    function0 _809_t1;
    int64_t _809_t3;
    uint8_t _809_t2;
    int64_t _809_t0;
    int64_t _809_$retval;
    _809_t1 = _814_f;
    _809_t3 = 4;
    $lines[$line_idx++] = "tests/integration/expressions/self-lesser-equal.orng:3:10:\n    if f(4) {\n        ^";
    _809_t2 = _809_t1(_809_t3);
    $line_idx--;
    if (_809_t2) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _809_t0 = 228;
    goto BB4;
BB5:
    _809_t0 = 0;
    goto BB4;
BB4:
    _809_$retval = _809_t0;
    return _809_$retval;
}

uint8_t _814_f(int64_t _814_x){
    uint8_t _814_$retval;
    (void)_814_x;
    _814_$retval = 1;
    return _814_$retval;
}

int main(void) {
  printf("%ld",_809_main());
  return 0;
}
