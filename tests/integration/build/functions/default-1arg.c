/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef int64_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _719_main(void);
int64_t _721_return53(int64_t _721_x);

/* Function definitions */
int64_t _719_main(void) {
    function0 _719_t0;
    int64_t _719_t2;
    int64_t _719_t1;
    int64_t _719_$retval;
    _719_t0 = _721_return53;
    _719_t2 = 53;
    $lines[$line_idx++] = "tests/integration/functions/default-1arg.orng:3:14:\n    return53()\n            ^";
    _719_t1 = _719_t0(_719_t2);
    $line_idx--;
    _719_$retval = _719_t1;
    return _719_$retval;
}

int64_t _721_return53(int64_t _721_x) {
    int64_t _721_$retval;
    _721_$retval = _721_x;
    return _721_$retval;
}

int main(void) {
  printf("%ld",_719_main());
  return 0;
}
