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
int64_t _999_main(void);
int64_t _1001_id(int64_t _1001_x);


/* Function definitions */
int64_t _999_main(void){
    function0 _999_t0;
    int64_t _999_t2;
    int64_t _999_t1;
    int64_t _999_$retval;
    _999_t0 = (function0) _1001_id;
    _999_t2 = 52;
    $lines[$line_idx++] = "tests/integration/functions/named-1arg.orng:3:8:\n    id(.x = 52)\n      ^";
    _999_t1 = _999_t0(_999_t2);
    $line_idx--;
    _999_$retval = _999_t1;
    return _999_$retval;
}

int64_t _1001_id(int64_t _1001_x){
    int64_t _1001_$retval;
    goto BB1177;
BB1177:
    _1001_$retval = _1001_x;
    return _1001_$retval;
}


int main(void) {
  printf("%ld",_999_main());
  return 0;
}
