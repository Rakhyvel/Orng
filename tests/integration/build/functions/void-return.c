/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef void(*function0)(void);

/* Function forward definitions */
int64_t _754_main(void);
void _756_void(void);

/* Function definitions */
int64_t _754_main(void) {
    function0 _754_t0;
    int64_t _754_$retval;
    _754_t0 = _756_void;
    $lines[$line_idx++] = "tests/integration/functions/void-return.orng:3:10:\n    void()\n        ^";
    _754_t0();
    $line_idx--;
    _754_$retval = 65;
    return _754_$retval;
}

void _756_void(void) {
    return;
}

int main(void) {
  printf("%ld",_754_main());
  return 0;
}
