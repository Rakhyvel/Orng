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
int64_t _1140_main(void);

/* Function definitions */
int64_t _1140_main(void) {
    int64_t _1140_t1;
    int64_t _1140_t2;
    int64_t _1140_t3;
    int64_t _1140_t4;
    struct0 _1141_x;
    int64_t* _1141_y;
    int64_t _1140_$retval;
    _1140_t1 = 1;
    _1140_t2 = 2;
    _1140_t3 = 3;
    _1140_t4 = 4;
    _1141_x = (struct0) {_1140_t1, _1140_t2, _1140_t3, _1140_t4};
    _1141_y = &_1141_x._3;
    *_1141_y = 66;
    _1140_$retval = _1141_x._3;
    return _1140_$retval;
}

int main(void) {
  printf("%ld",_1140_main());
  return 0;
}
