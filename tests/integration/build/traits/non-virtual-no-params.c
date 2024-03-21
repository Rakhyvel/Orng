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
int64_t _1607_main(void);
int64_t _1605_f(void);

/* Trait vtable implementations */

/* Function definitions */
int64_t _1607_main(void){
    function0 _1607_t4;
    int64_t _1607_t3;
    int64_t _1607_$retval;
    _1607_t4 = (function0) _1605_f;
    $lines[$line_idx++] = "tests/integration/traits/non-virtual-no-params.orng:14:8:\n    x.>f()\n      ^";
    _1607_t3 = _1607_t4();
    $line_idx--;
    _1607_$retval = _1607_t3;
    return _1607_$retval;
}

int64_t _1605_f(void){
    int64_t _1605_$retval;
    _1605_$retval = 311;
    return _1605_$retval;
}


int main(void) {
  printf("%ld",_1607_main());
  return 0;
}
