/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef int64_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _908_main(void);
int64_t _910_return53(int64_t _910_x);

/* Function definitions */
int64_t _908_main(void){
    function0 _908_t0;
    int64_t _908_t2;
    int64_t _908_t1;
    int64_t _908_$retval;
    _908_t0 = _910_return53;
    _908_t2 = 53;
    $lines[$line_idx++] = "tests/integration/functions/default-1arg.orng:3:14:\n    return53()\n            ^";
    _908_t1 = _908_t0(_908_t2);
    $line_idx--;
    _908_$retval = _908_t1;
    return _908_$retval;
}

int64_t _910_return53(int64_t _910_x){
    int64_t _910_$retval;
    _910_$retval = _910_x;
    return _910_$retval;
}

int main(void) {
  printf("%ld",_908_main());
  return 0;
}
