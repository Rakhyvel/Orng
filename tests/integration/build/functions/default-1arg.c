/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef int64_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _934_main(void);
int64_t _936_return53(int64_t _936_x);

/* Function definitions */
int64_t _934_main(void){
    function0 _934_t0;
    int64_t _934_t2;
    int64_t _934_t1;
    int64_t _934_$retval;
    _934_t0 = _936_return53;
    _934_t2 = 53;
    $lines[$line_idx++] = "tests/integration/functions/default-1arg.orng:3:14:\n    return53()\n            ^";
    _934_t1 = _934_t0(_934_t2);
    $line_idx--;
    _934_$retval = _934_t1;
    return _934_$retval;
}

int64_t _936_return53(int64_t _936_x){
    int64_t _936_$retval;
    _936_$retval = _936_x;
    return _936_$retval;
}

int main(void) {
  printf("%ld",_934_main());
  return 0;
}
