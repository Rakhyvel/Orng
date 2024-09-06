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
int64_t _1021_main(void);
void _1023_void(void);


/* Function definitions */
int64_t _1021_main(void){
    function0 _1021_t0;
    int64_t _1021_$retval;
    _1021_t0 = (function0) _1023_void;
    $lines[$line_idx++] = "tests/integration/functions/void-return.orng:3:10:\n    void()\n        ^";
    (void) _1021_t0();
    $line_idx--;
    _1021_$retval = 65;
    return _1021_$retval;
}

void _1023_void(void){
    return;
}


int main(void) {
  printf("%ld",_1021_main());
  return 0;
}
