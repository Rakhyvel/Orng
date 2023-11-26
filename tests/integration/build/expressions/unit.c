/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef void(*function0)(void);

/* Function forward definitions */
int64_t _267_main(void);
void _269_f(void);

/* Function definitions */
int64_t _267_main(void) {
    function0 _267_t0;
    int64_t _267_$retval;
    _267_t0 = _269_f;
    $lines[$line_idx++] = "tests/integration/expressions/unit.orng:3:7:\n    f()\n     ^";
    _267_t0();
    $line_idx--;
    _267_$retval = 48;
    return _267_$retval;
}

void _269_f(void) {
}

int main(void) {
  printf("%ld",_267_main());
  return 0;
}
