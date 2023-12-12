/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef void(*function0)(void);

/* Function forward definitions */
int64_t _687_main(void);
void _689_f(void);

/* Function definitions */
int64_t _687_main(void) {
    function0 _687_t0;
    int64_t _687_$retval;
    _687_t0 = _689_f;
    $lines[$line_idx++] = "tests/integration/expressions/unit.orng:3:7:\n    f()\n     ^";
    _687_t0();
    $line_idx--;
    _687_$retval = 48;
    return _687_$retval;
}

void _689_f(void) {
    return;
}

int main(void) {
  printf("%ld",_687_main());
  return 0;
}
