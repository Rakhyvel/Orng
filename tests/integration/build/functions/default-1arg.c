/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef int64_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _843_main(void);
int64_t _845_return53(int64_t _845_x);

/* Function definitions */
int64_t _843_main(void) {
    function0 _843_t0;
    int64_t _843_t2;
    int64_t _843_t1;
    int64_t _843_$retval;
    _843_t0 = _845_return53;
    _843_t2 = 53;
    $lines[$line_idx++] = "tests/integration/functions/default-1arg.orng:3:14:\n    return53()\n            ^";
    _843_t1 = _843_t0(_843_t2);
    $line_idx--;
    _843_$retval = _843_t1;
    return _843_$retval;
}

int64_t _845_return53(int64_t _845_x) {
    int64_t _845_$retval;
    _845_$retval = _845_x;
    return _845_$retval;
}

int main(void) {
  printf("%ld",_843_main());
  return 0;
}
