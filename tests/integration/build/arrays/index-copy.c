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
int64_t _92_main(void);

/* Function definitions */
int64_t _92_main(void) {
    int64_t _92_t1;
    int64_t _92_t2;
    int64_t _92_t3;
    int64_t _92_t4;
    struct0 _93_x;
    int64_t _92_t6;
    int64_t _92_t7;
    int64_t _92_$retval;
    _92_t1 = 1;
    _92_t2 = 2;
    _92_t3 = 3;
    _92_t4 = 4;
    _93_x = (struct0) {_92_t1, _92_t2, _92_t3, _92_t4};
    _92_t6 = 2;
    *((int64_t*)&_93_x + _92_t6) = 62;
    _92_t7 = 2;
    _92_$retval = *((int64_t*)&_93_x + _92_t7);
    return _92_$retval;
}

int main(void) {
  printf("%ld",_92_main());
  return 0;
}
