/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef int64_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _605_main(void);
int64_t _607_return53(int64_t _607_x);

/* Function definitions */
int64_t _605_main(void) {
    function0 _605_t0;
    int64_t _605_t2;
    int64_t _605_t1;
    int64_t _605_$retval;
    _605_t0 = _607_return53;
    _605_t2 = 53;
    $lines[$line_idx++] = "tests/integration/functions/default-1arg.orng:3:14:\n    return53()\n            ^";
    _605_t1 = _605_t0(_605_t2);
    $line_idx--;
    _605_$retval = _605_t1;
    return _605_$retval;
}

int64_t _607_return53(int64_t _607_x) {
    int64_t _607_$retval;
    _607_$retval = _607_x;
    return _607_$retval;
}

int main(void) {
  printf("%ld",_605_main());
  return 0;
}
