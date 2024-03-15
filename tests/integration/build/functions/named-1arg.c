/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward struct, union, and function declarations */

/* Struct, union, and function definitions */
typedef int64_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _980_main(void);
int64_t _982_id(int64_t _982_x);


/* Function definitions */
int64_t _980_main(void){
    function0 _980_t0;
    int64_t _980_t2;
    int64_t _980_t1;
    int64_t _980_$retval;
    _980_t0 = (function0) _982_id;
    _980_t2 = 52;
    $lines[$line_idx++] = "tests/integration/functions/named-1arg.orng:3:8:\n    id(.x = 52)\n      ^";
    _980_t1 = _980_t0(_980_t2);
    $line_idx--;
    _980_$retval = _980_t1;
    return _980_$retval;
}

int64_t _982_id(int64_t _982_x){
    int64_t _982_$retval;
    _982_$retval = _982_x;
    return _982_$retval;
}


int main(void) {
  printf("%ld",_980_main());
  return 0;
}
