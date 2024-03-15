/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward struct, union, and function declarations */

/* Struct, union, and function definitions */
typedef uint8_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _826_main(void);
uint8_t _831_f(int64_t _831_x);


/* Function definitions */
int64_t _826_main(void){
    function0 _826_t1;
    int64_t _826_t3;
    uint8_t _826_t2;
    int64_t _826_t0;
    int64_t _826_$retval;
    _826_t1 = (function0) _831_f;
    _826_t3 = 4;
    $lines[$line_idx++] = "tests/integration/expressions/self-greater-equal.orng:3:10:\n    if f(4) {\n        ^";
    _826_t2 = _826_t1(_826_t3);
    $line_idx--;
    if (_826_t2) {
        goto BB1001;
    } else {
        goto BB1005;
    }
BB1001:
    _826_t0 = 227;
    goto BB1004;
BB1005:
    _826_t0 = 0;
    goto BB1004;
BB1004:
    _826_$retval = _826_t0;
    return _826_$retval;
}

uint8_t _831_f(int64_t _831_x){
    uint8_t _831_$retval;
    (void)_831_x;
    _831_$retval = 1;
    return _831_$retval;
}


int main(void) {
  printf("%ld",_826_main());
  return 0;
}
