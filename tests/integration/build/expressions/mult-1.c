/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef uint8_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _712_main(void);
uint8_t _717_f(int64_t _717_x);

/* Function definitions */
int64_t _712_main(void){
    function0 _712_t1;
    int64_t _712_t3;
    uint8_t _712_t2;
    int64_t _712_t0;
    int64_t _712_$retval;
    _712_t1 = _717_f;
    _712_t3 = 4;
    $lines[$line_idx++] = "tests/integration/expressions/mult-1.orng:3:10:\n    if f(4) {\n        ^";
    _712_t2 = _712_t1(_712_t3);
    $line_idx--;
    if (_712_t2) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _712_t0 = 186;
    goto BB4;
BB5:
    _712_t0 = 4;
    goto BB4;
BB4:
    _712_$retval = _712_t0;
    return _712_$retval;
}

uint8_t _717_f(int64_t _717_x){
    uint8_t _717_$retval;
    (void)_717_x;
    _717_$retval = 1;
    return _717_$retval;
}

int main(void) {
  printf("%ld",_712_main());
  return 0;
}
