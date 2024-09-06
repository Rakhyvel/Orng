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
int64_t _60_main(void);
int64_t _63_f(void);


/* Function definitions */
int64_t _60_main(void){
    function0 _60_t0;
    int64_t _60_t1;
    int64_t _60_$retval;
    _60_t0 = (function0) _63_f;
    $lines[$line_idx++] = "tests/integration/comptime/empty-block.orng:3:7:\n    f(comptime {})\n     ^";
    _60_t1 = _60_t0();
    $line_idx--;
    _60_$retval = _60_t1;
    return _60_$retval;
}

int64_t _63_f(void){
    int64_t _63_$retval;
    _63_$retval = 262;
    return _63_$retval;
}


int main(void) {
  printf("%ld",_60_main());
  return 0;
}
