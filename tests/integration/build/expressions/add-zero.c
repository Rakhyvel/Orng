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
int64_t _658_main(void);
uint8_t _663_f(int64_t _663_x);


/* Function definitions */
int64_t _658_main(void){
    function0 _658_t1;
    int64_t _658_t3;
    uint8_t _658_t2;
    int64_t _658_t0;
    int64_t _658_$retval;
    _658_t1 = _663_f;
    _658_t3 = 4;
    $lines[$line_idx++] = "tests/integration/expressions/add-zero.orng:3:10:\n    if f(4) {\n        ^";
    _658_t2 = _658_t1(_658_t3);
    $line_idx--;
    if (_658_t2) {
        goto BB796;
    } else {
        goto BB800;
    }
BB796:
    _658_t0 = 182;
    goto BB799;
BB800:
    _658_t0 = 4;
    goto BB799;
BB799:
    _658_$retval = _658_t0;
    return _658_$retval;
}

uint8_t _663_f(int64_t _663_x){
    uint8_t _663_$retval;
    (void)_663_x;
    _663_$retval = 1;
    return _663_$retval;
}


int main(void) {
  printf("%ld",_658_main());
  return 0;
}
