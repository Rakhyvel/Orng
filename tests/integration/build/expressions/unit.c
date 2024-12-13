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
int64_t _932_main(void);
void _934_f(void);


/* Function definitions */
int64_t _932_main(void){
    function0 _932_t0;
    int64_t _932_$retval;
    _932_t0 = (function0) _934_f;
    $lines[$line_idx++] = "tests/integration/expressions/unit.orng:3:7:\n    f()\n     ^";
    (void) _932_t0();
    $line_idx--;
    _932_$retval = 48;
    return _932_$retval;
}

void _934_f(void){
    return;
}


int main(void) {
  printf("%ld",_932_main());
  return 0;
}
