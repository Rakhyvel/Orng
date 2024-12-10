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
int64_t _930_main(void);
void _932_f(void);


/* Function definitions */
int64_t _930_main(void){
    function0 _930_t0;
    int64_t _930_$retval;
    _930_t0 = (function0) _932_f;
    $lines[$line_idx++] = "tests/integration/expressions/unit.orng:3:7:\n    f()\n     ^";
    (void) _930_t0();
    $line_idx--;
    _930_$retval = 48;
    return _930_$retval;
}

void _932_f(void){
    return;
}


int main(void) {
  printf("%ld",_930_main());
  return 0;
}
