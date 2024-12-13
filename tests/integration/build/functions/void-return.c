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
int64_t _1049_main(void);
void _1051_void(void);


/* Function definitions */
int64_t _1049_main(void){
    function0 _1049_t0;
    int64_t _1049_$retval;
    _1049_t0 = (function0) _1051_void;
    $lines[$line_idx++] = "tests/integration/functions/void-return.orng:3:10:\n    void()\n        ^";
    (void) _1049_t0();
    $line_idx--;
    _1049_$retval = 65;
    return _1049_$retval;
}

void _1051_void(void){
    return;
}


int main(void) {
  printf("%ld",_1049_main());
  return 0;
}
