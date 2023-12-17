/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef void(*function0)(void);

/* Function forward definitions */
int64_t _1019_main(void);
void _1021_f(void);

/* Function definitions */
int64_t _1019_main(void){
    function0 _1019_t0;
    int64_t _1019_$retval;
    _1019_t0 = _1021_f;
    $lines[$line_idx++] = "tests/integration/expressions/unit.orng:3:7:\n    f()\n     ^";
    _1019_t0();
    $line_idx--;
    _1019_$retval = 48;
    return _1019_$retval;
}

void _1021_f(void){
    return;
}

int main(void) {
  printf("%ld",_1019_main());
  return 0;
}
