/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef int64_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _916_main(void);
int64_t _918_f(int64_t _918_x);

/* Function definitions */
int64_t _916_main(void){
    function0 _916_t0;
    int64_t _916_t2;
    int64_t _916_t1;
    int64_t _916_$retval;
    _916_t0 = _918_f;
    _916_t2 = 1;
    $lines[$line_idx++] = "tests/integration/expressions/neq-0-rhs.orng:3:7:\n    f(1)\n     ^";
    _916_t1 = _916_t0(_916_t2);
    $line_idx--;
    _916_$retval = _916_t1;
    return _916_$retval;
}

int64_t _918_f(int64_t _918_x){
    int64_t _918_t1;
    uint8_t _918_t2;
    int64_t _918_t0;
    int64_t _918_$retval;
    _918_t1 = 0;
    _918_t2 = _918_x != _918_t1;
    if (_918_t2) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _918_t0 = 173;
    goto BB4;
BB5:
    _918_t0 = 3;
    goto BB4;
BB4:
    _918_$retval = _918_t0;
    return _918_$retval;
}

int main(void) {
  printf("%ld",_916_main());
  return 0;
}
