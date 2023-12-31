/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward typedefs */

/* Typedefs */
typedef int64_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _969_main(void);
int64_t _971_id(int64_t _971_x);

/* Function definitions */
int64_t _969_main(void){
    function0 _969_t0;
    int64_t _969_t2;
    int64_t _969_t1;
    int64_t _969_$retval;
    _969_t0 = _971_id;
    _969_t2 = 52;
    $lines[$line_idx++] = "tests/integration/functions/named-1arg.orng:3:8:\n    id(.x = 52)\n      ^";
    _969_t1 = _969_t0(_969_t2);
    $line_idx--;
    _969_$retval = _969_t1;
    return _969_$retval;
}

int64_t _971_id(int64_t _971_x){
    int64_t _971_$retval;
    _971_$retval = _971_x;
    return _971_$retval;
}

int main(void) {
  printf("%ld",_969_main());
  return 0;
}
