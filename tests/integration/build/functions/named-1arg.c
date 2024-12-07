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
int64_t _994_main(void);
int64_t _996_id(int64_t _996_x);


/* Function definitions */
int64_t _994_main(void){
    function0 _994_t0;
    int64_t _994_t2;
    int64_t _994_t1;
    int64_t _994_$retval;
    _994_t0 = (function0) _996_id;
    _994_t2 = 52;
    $lines[$line_idx++] = "tests/integration/functions/named-1arg.orng:3:8:\n    id(.x = 52)\n      ^";
    _994_t1 = _994_t0(_994_t2);
    $line_idx--;
    _994_$retval = _994_t1;
    return _994_$retval;
}

int64_t _996_id(int64_t _996_x){
    int64_t _996_$retval;
    goto BB1174;
BB1174:
    _996_$retval = _996_x;
    return _996_$retval;
}


int main(void) {
  printf("%ld",_994_main());
  return 0;
}
