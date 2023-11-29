/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef int64_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _708_main(void);
int64_t _710_return53(int64_t _710_x);

/* Function definitions */
int64_t _708_main(void) {
    function0 _708_t0;
    int64_t _708_t2;
    int64_t _708_t1;
    int64_t _708_$retval;
    _708_t0 = _710_return53;
    _708_t2 = 53;
    $lines[$line_idx++] = "tests/integration/functions/default-1arg.orng:3:14:\n    return53()\n            ^";
    _708_t1 = _708_t0(_708_t2);
    $line_idx--;
    _708_$retval = _708_t1;
    return _708_$retval;
}

int64_t _710_return53(int64_t _710_x) {
    int64_t _710_$retval;
    _710_$retval = _710_x;
    return _710_$retval;
}

int main(void) {
  printf("%ld",_708_main());
  return 0;
}
