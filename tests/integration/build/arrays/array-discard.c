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
    int64_t _2;
} struct0;

/* Function forward definitions */
int64_t _1_main(void);

/* Function definitions */
int64_t _1_main(void) {
    int64_t _1_$retval;
    (void)(struct0) {1, 2, 3};
    _1_$retval = 218;
    return _1_$retval;
}

int main(void)
{
  printf("%ld",_1_main());
  return 0;
}
