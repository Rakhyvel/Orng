/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef int64_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _889_main(void);
int64_t _891_return53(int64_t _891_x);

/* Function definitions */
int64_t _889_main(void) {
    function0 _889_t0;
    int64_t _889_t2;
    int64_t _889_t1;
    int64_t _889_$retval;
    _889_t0 = _891_return53;
    _889_t2 = 53;
    $lines[$line_idx++] = "tests/integration/functions/default-1arg.orng:3:14:\n    return53()\n            ^";
    _889_t1 = _889_t0(_889_t2);
    $line_idx--;
    _889_$retval = _889_t1;
    return _889_$retval;
}

int64_t _891_return53(int64_t _891_x) {
    int64_t _891_$retval;
    _891_$retval = _891_x;
    return _891_$retval;
}

int main(void) {
  printf("%ld",_889_main());
  return 0;
}
