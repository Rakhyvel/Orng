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
int64_t _629_main(void);
uint8_t _634_f(int64_t _634_x);


/* Function definitions */
int64_t _629_main(void){
    function0 _629_t1;
    int64_t _629_t3;
    uint8_t _629_t2;
    int64_t _629_t0;
    int64_t _629_$retval;
    _629_t1 = (function0) _634_f;
    _629_t3 = 4;
    $lines[$line_idx++] = "tests/integration/expressions/add-zero.orng:3:10:\n    if f(4) {\n        ^";
    _629_t2 = _629_t1(_629_t3);
    $line_idx--;
    if (_629_t2) {
        goto BB739;
    } else {
        goto BB743;
    }
BB739:
    _629_t0 = 182;
    goto BB742;
BB743:
    _629_t0 = 4;
    goto BB742;
BB742:
    _629_$retval = _629_t0;
    return _629_$retval;
}

uint8_t _634_f(int64_t _634_x){
    uint8_t _634_$retval;
    (void)_634_x;
    goto BB734;
BB734:
    _634_$retval = 1;
    return _634_$retval;
}


int main(void) {
  printf("%ld",_629_main());
  return 0;
}
