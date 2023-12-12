/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef void(*function0)(void);

/* Function forward definitions */
int64_t _668_main(void);
void _670_f(void);

/* Function definitions */
int64_t _668_main(void) {
    function0 _668_t0;
    int64_t _668_$retval;
    _668_t0 = _670_f;
    $lines[$line_idx++] = "tests/integration/expressions/unit.orng:3:7:\n    f()\n     ^";
    _668_t0();
    $line_idx--;
    _668_$retval = 48;
    return _668_$retval;
}

void _670_f(void) {
    return;
}

int main(void) {
  printf("%ld",_668_main());
  return 0;
}
