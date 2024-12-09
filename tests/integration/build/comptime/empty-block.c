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
int64_t _149_main(void);
int64_t _152_f(void);


/* Function definitions */
int64_t _149_main(void){
    function0 _149_t0;
    int64_t _149_t1;
    int64_t _149_$retval;
    _149_t0 = (function0) _152_f;
    $lines[$line_idx++] = "tests/integration/comptime/empty-block.orng:3:7:\n    f(comptime {})\n     ^";
    _149_t1 = _149_t0();
    $line_idx--;
    _149_$retval = _149_t1;
    return _149_$retval;
}

int64_t _152_f(void){
    int64_t _152_$retval;
    _152_$retval = 262;
    return _152_$retval;
}


int main(void) {
  printf("%ld",_149_main());
  return 0;
}
