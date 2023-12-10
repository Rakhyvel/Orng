/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef void(*function0)(void);

/* Function forward definitions */
int64_t _660_main(void);
void _662_f(void);

/* Function definitions */
int64_t _660_main(void) {
    function0 _660_t0;
    int64_t _660_$retval;
    _660_t0 = _662_f;
    $lines[$line_idx++] = "tests/integration/expressions/unit.orng:3:7:\n    f()\n     ^";
    _660_t0();
    $line_idx--;
    _660_$retval = 48;
    return _660_$retval;
}

void _662_f(void) {
    return;
}

int main(void) {
  printf("%ld",_660_main());
  return 0;
}
