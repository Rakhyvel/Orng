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
int64_t _986_main(void);
int64_t _988_id(int64_t _988_x);


/* Function definitions */
int64_t _986_main(void){
    function0 _986_t0;
    int64_t _986_t2;
    int64_t _986_t1;
    int64_t _986_$retval;
    _986_t0 = (function0) _988_id;
    _986_t2 = 52;
    $lines[$line_idx++] = "tests/integration/functions/named-1arg.orng:3:8:\n    id(.x = 52)\n      ^";
    _986_t1 = _986_t0(_986_t2);
    $line_idx--;
    _986_$retval = _986_t1;
    return _986_$retval;
}

int64_t _988_id(int64_t _988_x){
    int64_t _988_$retval;
    goto BB1164;
BB1164:
    _988_$retval = _988_x;
    return _988_$retval;
}


int main(void) {
  printf("%ld",_986_main());
  return 0;
}
