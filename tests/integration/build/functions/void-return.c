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
int64_t _1005_main(void);
void _1007_void(void);

/* Function definitions */
int64_t _1005_main(void){
    function0 _1005_t0;
    int64_t _1005_$retval;
    _1005_t0 = _1007_void;
    $lines[$line_idx++] = "tests/integration/functions/void-return.orng:3:10:\n    void()\n        ^";
    (void) _1005_t0();
    $line_idx--;
    _1005_$retval = 65;
    return _1005_$retval;
}

void _1007_void(void){
    return;
}

int main(void) {
  printf("%ld",_1005_main());
  return 0;
}
