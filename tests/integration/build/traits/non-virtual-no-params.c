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
int64_t _1713_main(void);
int64_t _1711_f(void);

/* Trait vtable implementations */

/* Function definitions */
int64_t _1713_main(void){
    function0 _1713_t4;
    int64_t _1713_t3;
    int64_t _1713_$retval;
    _1713_t4 = (function0) _1711_f;
    $lines[$line_idx++] = "tests/integration/traits/non-virtual-no-params.orng:14:8:\n    x.>f()\n      ^";
    _1713_t3 = _1713_t4();
    $line_idx--;
    _1713_$retval = _1713_t3;
    return _1713_$retval;
}

int64_t _1711_f(void){
    int64_t _1711_$retval;
    _1711_$retval = 311;
    return _1711_$retval;
}


int main(void) {
  printf("%ld",_1713_main());
  return 0;
}
