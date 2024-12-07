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
int64_t _1710_get(void);

/* Trait vtable implementations */

/* Function definitions */
int64_t _1705_main(void){
    function0 _1705_t6;
    int64_t _1705_t5;
    int64_t _1705_$retval;
    _1705_t6 = (function0) _1710_get;
    $lines[$line_idx++] = "tests/integration/traits/inner-trait.orng:13:8:\n    x.>get()\n      ^";
    _1705_t5 = _1705_t6();
    $line_idx--;
    _1705_$retval = _1705_t5;
    return _1705_$retval;
}

int64_t _1710_get(void){
    int64_t _1710_$retval;
    _1710_$retval = 322;
    return _1710_$retval;
}


int main(void) {
  printf("%ld",_1705_main());
  return 0;
}
