/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef int64_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _668_main(void);
int64_t _670_return53(int64_t _670_x);

/* Function definitions */
int64_t _668_main(void) {
    function0 _668_t0;
    int64_t _668_t2;
    int64_t _668_t1;
    int64_t _668_$retval;
    _668_t0 = _670_return53;
    _668_t2 = 53;
    $lines[$line_idx++] = "tests/integration/functions/default-1arg.orng:3:14:\n    return53()\n            ^";
    _668_t1 = _668_t0(_668_t2);
    $line_idx--;
    _668_$retval = _668_t1;
    return _668_$retval;
}

int64_t _670_return53(int64_t _670_x) {
    int64_t _670_$retval;
    _670_$retval = _670_x;
    return _670_$retval;
}

int main(void) {
  printf("%ld",_668_main());
  return 0;
}
