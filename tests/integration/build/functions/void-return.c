/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef void(*function0)(void);

/* Function forward definitions */
int64_t _947_main(void);
void _949_void(void);

/* Function definitions */
int64_t _947_main(void) {
    function0 _947_t0;
    int64_t _947_$retval;
    _947_t0 = _949_void;
    $lines[$line_idx++] = "tests/integration/functions/void-return.orng:3:10:\n    void()\n        ^";
    _947_t0();
    $line_idx--;
    _947_$retval = 65;
    return _947_$retval;
}

void _949_void(void) {
    return;
}

int main(void) {
  printf("%ld",_947_main());
  return 0;
}
