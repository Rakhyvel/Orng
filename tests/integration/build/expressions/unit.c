/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef void(*function0)(void);

/* Function forward definitions */
int64_t _863_main(void);
void _865_f(void);

/* Function definitions */
int64_t _863_main(void){
    function0 _863_t0;
    int64_t _863_$retval;
    _863_t0 = _865_f;
    $lines[$line_idx++] = "tests/integration/expressions/unit.orng:3:7:\n    f()\n     ^";
    _863_t0();
    $line_idx--;
    _863_$retval = 48;
    return _863_$retval;
}

void _865_f(void){
    return;
}

int main(void) {
  printf("%ld",_863_main());
  return 0;
}
