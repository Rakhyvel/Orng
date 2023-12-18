/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef int64_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _1083_main(void);
int64_t _1085_id(int64_t _1085_x);

/* Function definitions */
int64_t _1083_main(void){
    function0 _1083_t0;
    int64_t _1083_t2;
    int64_t _1083_t1;
    int64_t _1083_$retval;
    _1083_t0 = _1085_id;
    _1083_t2 = 52;
    $lines[$line_idx++] = "tests/integration/functions/named-1arg.orng:3:8:\n    id(.x = 52)\n      ^";
    _1083_t1 = _1083_t0(_1083_t2);
    $line_idx--;
    _1083_$retval = _1083_t1;
    return _1083_$retval;
}

int64_t _1085_id(int64_t _1085_x){
    int64_t _1085_$retval;
    _1085_$retval = _1085_x;
    return _1085_$retval;
}

int main(void) {
  printf("%ld",_1083_main());
  return 0;
}
