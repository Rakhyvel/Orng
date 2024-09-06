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
int64_t _918_main(void);
void _920_f(void);


/* Function definitions */
int64_t _918_main(void){
    function0 _918_t0;
    int64_t _918_$retval;
    _918_t0 = (function0) _920_f;
    $lines[$line_idx++] = "tests/integration/expressions/unit.orng:3:7:\n    f()\n     ^";
    (void) _918_t0();
    $line_idx--;
    _918_$retval = 48;
    return _918_$retval;
}

void _920_f(void){
    return;
}


int main(void) {
  printf("%ld",_918_main());
  return 0;
}
