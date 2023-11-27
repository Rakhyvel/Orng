/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef int64_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _636_main(void);
int64_t _638_return53(int64_t _638_x);

/* Function definitions */
int64_t _636_main(void) {
    function0 _636_t0;
    int64_t _636_t2;
    int64_t _636_t1;
    int64_t _636_$retval;
    _636_t0 = _638_return53;
    _636_t2 = 53;
    $lines[$line_idx++] = "tests/integration/functions/default-1arg.orng:3:14:\n    return53()\n            ^";
    _636_t1 = _636_t0(_636_t2);
    $line_idx--;
    _636_$retval = _636_t1;
    return _636_$retval;
}

int64_t _638_return53(int64_t _638_x) {
    int64_t _638_$retval;
    _638_$retval = _638_x;
    return _638_$retval;
}

int main(void) {
  printf("%ld",_636_main());
  return 0;
}
