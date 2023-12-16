/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef int64_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _911_main(void);
int64_t _913_id(int64_t _913_x);

/* Function definitions */
int64_t _911_main(void) {
    function0 _911_t0;
    int64_t _911_t2;
    int64_t _911_t1;
    int64_t _911_$retval;
    _911_t0 = _913_id;
    _911_t2 = 52;
    $lines[$line_idx++] = "tests/integration/functions/named-1arg.orng:3:8:\n    id(.x = 52)\n      ^";
    _911_t1 = _911_t0(_911_t2);
    $line_idx--;
    _911_$retval = _911_t1;
    return _911_$retval;
}

int64_t _913_id(int64_t _913_x) {
    int64_t _913_$retval;
    _913_$retval = _913_x;
    return _913_$retval;
}

int main(void) {
  printf("%ld",_911_main());
  return 0;
}
