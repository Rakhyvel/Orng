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
int64_t _82_main(void);
int64_t _80_f(void);

/* Trait vtable implementations */

/* Function definitions */
int64_t _82_main(void){
    function0 _82_t4;
    int64_t _82_t3;
    int64_t _82_$retval;
    _82_t4 = (function0) _80_f;
    $lines[$line_idx++] = "tests/integration/traits/non-virtual-no-params.orng:14:8:\n    x.>f()\n      ^";
    _82_t3 = _82_t4();
    $line_idx--;
    _82_$retval = _82_t3;
    return _82_$retval;
}

int64_t _80_f(void){
    int64_t _80_$retval;
    _80_$retval = 311;
    return _80_$retval;
}


int main(void) {
  printf("%ld",_82_main());
  return 0;
}
