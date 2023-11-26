/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef int64_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _627_main(void);
int64_t _629_id(int64_t _629_x);

/* Function definitions */
int64_t _627_main(void) {
    function0 _627_t0;
    int64_t _627_t2;
    int64_t _627_t1;
    int64_t _627_$retval;
    _627_t0 = _629_id;
    _627_t2 = 52;
    $lines[$line_idx++] = "tests/integration/functions/named-1arg.orng:3:8:\n    id(.x = 52)\n      ^";
    _627_t1 = _627_t0(_627_t2);
    $line_idx--;
    _627_$retval = _627_t1;
    return _627_$retval;
}

int64_t _629_id(int64_t _629_x) {
    int64_t _629_$retval;
    _629_$retval = _629_x;
    return _629_$retval;
}

int main(void) {
  printf("%ld",_627_main());
  return 0;
}
