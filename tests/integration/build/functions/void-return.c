/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward struct, union, and function declarations */

/* Struct, union, and function definitions */
typedef void(*function0)(void);

/* Function forward definitions */
int64_t _1013_main(void);
void _1015_void(void);


/* Function definitions */
int64_t _1013_main(void){
    function0 _1013_t0;
    int64_t _1013_$retval;
    _1013_t0 = (function0) _1015_void;
    $lines[$line_idx++] = "tests/integration/functions/void-return.orng:3:10:\n    void()\n        ^";
    (void) _1013_t0();
    $line_idx--;
    _1013_$retval = 65;
    return _1013_$retval;
}

void _1015_void(void){
    return;
}


int main(void) {
  printf("%ld",_1013_main());
  return 0;
}
