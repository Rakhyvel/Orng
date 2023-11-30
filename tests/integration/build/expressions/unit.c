/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef void(*function0)(void);

/* Function forward definitions */
int64_t _826_main(void);
void _828_f(void);

/* Function definitions */
int64_t _826_main(void) {
    function0 _826_t0;
    int64_t _826_$retval;
    _826_t0 = _828_f;
    $lines[$line_idx++] = "tests/integration/expressions/unit.orng:3:7:\n    f()\n     ^";
    _826_t0();
    $line_idx--;
    _826_$retval = 48;
    return _826_$retval;
}

void _828_f(void) {
}

int main(void) {
  printf("%ld",_826_main());
  return 0;
}
