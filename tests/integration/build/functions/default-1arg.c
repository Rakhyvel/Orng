/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef int64_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _700_main(void);
int64_t _702_return53(int64_t _702_x);

/* Function definitions */
int64_t _700_main(void) {
    function0 _700_t0;
    int64_t _700_t2;
    int64_t _700_t1;
    int64_t _700_$retval;
    _700_t0 = _702_return53;
    _700_t2 = 53;
    $lines[$line_idx++] = "tests/integration/functions/default-1arg.orng:3:14:\n    return53()\n            ^";
    _700_t1 = _700_t0(_700_t2);
    $line_idx--;
    _700_$retval = _700_t1;
    return _700_$retval;
}

int64_t _702_return53(int64_t _702_x) {
    int64_t _702_$retval;
    _702_$retval = _702_x;
    return _702_$retval;
}

int main(void) {
  printf("%ld",_700_main());
  return 0;
}
