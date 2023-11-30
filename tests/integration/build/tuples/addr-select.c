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
int64_t _1466_main(void);

/* Function definitions */
int64_t _1466_main(void) {
    int64_t _1466_t1;
    int64_t _1466_t2;
    int64_t _1466_t3;
    int64_t _1466_t4;
    struct0 _1467_x;
    int64_t* _1467_y;
    int64_t _1466_$retval;
    _1466_t1 = 1;
    _1466_t2 = 2;
    _1466_t3 = 3;
    _1466_t4 = 4;
    _1467_x = (struct0) {_1466_t1, _1466_t2, _1466_t3, _1466_t4};
    _1467_y = &_1467_x._3;
    *_1467_y = 66;
    _1466_$retval = _1467_x._3;
    return _1466_$retval;
}

int main(void) {
  printf("%ld",_1466_main());
  return 0;
}
