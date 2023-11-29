/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef int64_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _21_main(void);
int64_t _23_return53(int64_t _23_x);

/* Function definitions */
int64_t _21_main(void) {
    function0 _21_t0;
    int64_t _21_t2;
    int64_t _21_t1;
    int64_t _21_$retval;
    _21_t0 = _23_return53;
    _21_t2 = 53;
    $lines[$line_idx++] = "tests/integration/functions/default-1arg.orng:3:14:\n    return53()\n            ^";
    _21_t1 = _21_t0(_21_t2);
    $line_idx--;
    _21_$retval = _21_t1;
    return _21_$retval;
}

int64_t _23_return53(int64_t _23_x) {
    int64_t _23_$retval;
    _23_$retval = _23_x;
    return _23_$retval;
}

int main(void) {
  printf("%ld",_21_main());
  return 0;
}
