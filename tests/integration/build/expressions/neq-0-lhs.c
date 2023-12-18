/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef int64_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _908_main(void);
int64_t _910_f(int64_t _910_x);

/* Function definitions */
int64_t _908_main(void){
    function0 _908_t0;
    int64_t _908_t2;
    int64_t _908_t1;
    int64_t _908_$retval;
    _908_t0 = _910_f;
    _908_t2 = 1;
    $lines[$line_idx++] = "tests/integration/expressions/neq-0-lhs.orng:3:7:\n    f(1)\n     ^";
    _908_t1 = _908_t0(_908_t2);
    $line_idx--;
    _908_$retval = _908_t1;
    return _908_$retval;
}

int64_t _910_f(int64_t _910_x){
    int64_t _910_t1;
    uint8_t _910_t2;
    int64_t _910_t0;
    int64_t _910_$retval;
    _910_t1 = 0;
    _910_t2 = _910_t1 != _910_x;
    if (_910_t2) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _910_t0 = 174;
    goto BB4;
BB5:
    _910_t0 = 3;
    goto BB4;
BB4:
    _910_$retval = _910_t0;
    return _910_$retval;
}

int main(void) {
  printf("%ld",_908_main());
  return 0;
}
