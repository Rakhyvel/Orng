/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef int64_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _901_main(void);
int64_t _903_f(int64_t _903_x);

/* Function definitions */
int64_t _901_main(void){
    function0 _901_t0;
    int64_t _901_t2;
    int64_t _901_t1;
    int64_t _901_$retval;
    _901_t0 = _903_f;
    _901_t2 = 1;
    $lines[$line_idx++] = "tests/integration/expressions/neq-0-lhs.orng:3:7:\n    f(1)\n     ^";
    _901_t1 = _901_t0(_901_t2);
    $line_idx--;
    _901_$retval = _901_t1;
    return _901_$retval;
}

int64_t _903_f(int64_t _903_x){
    int64_t _903_t1;
    uint8_t _903_t2;
    int64_t _903_t0;
    int64_t _903_$retval;
    _903_t1 = 0;
    _903_t2 = _903_t1 != _903_x;
    if (_903_t2) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _903_t0 = 174;
    goto BB4;
BB5:
    _903_t0 = 3;
    goto BB4;
BB4:
    _903_$retval = _903_t0;
    return _903_$retval;
}

int main(void) {
  printf("%ld",_901_main());
  return 0;
}
