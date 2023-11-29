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
int64_t _72_main(void);

/* Function definitions */
int64_t _72_main(void) {
    int64_t _72_t1;
    int64_t _72_t2;
    int64_t _72_t3;
    int64_t _72_t4;
    struct0 _73_x;
    int64_t _72_t6;
    int64_t _72_t7;
    int64_t _72_$retval;
    _72_t1 = 1;
    _72_t2 = 2;
    _72_t3 = 3;
    _72_t4 = 4;
    _73_x = (struct0) {_72_t1, _72_t2, _72_t3, _72_t4};
    _72_t6 = 2;
    *((int64_t*)&_73_x + _72_t6) = 62;
    _72_t7 = 2;
    _72_$retval = *((int64_t*)&_73_x + _72_t7);
    return _72_$retval;
}

int main(void) {
  printf("%ld",_72_main());
  return 0;
}
