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
    struct0 _2_x;
    int64_t _1_t6;
    int64_t _1_t0;
    int64_t _1_$retval;
    _2_x = (struct0) {1, 2, 3};
    _1_t6 = *((int64_t*)&_2_x + 2);
    if (_1_t6 == 1) {
        goto BB3;
    } else {
        goto BB6;
    }
BB3:
    _1_t0 = 2;
    goto BB5;
BB6:
    if (_1_t6 == 2) {
        goto BB8;
    } else {
        goto BB9;
    }
BB5:
    _1_$retval = _1_t0;
    return _1_$retval;
BB8:
    _1_t0 = 22;
    goto BB5;
BB9:
    if (_1_t6 == 3) {
        goto BB11;
    } else {
        goto BB13;
    }
BB11:
    _1_t0 = 222;
    goto BB5;
BB13:
    _1_t0 = 0;
    goto BB5;
}

int main(void)
{
  printf("%ld",_1_main());
  return 0;
}
