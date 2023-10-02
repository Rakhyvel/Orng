/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef struct {
    int64_t _0;
    int64_t _1;
} struct0;

/* Function forward definitions */
int64_t _1_main();

/* Function definitions */
int64_t _1_main() {
    struct0 _2_x;
    int64_t _1_$retval;
    _2_x = (struct0) {50, 5};
    _2_x._1 = 6;
    _1_$retval = _2_x._0 + _2_x._1;
    return _1_$retval;
}

int main()
{
  printf("%ld",_1_main());
  return 0;
}
