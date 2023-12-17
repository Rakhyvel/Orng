/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef uint8_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _938_main(void);
uint8_t _943_f(int64_t _943_x);

/* Function definitions */
int64_t _938_main(void){
    function0 _938_t1;
    int64_t _938_t3;
    uint8_t _938_t2;
    int64_t _938_t0;
    int64_t _938_$retval;
    _938_t1 = _943_f;
    _938_t3 = 4;
    $lines[$line_idx++] = "tests/integration/expressions/self-greater-equal.orng:3:10:\n    if f(4) {\n        ^";
    _938_t2 = _938_t1(_938_t3);
    $line_idx--;
    if (_938_t2) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _938_t0 = 227;
    goto BB4;
BB5:
    _938_t0 = 0;
    goto BB4;
BB4:
    _938_$retval = _938_t0;
    return _938_$retval;
}

uint8_t _943_f(int64_t _943_x){
    uint8_t _943_$retval;
    (void)_943_x;
    _943_$retval = 1;
    return _943_$retval;
}

int main(void) {
  printf("%ld",_938_main());
  return 0;
}
