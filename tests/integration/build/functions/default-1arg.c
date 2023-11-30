/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef int64_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _866_main(void);
int64_t _868_return53(int64_t _868_x);

/* Function definitions */
int64_t _866_main(void) {
    function0 _866_t0;
    int64_t _866_t2;
    int64_t _866_t1;
    int64_t _866_$retval;
    _866_t0 = _868_return53;
    _866_t2 = 53;
    $lines[$line_idx++] = "tests/integration/functions/default-1arg.orng:3:14:\n    return53()\n            ^";
    _866_t1 = _866_t0(_866_t2);
    $line_idx--;
    _866_$retval = _866_t1;
    return _866_$retval;
}

int64_t _868_return53(int64_t _868_x) {
    int64_t _868_$retval;
    _868_$retval = _868_x;
    return _868_$retval;
}

int main(void) {
  printf("%ld",_866_main());
  return 0;
}
