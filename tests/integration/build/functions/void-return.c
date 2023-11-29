/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef void(*function0)(void);

/* Function forward definitions */
int64_t _933_main(void);
void _935_void(void);

/* Function definitions */
int64_t _933_main(void) {
    function0 _933_t0;
    int64_t _933_$retval;
    _933_t0 = _935_void;
    $lines[$line_idx++] = "tests/integration/functions/void-return.orng:3:10:\n    void()\n        ^";
    _933_t0();
    $line_idx--;
    _933_$retval = 65;
    return _933_$retval;
}

void _935_void(void) {
}

int main(void) {
  printf("%ld",_933_main());
  return 0;
}
