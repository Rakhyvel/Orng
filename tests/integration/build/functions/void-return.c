/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef void(*function0)(void);

/* Function forward definitions */
int64_t _955_main(void);
void _957_void(void);

/* Function definitions */
int64_t _955_main(void){
    function0 _955_t0;
    int64_t _955_$retval;
    _955_t0 = _957_void;
    $lines[$line_idx++] = "tests/integration/functions/void-return.orng:3:10:\n    void()\n        ^";
    _955_t0();
    $line_idx--;
    _955_$retval = 65;
    return _955_$retval;
}

void _957_void(void){
    return;
}

int main(void) {
  printf("%ld",_955_main());
  return 0;
}
