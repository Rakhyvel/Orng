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
int64_t _1705_main(void);
int64_t _1703_f(void);

/* Trait vtable implementations */

/* Function definitions */
int64_t _1705_main(void){
    function0 _1705_t4;
    int64_t _1705_t3;
    int64_t _1705_$retval;
    _1705_t4 = (function0) _1703_f;
    $lines[$line_idx++] = "tests/integration/traits/non-virtual-no-params.orng:14:8:\n    x.>f()\n      ^";
    _1705_t3 = _1705_t4();
    $line_idx--;
    _1705_$retval = _1705_t3;
    return _1705_$retval;
}

int64_t _1703_f(void){
    int64_t _1703_$retval;
    _1703_$retval = 311;
    return _1703_$retval;
}


int main(void) {
  printf("%ld",_1705_main());
  return 0;
}
