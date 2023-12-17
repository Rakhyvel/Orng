/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef int64_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _1075_main(void);
int64_t _1077_id(int64_t _1077_x);

/* Function definitions */
int64_t _1075_main(void){
    function0 _1075_t0;
    int64_t _1075_t2;
    int64_t _1075_t1;
    int64_t _1075_$retval;
    _1075_t0 = _1077_id;
    _1075_t2 = 52;
    $lines[$line_idx++] = "tests/integration/functions/named-1arg.orng:3:8:\n    id(.x = 52)\n      ^";
    _1075_t1 = _1075_t0(_1075_t2);
    $line_idx--;
    _1075_$retval = _1075_t1;
    return _1075_$retval;
}

int64_t _1077_id(int64_t _1077_x){
    int64_t _1077_$retval;
    _1077_$retval = _1077_x;
    return _1077_$retval;
}

int main(void) {
  printf("%ld",_1075_main());
  return 0;
}
