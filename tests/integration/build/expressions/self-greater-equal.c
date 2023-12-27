/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef uint8_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _821_main(void);
uint8_t _826_f(int64_t _826_x);

/* Function definitions */
int64_t _821_main(void){
    function0 _821_t1;
    int64_t _821_t3;
    uint8_t _821_t2;
    int64_t _821_t0;
    int64_t _821_$retval;
    _821_t1 = _826_f;
    _821_t3 = 4;
    $lines[$line_idx++] = "tests/integration/expressions/self-greater-equal.orng:3:10:\n    if f(4) {\n        ^";
    _821_t2 = _821_t1(_821_t3);
    $line_idx--;
    if (_821_t2) {
        goto BB1039;
    } else {
        goto BB1043;
    }
BB1039:
    _821_t0 = 227;
    goto BB1042;
BB1043:
    _821_t0 = 0;
    goto BB1042;
BB1042:
    _821_$retval = _821_t0;
    return _821_$retval;
}

uint8_t _826_f(int64_t _826_x){
    uint8_t _826_$retval;
    (void)_826_x;
    _826_$retval = 1;
    return _826_$retval;
}

int main(void) {
  printf("%ld",_821_main());
  return 0;
}
