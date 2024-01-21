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
int64_t _1020_main(void);
void _1022_void(void);

/* Function definitions */
int64_t _1020_main(void){
    function0 _1020_t0;
    int64_t _1020_$retval;
    _1020_t0 = _1022_void;
    $lines[$line_idx++] = "tests/integration/functions/void-return.orng:3:10:\n    void()\n        ^";
    (void) _1020_t0();
    $line_idx--;
    _1020_$retval = 65;
    return _1020_$retval;
}

void _1022_void(void){
    return;
}

int main(void) {
  printf("%ld",_1020_main());
  return 0;
}
