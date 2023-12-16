/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef uint8_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _571_main(void);
uint8_t _576_f(int64_t _576_x);

/* Function definitions */
int64_t _571_main(void){
    function0 _571_t1;
    int64_t _571_t3;
    uint8_t _571_t2;
    int64_t _571_t0;
    int64_t _571_$retval;
    _571_t1 = _576_f;
    _571_t3 = 4;
    $lines[$line_idx++] = "tests/integration/expressions/add-zero.orng:3:10:\n    if f(4) {\n        ^";
    _571_t2 = _571_t1(_571_t3);
    $line_idx--;
    if (_571_t2) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _571_t0 = 182;
    goto BB4;
BB5:
    _571_t0 = 4;
    goto BB4;
BB4:
    _571_$retval = _571_t0;
    return _571_$retval;
}

uint8_t _576_f(int64_t _576_x){
    uint8_t _576_$retval;
    (void)_576_x;
    _576_$retval = 1;
    return _576_$retval;
}

int main(void) {
  printf("%ld",_571_main());
  return 0;
}
