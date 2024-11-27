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
int64_t _1675_main(void);
int64_t _1680_get(void);

/* Trait vtable implementations */

/* Function definitions */
int64_t _1675_main(void){
    function0 _1675_t6;
    int64_t _1675_t5;
    int64_t _1675_$retval;
    _1675_t6 = (function0) _1680_get;
    $lines[$line_idx++] = "tests/integration/traits/inner-trait.orng:13:8:\n    x.>get()\n      ^";
    _1675_t5 = _1675_t6();
    $line_idx--;
    _1675_$retval = _1675_t5;
    return _1675_$retval;
}

int64_t _1680_get(void){
    int64_t _1680_$retval;
    _1680_$retval = 322;
    return _1680_$retval;
}


int main(void) {
  printf("%ld",_1675_main());
  return 0;
}
