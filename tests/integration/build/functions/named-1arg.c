/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef int64_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _894_main(void);
int64_t _896_id(int64_t _896_x);

/* Function definitions */
int64_t _894_main(void) {
    function0 _894_t0;
    int64_t _894_t2;
    int64_t _894_t1;
    int64_t _894_$retval;
    _894_t0 = _896_id;
    _894_t2 = 52;
    $lines[$line_idx++] = "tests/integration/functions/named-1arg.orng:3:8:\n    id(.x = 52)\n      ^";
    _894_t1 = _894_t0(_894_t2);
    $line_idx--;
    _894_$retval = _894_t1;
    return _894_$retval;
}

int64_t _896_id(int64_t _896_x) {
    int64_t _896_$retval;
    _896_$retval = _896_x;
    return _896_$retval;
}

int main(void) {
  printf("%ld",_894_main());
  return 0;
}
