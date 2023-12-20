/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef void(*function0)(void);

/* Function forward definitions */
int64_t _989_main(void);
void _991_void(void);

/* Function definitions */
int64_t _989_main(void){
    function0 _989_t0;
    int64_t _989_$retval;
    _989_t0 = _991_void;
    $lines[$line_idx++] = "tests/integration/functions/void-return.orng:3:10:\n    void()\n        ^";
    _989_t0();
    $line_idx--;
    _989_$retval = 65;
    return _989_$retval;
}

void _991_void(void){
    return;
}

int main(void) {
  printf("%ld",_989_main());
  return 0;
}
