/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef uint8_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _707_main(void);
uint8_t _712_f(int64_t _712_x);

/* Function definitions */
int64_t _707_main(void){
    function0 _707_t1;
    int64_t _707_t3;
    uint8_t _707_t2;
    int64_t _707_t0;
    int64_t _707_$retval;
    _707_t1 = _712_f;
    _707_t3 = 4;
    $lines[$line_idx++] = "tests/integration/expressions/mod-0.orng:3:10:\n    if f(4) {\n        ^";
    _707_t2 = _707_t1(_707_t3);
    $line_idx--;
    if (_707_t2) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _707_t0 = 191;
    goto BB4;
BB5:
    _707_t0 = 4;
    goto BB4;
BB4:
    _707_$retval = _707_t0;
    return _707_$retval;
}

uint8_t _712_f(int64_t _712_x){
    uint8_t _712_$retval;
    (void)_712_x;
    _712_$retval = 1;
    return _712_$retval;
}

int main(void) {
  printf("%ld",_707_main());
  return 0;
}
