/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef void(*function0)(void);

/* Function forward definitions */
int64_t _675_main(void);
void _677_f(void);

/* Function definitions */
int64_t _675_main(void) {
    function0 _675_t0;
    int64_t _675_$retval;
    _675_t0 = _677_f;
    $lines[$line_idx++] = "tests/integration/expressions/unit.orng:3:7:\n    f()\n     ^";
    _675_t0();
    $line_idx--;
    _675_$retval = 48;
    return _675_$retval;
}

void _677_f(void) {
}

int main(void) {
  printf("%ld",_675_main());
  return 0;
}
