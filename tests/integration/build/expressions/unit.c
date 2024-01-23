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
int64_t _917_main(void);
void _919_f(void);


/* Function definitions */
int64_t _917_main(void){
    function0 _917_t0;
    int64_t _917_$retval;
    _917_t0 = _919_f;
    $lines[$line_idx++] = "tests/integration/expressions/unit.orng:3:7:\n    f()\n     ^";
    (void) _917_t0();
    $line_idx--;
    _917_$retval = 48;
    return _917_$retval;
}

void _919_f(void){
    return;
}


int main(void) {
  printf("%ld",_917_main());
  return 0;
}
