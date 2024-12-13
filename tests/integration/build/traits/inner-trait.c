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
int64_t _1727_main(void);
int64_t _1732_get(void);

/* Trait vtable implementations */

/* Function definitions */
int64_t _1727_main(void){
    function0 _1727_t6;
    int64_t _1727_t5;
    int64_t _1727_$retval;
    _1727_t6 = (function0) _1732_get;
    $lines[$line_idx++] = "tests/integration/traits/inner-trait.orng:13:8:\n    x.>get()\n      ^";
    _1727_t5 = _1727_t6();
    $line_idx--;
    _1727_$retval = _1727_t5;
    return _1727_$retval;
}

int64_t _1732_get(void){
    int64_t _1732_$retval;
    _1732_$retval = 322;
    return _1732_$retval;
}


int main(void) {
  printf("%ld",_1727_main());
  return 0;
}
