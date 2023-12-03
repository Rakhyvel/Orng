/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef int64_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _690_main(void);
int64_t _692_id(int64_t _692_x);

/* Function definitions */
int64_t _690_main(void) {
    function0 _690_t0;
    int64_t _690_t2;
    int64_t _690_t1;
    int64_t _690_$retval;
    _690_t0 = _692_id;
    _690_t2 = 52;
    $lines[$line_idx++] = "tests/integration/functions/named-1arg.orng:3:8:\n    id(.x = 52)\n      ^";
    _690_t1 = _690_t0(_690_t2);
    $line_idx--;
    _690_$retval = _690_t1;
    return _690_$retval;
}

int64_t _692_id(int64_t _692_x) {
    int64_t _692_$retval;
    _692_$retval = _692_x;
    return _692_$retval;
}

int main(void) {
  printf("%ld",_690_main());
  return 0;
}
