/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef int64_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _1060_main(void);
int64_t _1062_return53(int64_t _1062_x);

/* Function definitions */
int64_t _1060_main(void){
    function0 _1060_t0;
    int64_t _1060_t2;
    int64_t _1060_t1;
    int64_t _1060_$retval;
    _1060_t0 = _1062_return53;
    _1060_t2 = 53;
    $lines[$line_idx++] = "tests/integration/functions/default-1arg.orng:3:14:\n    return53()\n            ^";
    _1060_t1 = _1060_t0(_1060_t2);
    $line_idx--;
    _1060_$retval = _1060_t1;
    return _1060_$retval;
}

int64_t _1062_return53(int64_t _1062_x){
    int64_t _1062_$retval;
    _1062_$retval = _1062_x;
    return _1062_$retval;
}

int main(void) {
  printf("%ld",_1060_main());
  return 0;
}
