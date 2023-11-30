/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef void(*function0)(void);

/* Function forward definitions */
int64_t _912_main(void);
void _914_void(void);

/* Function definitions */
int64_t _912_main(void) {
    function0 _912_t0;
    int64_t _912_$retval;
    _912_t0 = _914_void;
    $lines[$line_idx++] = "tests/integration/functions/void-return.orng:3:10:\n    void()\n        ^";
    _912_t0();
    $line_idx--;
    _912_$retval = 65;
    return _912_$retval;
}

void _914_void(void) {
}

int main(void) {
  printf("%ld",_912_main());
  return 0;
}
