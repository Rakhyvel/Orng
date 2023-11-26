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
int64_t _1042_main(void);

/* Function definitions */
int64_t _1042_main(void) {
    int64_t _1042_t1;
    int64_t _1042_t2;
    int64_t _1042_t3;
    int64_t _1042_t4;
    struct0 _1043_x;
    int64_t* _1043_y;
    int64_t _1042_$retval;
    _1042_t1 = 1;
    _1042_t2 = 2;
    _1042_t3 = 3;
    _1042_t4 = 4;
    _1043_x = (struct0) {_1042_t1, _1042_t2, _1042_t3, _1042_t4};
    _1043_y = &_1043_x._3;
    *_1043_y = 66;
    _1042_$retval = _1043_x._3;
    return _1042_$retval;
}

int main(void) {
  printf("%ld",_1042_main());
  return 0;
}
