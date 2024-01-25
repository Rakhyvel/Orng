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
int64_t _1047_main(void);
void _1049_void(void);


/* Function definitions */
int64_t _1047_main(void){
    function0 _1047_t0;
    int64_t _1047_$retval;
    _1047_t0 = _1049_void;
    $lines[$line_idx++] = "tests/integration/functions/void-return.orng:3:10:\n    void()\n        ^";
    (void) _1047_t0();
    $line_idx--;
    _1047_$retval = 65;
    return _1047_$retval;
}

void _1049_void(void){
    return;
}


int main(void) {
  printf("%ld",_1047_main());
  return 0;
}
