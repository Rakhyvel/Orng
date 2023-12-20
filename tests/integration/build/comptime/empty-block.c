/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef int64_t(*function0)(void);

/* Function forward definitions */
int64_t _138_main(void);
int64_t _141_f(void);

/* Function definitions */
int64_t _138_main(void){
    function0 _138_t0;
    int64_t _138_t1;
    int64_t _138_$retval;
    _138_t0 = _141_f;
    $lines[$line_idx++] = "tests/integration/comptime/empty-block.orng:3:7:\n    f(comptime {})\n     ^";
    _138_t1 = _138_t0();
    $line_idx--;
    _138_$retval = _138_t1;
    return _138_$retval;
}

int64_t _141_f(void){
    int64_t _141_$retval;
    _141_$retval = 262;
    return _141_$retval;
}

int main(void) {
  printf("%ld",_138_main());
  return 0;
}
