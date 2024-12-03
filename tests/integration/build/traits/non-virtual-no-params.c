/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward struct, union, and function declarations */

/* Struct, union, and function definitions */
typedef int64_t(*function0)(void);

/* Trait vtable type definitions */
/* Function forward definitions */
int64_t _115_main(void);
int64_t _113_f(void);

/* Trait vtable implementations */

/* Function definitions */
int64_t _115_main(void){
    function0 _115_t4;
    int64_t _115_t3;
    int64_t _115_$retval;
    _115_t4 = (function0) _113_f;
    $lines[$line_idx++] = "tests/integration/traits/non-virtual-no-params.orng:14:8:\n    x.>f()\n      ^";
    _115_t3 = _115_t4();
    $line_idx--;
    _115_$retval = _115_t3;
    return _115_$retval;
}

int64_t _113_f(void){
    int64_t _113_$retval;
    _113_$retval = 311;
    return _113_$retval;
}


int main(void) {
  printf("%ld",_115_main());
  return 0;
}
