/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef void(*function0)(void);

/* Function forward definitions */
int64_t _935_main(void);
void _937_void(void);

/* Function definitions */
int64_t _935_main(void) {
    function0 _935_t0;
    int64_t _935_$retval;
    _935_t0 = _937_void;
    $lines[$line_idx++] = "tests/integration/functions/void-return.orng:3:10:\n    void()\n        ^";
    _935_t0();
    $line_idx--;
    _935_$retval = 65;
    return _935_$retval;
}

void _937_void(void) {
}

int main(void) {
  printf("%ld",_935_main());
  return 0;
}
