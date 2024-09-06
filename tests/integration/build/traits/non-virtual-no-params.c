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
int64_t _1698_main(void);
int64_t _1696_f(void);

/* Trait vtable implementations */

/* Function definitions */
int64_t _1698_main(void){
    function0 _1698_t4;
    int64_t _1698_t3;
    int64_t _1698_$retval;
    _1698_t4 = (function0) _1696_f;
    $lines[$line_idx++] = "tests/integration/traits/non-virtual-no-params.orng:14:8:\n    x.>f()\n      ^";
    _1698_t3 = _1698_t4();
    $line_idx--;
    _1698_$retval = _1698_t3;
    return _1698_$retval;
}

int64_t _1696_f(void){
    int64_t _1696_$retval;
    _1696_$retval = 311;
    return _1696_$retval;
}


int main(void) {
  printf("%ld",_1698_main());
  return 0;
}
