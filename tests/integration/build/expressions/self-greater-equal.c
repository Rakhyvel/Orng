/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef uint8_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _945_main(void);
uint8_t _950_f(int64_t _950_x);

/* Function definitions */
int64_t _945_main(void){
    function0 _945_t1;
    int64_t _945_t3;
    uint8_t _945_t2;
    int64_t _945_t0;
    int64_t _945_$retval;
    _945_t1 = _950_f;
    _945_t3 = 4;
    $lines[$line_idx++] = "tests/integration/expressions/self-greater-equal.orng:3:10:\n    if f(4) {\n        ^";
    _945_t2 = _945_t1(_945_t3);
    $line_idx--;
    if (_945_t2) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _945_t0 = 227;
    goto BB4;
BB5:
    _945_t0 = 0;
    goto BB4;
BB4:
    _945_$retval = _945_t0;
    return _945_$retval;
}

uint8_t _950_f(int64_t _950_x){
    uint8_t _950_$retval;
    (void)_950_x;
    _950_$retval = 1;
    return _950_$retval;
}

int main(void) {
  printf("%ld",_945_main());
  return 0;
}
