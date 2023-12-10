/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef void(*function0)(void);

/* Function forward definitions */
int64_t _746_main(void);
void _748_void(void);

/* Function definitions */
int64_t _746_main(void) {
    function0 _746_t0;
    int64_t _746_$retval;
    _746_t0 = _748_void;
    $lines[$line_idx++] = "tests/integration/functions/void-return.orng:3:10:\n    void()\n        ^";
    _746_t0();
    $line_idx--;
    _746_$retval = 65;
    return _746_$retval;
}

void _748_void(void) {
    return;
}

int main(void) {
  printf("%ld",_746_main());
  return 0;
}
