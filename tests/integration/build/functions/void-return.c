/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef void(*function0)(void);

/* Function forward definitions */
int64_t _722_main(void);
void _724_void(void);

/* Function definitions */
int64_t _722_main(void) {
    function0 _722_t0;
    int64_t _722_$retval;
    _722_t0 = _724_void;
    $lines[$line_idx++] = "tests/integration/functions/void-return.orng:3:10:\n    void()\n        ^";
    _722_t0();
    $line_idx--;
    _722_$retval = 65;
    return _722_$retval;
}

void _724_void(void) {
    return;
}

int main(void) {
  printf("%ld",_722_main());
  return 0;
}
