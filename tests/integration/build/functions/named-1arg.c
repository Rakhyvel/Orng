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
int64_t _972_main(void);
int64_t _974_id(int64_t _974_x);

/* Function definitions */
int64_t _972_main(void){
    function0 _972_t0;
    int64_t _972_t2;
    int64_t _972_t1;
    int64_t _972_$retval;
    _972_t0 = _974_id;
    _972_t2 = 52;
    $lines[$line_idx++] = "tests/integration/functions/named-1arg.orng:3:8:\n    id(.x = 52)\n      ^";
    _972_t1 = _972_t0(_972_t2);
    $line_idx--;
    _972_$retval = _972_t1;
    return _972_$retval;
}

int64_t _974_id(int64_t _974_x){
    int64_t _974_$retval;
    _974_$retval = _974_x;
    return _974_$retval;
}

int main(void) {
  printf("%ld",_972_main());
  return 0;
}
