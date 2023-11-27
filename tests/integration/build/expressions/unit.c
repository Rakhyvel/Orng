/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef void(*function0)(void);

/* Function forward definitions */
int64_t _603_main(void);
void _605_f(void);

/* Function definitions */
int64_t _603_main(void) {
    function0 _603_t0;
    int64_t _603_$retval;
    _603_t0 = _605_f;
    $lines[$line_idx++] = "tests/integration/expressions/unit.orng:3:7:\n    f()\n     ^";
    _603_t0();
    $line_idx--;
    _603_$retval = 48;
    return _603_$retval;
}

void _605_f(void) {
}

int main(void) {
  printf("%ld",_603_main());
  return 0;
}
