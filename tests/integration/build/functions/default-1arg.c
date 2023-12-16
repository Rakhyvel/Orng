/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef int64_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _897_main(void);
int64_t _899_return53(int64_t _899_x);

/* Function definitions */
int64_t _897_main(void){
    function0 _897_t0;
    int64_t _897_t2;
    int64_t _897_t1;
    int64_t _897_$retval;
    _897_t0 = _899_return53;
    _897_t2 = 53;
    $lines[$line_idx++] = "tests/integration/functions/default-1arg.orng:3:14:\n    return53()\n            ^";
    _897_t1 = _897_t0(_897_t2);
    $line_idx--;
    _897_$retval = _897_t1;
    return _897_$retval;
}

int64_t _899_return53(int64_t _899_x){
    int64_t _899_$retval;
    _899_$retval = _899_x;
    return _899_$retval;
}

int main(void) {
  printf("%ld",_897_main());
  return 0;
}
