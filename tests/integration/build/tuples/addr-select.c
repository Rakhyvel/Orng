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
    int64_t _3;
} struct0;

/* Function forward definitions */
int64_t _2_main(void);

/* Function definitions */
int64_t _2_main(void) {
    struct0 _3_x;
    int64_t* _3_y;
    int64_t _2_$retval;
    _3_x = (struct0) {1, 2, 3, 4};
    _3_y = &_3_x._3;
    **&_3_y = 66;
    _2_$retval = _3_x._3;
    return _2_$retval;
}

int main(void)
{
  printf("%ld",_2_main());
  return 0;
}
