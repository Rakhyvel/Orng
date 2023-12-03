/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef void(*function0)(void);

/* Function forward definitions */
int64_t _636_main(void);
void _638_f(void);

/* Function definitions */
int64_t _636_main(void) {
    function0 _636_t0;
    int64_t _636_$retval;
    _636_t0 = _638_f;
    $lines[$line_idx++] = "tests/integration/expressions/unit.orng:3:7:\n    f()\n     ^";
    _636_t0();
    $line_idx--;
    _636_$retval = 48;
    return _636_$retval;
}

void _638_f(void) {
    return;
}

int main(void) {
  printf("%ld",_636_main());
  return 0;
}
