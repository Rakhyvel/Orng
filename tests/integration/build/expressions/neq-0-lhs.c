/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef int64_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _784_main(void);
int64_t _786_f(int64_t _786_x);

/* Function definitions */
int64_t _784_main(void){
    function0 _784_t0;
    int64_t _784_t2;
    int64_t _784_t1;
    int64_t _784_$retval;
    _784_t0 = _786_f;
    _784_t2 = 1;
    $lines[$line_idx++] = "tests/integration/expressions/neq-0-lhs.orng:3:7:\n    f(1)\n     ^";
    _784_t1 = _784_t0(_784_t2);
    $line_idx--;
    _784_$retval = _784_t1;
    return _784_$retval;
}

int64_t _786_f(int64_t _786_x){
    int64_t _786_t1;
    uint8_t _786_t2;
    int64_t _786_t0;
    int64_t _786_$retval;
    _786_t1 = 0;
    _786_t2 = _786_t1 != _786_x;
    if (_786_t2) {
        goto BB1015;
    } else {
        goto BB1019;
    }
BB1015:
    _786_t0 = 174;
    goto BB1018;
BB1019:
    _786_t0 = 3;
    goto BB1018;
BB1018:
    _786_$retval = _786_t0;
    return _786_$retval;
}

int main(void) {
  printf("%ld",_784_main());
  return 0;
}
