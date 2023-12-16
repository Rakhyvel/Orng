/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef int64_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _745_main(void);
int64_t _747_f(int64_t _747_x);

/* Function definitions */
int64_t _745_main(void){
    function0 _745_t0;
    int64_t _745_t2;
    int64_t _745_t1;
    int64_t _745_$retval;
    _745_t0 = _747_f;
    _745_t2 = 1;
    $lines[$line_idx++] = "tests/integration/expressions/neq-0-lhs.orng:3:7:\n    f(1)\n     ^";
    _745_t1 = _745_t0(_745_t2);
    $line_idx--;
    _745_$retval = _745_t1;
    return _745_$retval;
}

int64_t _747_f(int64_t _747_x){
    int64_t _747_t1;
    uint8_t _747_t2;
    int64_t _747_t0;
    int64_t _747_$retval;
    _747_t1 = 0;
    _747_t2 = _747_t1 != _747_x;
    if (_747_t2) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _747_t0 = 174;
    goto BB4;
BB5:
    _747_t0 = 3;
    goto BB4;
BB4:
    _747_$retval = _747_t0;
    return _747_$retval;
}

int main(void) {
  printf("%ld",_745_main());
  return 0;
}
