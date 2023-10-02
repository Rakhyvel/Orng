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
    struct0 _1_t3;
    int64_t _1_$retval;
    _2_x = (struct0) {2, 324};
    _1_t3 = (struct0) {(*((int64_t*)&_2_x + 1)), (*(int64_t*)&_2_x)};
    *(int64_t*)&_2_x = _1_t3._0;
    *((int64_t*)&_2_x + 1) = _1_t3._1;
    _1_$retval = *(int64_t*)&_2_x / *((int64_t*)&_2_x + 1);
    return _1_$retval;
}

int main()
{
  printf("%ld",_1_main());
  return 0;
}
