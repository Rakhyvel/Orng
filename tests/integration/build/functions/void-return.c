/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef void(*function0)(void);

/* Function forward definitions */
int64_t _773_main(void);
void _775_void(void);

/* Function definitions */
int64_t _773_main(void) {
    function0 _773_t0;
    int64_t _773_$retval;
    _773_t0 = _775_void;
    $lines[$line_idx++] = "tests/integration/functions/void-return.orng:3:10:\n    void()\n        ^";
    _773_t0();
    $line_idx--;
    _773_$retval = 65;
    return _773_$retval;
}

void _775_void(void) {
    return;
}

int main(void) {
  printf("%ld",_773_main());
  return 0;
}
