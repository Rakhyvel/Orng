/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef int64_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _722_main(void);
int64_t _724_id(int64_t _724_x);

/* Function definitions */
int64_t _722_main(void) {
    function0 _722_t0;
    int64_t _722_t2;
    int64_t _722_t1;
    int64_t _722_$retval;
    _722_t0 = _724_id;
    _722_t2 = 52;
    $lines[$line_idx++] = "tests/integration/functions/named-1arg.orng:3:8:\n    id(.x = 52)\n      ^";
    _722_t1 = _722_t0(_722_t2);
    $line_idx--;
    _722_$retval = _722_t1;
    return _722_$retval;
}

int64_t _724_id(int64_t _724_x) {
    int64_t _724_$retval;
    _724_$retval = _724_x;
    return _724_$retval;
}

int main(void) {
  printf("%ld",_722_main());
  return 0;
}
