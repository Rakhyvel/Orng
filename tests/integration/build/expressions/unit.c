/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward typedefs */

/* Typedefs */
typedef void(*function0)(void);

/* Function forward definitions */
int64_t _914_main(void);
void _916_f(void);

/* Function definitions */
int64_t _914_main(void){
    function0 _914_t0;
    int64_t _914_$retval;
    _914_t0 = _916_f;
    $lines[$line_idx++] = "tests/integration/expressions/unit.orng:3:7:\n    f()\n     ^";
    _914_t0();
    $line_idx--;
    _914_$retval = 48;
    return _914_$retval;
}

void _916_f(void){
    return;
}

int main(void) {
  printf("%ld",_914_main());
  return 0;
}
