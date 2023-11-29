/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef int64_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _864_main(void);
int64_t _866_return53(int64_t _866_x);

/* Function definitions */
int64_t _864_main(void) {
    function0 _864_t0;
    int64_t _864_t2;
    int64_t _864_t1;
    int64_t _864_$retval;
    _864_t0 = _866_return53;
    _864_t2 = 53;
    $lines[$line_idx++] = "tests/integration/functions/default-1arg.orng:3:14:\n    return53()\n            ^";
    _864_t1 = _864_t0(_864_t2);
    $line_idx--;
    _864_$retval = _864_t1;
    return _864_$retval;
}

int64_t _866_return53(int64_t _866_x) {
    int64_t _866_$retval;
    _866_$retval = _866_x;
    return _866_$retval;
}

int main(void) {
  printf("%ld",_864_main());
  return 0;
}
