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
int64_t _1027_main(void);
void _1029_void(void);


/* Function definitions */
int64_t _1027_main(void){
    function0 _1027_t0;
    int64_t _1027_$retval;
    _1027_t0 = (function0) _1029_void;
    $lines[$line_idx++] = "tests/integration/functions/void-return.orng:3:10:\n    void()\n        ^";
    (void) _1027_t0();
    $line_idx--;
    _1027_$retval = 65;
    return _1027_$retval;
}

void _1029_void(void){
    return;
}


int main(void) {
  printf("%ld",_1027_main());
  return 0;
}
