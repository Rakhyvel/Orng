/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef int64_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _871_main(void);
int64_t _873_id(int64_t _873_x);

/* Function definitions */
int64_t _871_main(void) {
    function0 _871_t0;
    int64_t _871_t2;
    int64_t _871_t1;
    int64_t _871_$retval;
    _871_t0 = _873_id;
    _871_t2 = 52;
    $lines[$line_idx++] = "tests/integration/functions/named-1arg.orng:3:8:\n    id(.x = 52)\n      ^";
    _871_t1 = _871_t0(_871_t2);
    $line_idx--;
    _871_$retval = _871_t1;
    return _871_$retval;
}

int64_t _873_id(int64_t _873_x) {
    int64_t _873_$retval;
    _873_$retval = _873_x;
    return _873_$retval;
}

int main(void) {
  printf("%ld",_871_main());
  return 0;
}
