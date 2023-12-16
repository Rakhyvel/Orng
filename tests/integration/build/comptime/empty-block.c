/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef int64_t(*function0)(void);

/* Function forward definitions */
int64_t _210_main(void);
int64_t _213_f(void);

/* Function definitions */
int64_t _210_main(void){
    function0 _210_t0;
    int64_t _210_t1;
    int64_t _210_$retval;
    _210_t0 = _213_f;
    $lines[$line_idx++] = "tests/integration/comptime/empty-block.orng:3:7:\n    f(comptime {})\n     ^";
    _210_t1 = _210_t0();
    $line_idx--;
    _210_$retval = _210_t1;
    return _210_$retval;
}

int64_t _213_f(void){
    int64_t _213_$retval;
    _213_$retval = 262;
    return _213_$retval;
}

int main(void) {
  printf("%ld",_210_main());
  return 0;
}
