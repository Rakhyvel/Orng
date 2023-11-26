/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef void(*function0)(void);

/* Function forward definitions */
int64_t _572_main(void);
void _574_f(void);

/* Function definitions */
int64_t _572_main(void) {
    function0 _572_t0;
    int64_t _572_$retval;
    _572_t0 = _574_f;
    $lines[$line_idx++] = "tests/integration/expressions/unit.orng:3:7:\n    f()\n     ^";
    _572_t0();
    $line_idx--;
    _572_$retval = 48;
    return _572_$retval;
}

void _574_f(void) {
}

int main(void) {
  printf("%ld",_572_main());
  return 0;
}
