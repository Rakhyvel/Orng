/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef int64_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _919_main(void);
int64_t _921_id(int64_t _921_x);

/* Function definitions */
int64_t _919_main(void){
    function0 _919_t0;
    int64_t _919_t2;
    int64_t _919_t1;
    int64_t _919_$retval;
    _919_t0 = _921_id;
    _919_t2 = 52;
    $lines[$line_idx++] = "tests/integration/functions/named-1arg.orng:3:8:\n    id(.x = 52)\n      ^";
    _919_t1 = _919_t0(_919_t2);
    $line_idx--;
    _919_$retval = _919_t1;
    return _919_$retval;
}

int64_t _921_id(int64_t _921_x){
    int64_t _921_$retval;
    _921_$retval = _921_x;
    return _921_$retval;
}

int main(void) {
  printf("%ld",_919_main());
  return 0;
}
