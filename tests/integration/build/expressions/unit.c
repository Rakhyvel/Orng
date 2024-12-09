/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward struct, union, and function declarations */

/* Struct, union, and function definitions */
typedef void(*function0)(void);

/* Function forward definitions */
int64_t _915_main(void);
void _917_f(void);


/* Function definitions */
int64_t _915_main(void){
    function0 _915_t0;
    int64_t _915_$retval;
    _915_t0 = (function0) _917_f;
    $lines[$line_idx++] = "tests/integration/expressions/unit.orng:3:7:\n    f()\n     ^";
    (void) _915_t0();
    $line_idx--;
    _915_$retval = 48;
    return _915_$retval;
}

void _917_f(void){
    return;
}


int main(void) {
  printf("%ld",_915_main());
  return 0;
}
