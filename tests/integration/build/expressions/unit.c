/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef void(*function0)(void);

/* Function forward definitions */
int64_t _1026_main(void);
void _1028_f(void);

/* Function definitions */
int64_t _1026_main(void){
    function0 _1026_t0;
    int64_t _1026_$retval;
    _1026_t0 = _1028_f;
    $lines[$line_idx++] = "tests/integration/expressions/unit.orng:3:7:\n    f()\n     ^";
    _1026_t0();
    $line_idx--;
    _1026_$retval = 48;
    return _1026_$retval;
}

void _1028_f(void){
    return;
}

int main(void) {
  printf("%ld",_1026_main());
  return 0;
}
