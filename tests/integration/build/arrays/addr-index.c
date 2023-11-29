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
int64_t _10_main(void);

/* Function definitions */
int64_t _10_main(void) {
    int64_t _10_t1;
    int64_t _10_t2;
    int64_t _10_t3;
    int64_t _10_t4;
    struct0 _11_x;
    int64_t _10_t5;
    int64_t* _11_y;
    int64_t _10_t8;
    int64_t _10_$retval;
    _10_t1 = 1;
    _10_t2 = 2;
    _10_t3 = 3;
    _10_t4 = 4;
    _11_x = (struct0) {_10_t1, _10_t2, _10_t3, _10_t4};
    _10_t5 = 0;
    _11_y = ((int64_t*)&_11_x + _10_t5);
    *_11_y = 63;
    _10_t8 = 0;
    _10_$retval = *((int64_t*)&_11_x + _10_t8);
    return _10_$retval;
}

int main(void) {
  printf("%ld",_10_main());
  return 0;
}
