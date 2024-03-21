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
int64_t _910_main(void);
void _912_f(void);


/* Function definitions */
int64_t _910_main(void){
    function0 _910_t0;
    int64_t _910_$retval;
    _910_t0 = (function0) _912_f;
    $lines[$line_idx++] = "tests/integration/expressions/unit.orng:3:7:\n    f()\n     ^";
    (void) _910_t0();
    $line_idx--;
    _910_$retval = 48;
    return _910_$retval;
}

void _912_f(void){
}


int main(void) {
  printf("%ld",_910_main());
  return 0;
}
