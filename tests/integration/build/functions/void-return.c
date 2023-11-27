/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef void(*function0)(void);

/* Function forward definitions */
int64_t _690_main(void);
void _692_void(void);

/* Function definitions */
int64_t _690_main(void) {
    function0 _690_t0;
    int64_t _690_$retval;
    _690_t0 = _692_void;
    $lines[$line_idx++] = "tests/integration/functions/void-return.orng:3:10:\n    void()\n        ^";
    _690_t0();
    $line_idx--;
    _690_$retval = 65;
    return _690_$retval;
}

void _692_void(void) {
}

int main(void) {
  printf("%ld",_690_main());
  return 0;
}
