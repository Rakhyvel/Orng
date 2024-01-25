/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward struct, union, and function declarations */

/* Struct, union, and function definitions */
typedef int64_t(*function0)(void);

/* Function forward definitions */
int64_t _144_main(void);
int64_t _147_f(void);


/* Function definitions */
int64_t _144_main(void){
    function0 _144_t0;
    int64_t _144_t1;
    int64_t _144_$retval;
    _144_t0 = _147_f;
    $lines[$line_idx++] = "tests/integration/comptime/empty-block.orng:3:7:\n    f(comptime {})\n     ^";
    _144_t1 = _144_t0();
    $line_idx--;
    _144_$retval = _144_t1;
    return _144_$retval;
}

int64_t _147_f(void){
    int64_t _147_$retval;
    _147_$retval = 262;
    return _147_$retval;
}


int main(void) {
  printf("%ld",_144_main());
  return 0;
}
