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
int64_t _153_main(void);
int64_t _156_f(void);


/* Function definitions */
int64_t _153_main(void){
    function0 _153_t0;
    int64_t _153_t1;
    int64_t _153_$retval;
    _153_t0 = (function0) _156_f;
    $lines[$line_idx++] = "tests/integration/comptime/empty-block.orng:3:7:\n    f(comptime {})\n     ^";
    _153_t1 = _153_t0();
    $line_idx--;
    _153_$retval = _153_t1;
    return _153_$retval;
}

int64_t _156_f(void){
    int64_t _156_$retval;
    _156_$retval = 262;
    return _156_$retval;
}


int main(void) {
  printf("%ld",_153_main());
  return 0;
}
