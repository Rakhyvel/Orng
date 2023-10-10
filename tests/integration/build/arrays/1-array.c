/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef struct {
    int64_t _0;
} struct0;

/* Function forward definitions */
int64_t _2_main(void);

/* Function definitions */
int64_t _2_main(void) {
    struct0 _3_x;
    int64_t _2_$retval;
    _3_x = (struct0) {120};
    _2_$retval = *(int64_t*)&_3_x;
    return _2_$retval;
}

int main(void)
{
  printf("%ld",_2_main());
  return 0;
}
