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
int64_t _87_main(void);
int64_t _92_get(void);

/* Trait vtable implementations */

/* Function definitions */
int64_t _87_main(void){
    function0 _87_t6;
    int64_t _87_t5;
    int64_t _87_$retval;
    _87_t6 = (function0) _92_get;
    $lines[$line_idx++] = "tests/integration/traits/inner-trait.orng:13:8:\n    x.>get()\n      ^";
    _87_t5 = _87_t6();
    $line_idx--;
    _87_$retval = _87_t5;
    return _87_$retval;
}

int64_t _92_get(void){
    int64_t _92_$retval;
    _92_$retval = 322;
    return _92_$retval;
}


int main(void) {
  printf("%ld",_87_main());
  return 0;
}
