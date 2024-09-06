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
int64_t _1686_main(void);
int64_t _1684_f(void);

/* Trait vtable implementations */

/* Function definitions */
int64_t _1686_main(void){
    function0 _1686_t4;
    int64_t _1686_t3;
    int64_t _1686_$retval;
    _1686_t4 = (function0) _1684_f;
    $lines[$line_idx++] = "tests/integration/traits/non-virtual-no-params.orng:14:8:\n    x.>f()\n      ^";
    _1686_t3 = _1686_t4();
    $line_idx--;
    _1686_$retval = _1686_t3;
    return _1686_$retval;
}

int64_t _1684_f(void){
    int64_t _1684_$retval;
    _1684_$retval = 311;
    return _1684_$retval;
}


int main(void) {
  printf("%ld",_1686_main());
  return 0;
}
