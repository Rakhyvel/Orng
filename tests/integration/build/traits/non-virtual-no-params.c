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
int64_t _1621_main(void);
int64_t _1619_f(void);

/* Trait vtable implementations */

/* Function definitions */
int64_t _1621_main(void){
    function0 _1621_t4;
    int64_t _1621_t3;
    int64_t _1621_$retval;
    _1621_t4 = (function0) _1619_f;
    $lines[$line_idx++] = "tests/integration/traits/non-virtual-no-params.orng:14:8:\n    x.>f()\n      ^";
    _1621_t3 = _1621_t4();
    $line_idx--;
    _1621_$retval = _1621_t3;
    return _1621_$retval;
}

int64_t _1619_f(void){
    int64_t _1619_$retval;
    _1619_$retval = 311;
    return _1619_$retval;
}


int main(void) {
  printf("%ld",_1621_main());
  return 0;
}
