/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef int64_t(*function0)(void);

/* Function forward definitions */
int64_t _54_main(void);
int64_t _57_f(void);

/* Function definitions */
int64_t _54_main(void){
    function0 _54_t0;
    int64_t _54_t1;
    int64_t _54_$retval;
    _54_t0 = _57_f;
    $lines[$line_idx++] = "tests/integration/comptime/empty-block.orng:3:7:\n    f(comptime {})\n     ^";
    _54_t1 = _54_t0();
    $line_idx--;
    _54_$retval = _54_t1;
    return _54_$retval;
}

int64_t _57_f(void){
    int64_t _57_$retval;
    _57_$retval = 262;
    return _57_$retval;
}

int main(void) {
  printf("%ld",_54_main());
  return 0;
}
