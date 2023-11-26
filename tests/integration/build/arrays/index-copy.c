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
int64_t _71_main(void);

/* Function definitions */
int64_t _71_main(void) {
    int64_t _71_t1;
    int64_t _71_t2;
    int64_t _71_t3;
    int64_t _71_t4;
    struct0 _72_x;
    int64_t _71_t6;
    int64_t _71_t7;
    int64_t _71_$retval;
    _71_t1 = 1;
    _71_t2 = 2;
    _71_t3 = 3;
    _71_t4 = 4;
    _72_x = (struct0) {_71_t1, _71_t2, _71_t3, _71_t4};
    _71_t6 = 2;
    *((int64_t*)&_72_x + _71_t6) = 62;
    _71_t7 = 2;
    _71_$retval = *((int64_t*)&_72_x + _71_t7);
    return _71_$retval;
}

int main(void) {
  printf("%ld",_71_main());
  return 0;
}
