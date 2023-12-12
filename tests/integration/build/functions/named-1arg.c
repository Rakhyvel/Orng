/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef int64_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _741_main(void);
int64_t _743_id(int64_t _743_x);

/* Function definitions */
int64_t _741_main(void) {
    function0 _741_t0;
    int64_t _741_t2;
    int64_t _741_t1;
    int64_t _741_$retval;
    _741_t0 = _743_id;
    _741_t2 = 52;
    $lines[$line_idx++] = "tests/integration/functions/named-1arg.orng:3:8:\n    id(.x = 52)\n      ^";
    _741_t1 = _741_t0(_741_t2);
    $line_idx--;
    _741_$retval = _741_t1;
    return _741_$retval;
}

int64_t _743_id(int64_t _743_x) {
    int64_t _743_$retval;
    _743_$retval = _743_x;
    return _743_$retval;
}

int main(void) {
  printf("%ld",_741_main());
  return 0;
}
