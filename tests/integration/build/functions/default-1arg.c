/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef int64_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _1053_main(void);
int64_t _1055_return53(int64_t _1055_x);

/* Function definitions */
int64_t _1053_main(void){
    function0 _1053_t0;
    int64_t _1053_t2;
    int64_t _1053_t1;
    int64_t _1053_$retval;
    _1053_t0 = _1055_return53;
    _1053_t2 = 53;
    $lines[$line_idx++] = "tests/integration/functions/default-1arg.orng:3:14:\n    return53()\n            ^";
    _1053_t1 = _1053_t0(_1053_t2);
    $line_idx--;
    _1053_$retval = _1053_t1;
    return _1053_$retval;
}

int64_t _1055_return53(int64_t _1055_x){
    int64_t _1055_$retval;
    _1055_$retval = _1055_x;
    return _1055_$retval;
}

int main(void) {
  printf("%ld",_1053_main());
  return 0;
}
