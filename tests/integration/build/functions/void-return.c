/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef void(*function0)(void);

/* Function forward definitions */
int64_t _75_main(void);
void _77_void(void);

/* Function definitions */
int64_t _75_main(void) {
    function0 _75_t0;
    int64_t _75_$retval;
    _75_t0 = _77_void;
    $lines[$line_idx++] = "tests/integration/functions/void-return.orng:3:10:\n    void()\n        ^";
    _75_t0();
    $line_idx--;
    _75_$retval = 65;
    return _75_$retval;
}

void _77_void(void) {
}

int main(void) {
  printf("%ld",_75_main());
  return 0;
}
