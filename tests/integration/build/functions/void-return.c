/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward typedefs */

/* Typedefs */
typedef void(*function0)(void);

/* Function forward definitions */
int64_t _1015_main(void);
void _1017_void(void);

/* Function definitions */
int64_t _1015_main(void){
    function0 _1015_t0;
    int64_t _1015_$retval;
    _1015_t0 = _1017_void;
    $lines[$line_idx++] = "tests/integration/functions/void-return.orng:3:10:\n    void()\n        ^";
    (void) _1015_t0();
    $line_idx--;
    _1015_$retval = 65;
    return _1015_$retval;
}

void _1017_void(void){
    return;
}

int main(void) {
  printf("%ld",_1015_main());
  return 0;
}
