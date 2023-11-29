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
int64_t _6_main(void);

/* Function definitions */
int64_t _6_main(void) {
    int64_t _6_t1;
    int64_t _6_t2;
    int64_t _6_t3;
    int64_t _6_t4;
    struct0 _7_x;
    struct0* _7_y;
    int64_t _6_t7;
    int64_t _6_t8;
    int64_t _6_$retval;
    _6_t1 = 1;
    _6_t2 = 2;
    _6_t3 = 3;
    _6_t4 = 4;
    _7_x = (struct0) {_6_t1, _6_t2, _6_t3, _6_t4};
    _7_y = &_7_x;
    _6_t7 = 2;
    *((int64_t*)_7_y + _6_t7) = 70;
    _6_t8 = 2;
    _6_$retval = *((int64_t*)_7_y + _6_t8);
    return _6_$retval;
}

int main(void) {
  printf("%ld",_6_main());
  return 0;
}
