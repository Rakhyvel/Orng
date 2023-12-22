/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef uint8_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _845_main(void);
uint8_t _850_f(int64_t _850_x);

/* Function definitions */
int64_t _845_main(void){
    function0 _845_t1;
    int64_t _845_t3;
    uint8_t _845_t2;
    int64_t _845_t0;
    int64_t _845_$retval;
    _845_t1 = _850_f;
    _845_t3 = 4;
    $lines[$line_idx++] = "tests/integration/expressions/self-lesser.orng:3:10:\n    if f(4) {\n        ^";
    _845_t2 = _845_t1(_845_t3);
    $line_idx--;
    if (_845_t2) {
        goto BB1079;
    } else {
        goto BB1083;
    }
BB1079:
    _845_t0 = 0;
    goto BB1082;
BB1083:
    _845_t0 = 226;
    goto BB1082;
BB1082:
    _845_$retval = _845_t0;
    return _845_$retval;
}

uint8_t _850_f(int64_t _850_x){
    uint8_t _850_$retval;
    (void)_850_x;
    _850_$retval = 0;
    return _850_$retval;
}

int main(void) {
  printf("%ld",_845_main());
  return 0;
}
