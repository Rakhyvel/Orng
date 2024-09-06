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
int64_t _1677_main(void);
int64_t _1682_get(void);

/* Trait vtable implementations */

/* Function definitions */
int64_t _1677_main(void){
    function0 _1677_t6;
    int64_t _1677_t5;
    int64_t _1677_$retval;
    _1677_t6 = (function0) _1682_get;
    $lines[$line_idx++] = "tests/integration/traits/inner-trait.orng:13:8:\n    x.>get()\n      ^";
    _1677_t5 = _1677_t6();
    $line_idx--;
    _1677_$retval = _1677_t5;
    return _1677_$retval;
}

int64_t _1682_get(void){
    int64_t _1682_$retval;
    _1682_$retval = 322;
    return _1682_$retval;
}


int main(void) {
  printf("%ld",_1677_main());
  return 0;
}
