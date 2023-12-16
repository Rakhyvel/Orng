/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef int64_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _764_main(void);
int64_t _766_f(int64_t _766_x);

/* Function definitions */
int64_t _764_main(void){
    function0 _764_t0;
    int64_t _764_t2;
    int64_t _764_t1;
    int64_t _764_$retval;
    _764_t0 = _766_f;
    _764_t2 = 1;
    $lines[$line_idx++] = "tests/integration/expressions/neq-0-rhs.orng:3:7:\n    f(1)\n     ^";
    _764_t1 = _764_t0(_764_t2);
    $line_idx--;
    _764_$retval = _764_t1;
    return _764_$retval;
}

int64_t _766_f(int64_t _766_x){
    int64_t _766_t1;
    uint8_t _766_t2;
    int64_t _766_t0;
    int64_t _766_$retval;
    _766_t1 = 0;
    _766_t2 = _766_x != _766_t1;
    if (_766_t2) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _766_t0 = 173;
    goto BB4;
BB5:
    _766_t0 = 3;
    goto BB4;
BB4:
    _766_$retval = _766_t0;
    return _766_$retval;
}

int main(void) {
  printf("%ld",_764_main());
  return 0;
}
