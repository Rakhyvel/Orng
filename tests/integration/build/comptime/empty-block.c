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
int64_t _151_main(void);
int64_t _154_f(void);


/* Function definitions */
int64_t _151_main(void){
    function0 _151_t0;
    int64_t _151_t1;
    int64_t _151_$retval;
    _151_t0 = (function0) _154_f;
    $lines[$line_idx++] = "tests/integration/comptime/empty-block.orng:3:7:\n    f(comptime {})\n     ^";
    _151_t1 = _151_t0();
    $line_idx--;
    _151_$retval = _151_t1;
    return _151_$retval;
}

int64_t _154_f(void){
    int64_t _154_$retval;
    _154_$retval = 262;
    return _154_$retval;
}


int main(void) {
  printf("%ld",_151_main());
  return 0;
}
