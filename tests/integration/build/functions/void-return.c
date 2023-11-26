/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef void(*function0)(void);

/* Function forward definitions */
int64_t _659_main(void);
void _661_void(void);

/* Function definitions */
int64_t _659_main(void) {
    function0 _659_t0;
    int64_t _659_$retval;
    _659_t0 = _661_void;
    $lines[$line_idx++] = "tests/integration/functions/void-return.orng:3:10:\n    void()\n        ^";
    _659_t0();
    $line_idx--;
    _659_$retval = 65;
    return _659_$retval;
}

void _661_void(void) {
}

int main(void) {
  printf("%ld",_659_main());
  return 0;
}
