/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef int64_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _824_main(void);
int64_t _826_f(int64_t _826_x);

/* Function definitions */
int64_t _824_main(void){
    function0 _824_t0;
    int64_t _824_t2;
    int64_t _824_t1;
    int64_t _824_$retval;
    _824_t0 = _826_f;
    _824_t2 = 1;
    $lines[$line_idx++] = "tests/integration/expressions/neq-0-rhs.orng:3:7:\n    f(1)\n     ^";
    _824_t1 = _824_t0(_824_t2);
    $line_idx--;
    _824_$retval = _824_t1;
    return _824_$retval;
}

int64_t _826_f(int64_t _826_x){
    int64_t _826_t1;
    uint8_t _826_t2;
    int64_t _826_t0;
    int64_t _826_$retval;
    _826_t1 = 0;
    _826_t2 = _826_x != _826_t1;
    if (_826_t2) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _826_t0 = 173;
    goto BB4;
BB5:
    _826_t0 = 3;
    goto BB4;
BB4:
    _826_$retval = _826_t0;
    return _826_$retval;
}

int main(void) {
  printf("%ld",_824_main());
  return 0;
}
