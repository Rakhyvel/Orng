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
int64_t _944_main(void);
void _946_f(void);


/* Function definitions */
int64_t _944_main(void){
    function0 _944_t0;
    int64_t _944_$retval;
    _944_t0 = _946_f;
    $lines[$line_idx++] = "tests/integration/expressions/unit.orng:3:7:\n    f()\n     ^";
    (void) _944_t0();
    $line_idx--;
    _944_$retval = 48;
    return _944_$retval;
}

void _946_f(void){
    return;
}


int main(void) {
  printf("%ld",_944_main());
  return 0;
}
