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
int64_t _5_main(void);

/* Function definitions */
int64_t _5_main(void) {
    int64_t _5_t1;
    int64_t _5_t2;
    int64_t _5_t3;
    int64_t _5_t4;
    struct0 _6_x;
    struct0* _6_y;
    int64_t _5_t7;
    int64_t _5_t8;
    int64_t _5_$retval;
    _5_t1 = 1;
    _5_t2 = 2;
    _5_t3 = 3;
    _5_t4 = 4;
    _6_x = (struct0) {_5_t1, _5_t2, _5_t3, _5_t4};
    _6_y = &_6_x;
    _5_t7 = 2;
    *((int64_t*)_6_y + _5_t7) = 70;
    _5_t8 = 2;
    _5_$retval = *((int64_t*)_6_y + _5_t8);
    return _5_$retval;
}

int main(void) {
  printf("%ld",_5_main());
  return 0;
}
