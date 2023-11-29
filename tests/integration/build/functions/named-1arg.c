/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef int64_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _730_main(void);
int64_t _732_id(int64_t _732_x);

/* Function definitions */
int64_t _730_main(void) {
    function0 _730_t0;
    int64_t _730_t2;
    int64_t _730_t1;
    int64_t _730_$retval;
    _730_t0 = _732_id;
    _730_t2 = 52;
    $lines[$line_idx++] = "tests/integration/functions/named-1arg.orng:3:8:\n    id(.x = 52)\n      ^";
    _730_t1 = _730_t0(_730_t2);
    $line_idx--;
    _730_$retval = _730_t1;
    return _730_$retval;
}

int64_t _732_id(int64_t _732_x) {
    int64_t _732_$retval;
    _732_$retval = _732_x;
    return _732_$retval;
}

int main(void) {
  printf("%ld",_730_main());
  return 0;
}
