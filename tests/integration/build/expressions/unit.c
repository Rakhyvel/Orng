/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef void(*function0)(void);

/* Function forward definitions */
int64_t _291_main(void);
void _293_f(void);

/* Function definitions */
int64_t _291_main(void) {
    function0 _291_t0;
    int64_t _291_$retval;
    _291_t0 = _293_f;
    $lines[$line_idx++] = "tests/integration/expressions/unit.orng:3:7:\n    f()\n     ^";
    _291_t0();
    $line_idx--;
    _291_$retval = 48;
    return _291_$retval;
}

void _293_f(void) {
    return;
}

int main(void) {
  printf("%ld",_291_main());
  return 0;
}
