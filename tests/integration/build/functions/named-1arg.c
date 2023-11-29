/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef int64_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _892_main(void);
int64_t _894_id(int64_t _894_x);

/* Function definitions */
int64_t _892_main(void) {
    function0 _892_t0;
    int64_t _892_t2;
    int64_t _892_t1;
    int64_t _892_$retval;
    _892_t0 = _894_id;
    _892_t2 = 52;
    $lines[$line_idx++] = "tests/integration/functions/named-1arg.orng:3:8:\n    id(.x = 52)\n      ^";
    _892_t1 = _892_t0(_892_t2);
    $line_idx--;
    _892_$retval = _892_t1;
    return _892_$retval;
}

int64_t _894_id(int64_t _894_x) {
    int64_t _894_$retval;
    _894_$retval = _894_x;
    return _894_$retval;
}

int main(void) {
  printf("%ld",_892_main());
  return 0;
}
