/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef void(*function0)(void);

/* Function forward definitions */
int64_t _934_main(void);
void _936_f(void);

/* Function definitions */
int64_t _934_main(void){
    function0 _934_t0;
    int64_t _934_$retval;
    _934_t0 = _936_f;
    $lines[$line_idx++] = "tests/integration/expressions/unit.orng:3:7:\n    f()\n     ^";
    _934_t0();
    $line_idx--;
    _934_$retval = 48;
    return _934_$retval;
}

void _936_f(void){
    return;
}

int main(void) {
  printf("%ld",_934_main());
  return 0;
}
