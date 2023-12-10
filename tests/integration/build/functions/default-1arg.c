/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef int64_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _692_main(void);
int64_t _694_return53(int64_t _694_x);

/* Function definitions */
int64_t _692_main(void) {
    function0 _692_t0;
    int64_t _692_t2;
    int64_t _692_t1;
    int64_t _692_$retval;
    _692_t0 = _694_return53;
    _692_t2 = 53;
    $lines[$line_idx++] = "tests/integration/functions/default-1arg.orng:3:14:\n    return53()\n            ^";
    _692_t1 = _692_t0(_692_t2);
    $line_idx--;
    _692_$retval = _692_t1;
    return _692_$retval;
}

int64_t _694_return53(int64_t _694_x) {
    int64_t _694_$retval;
    _694_$retval = _694_x;
    return _694_$retval;
}

int main(void) {
  printf("%ld",_692_main());
  return 0;
}
