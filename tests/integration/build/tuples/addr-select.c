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
int64_t _1159_main(void);

/* Function definitions */
int64_t _1159_main(void) {
    int64_t _1159_t1;
    int64_t _1159_t2;
    int64_t _1159_t3;
    int64_t _1159_t4;
    struct0 _1160_x;
    int64_t* _1160_y;
    int64_t _1159_$retval;
    _1159_t1 = 1;
    _1159_t2 = 2;
    _1159_t3 = 3;
    _1159_t4 = 4;
    _1160_x = (struct0) {_1159_t1, _1159_t2, _1159_t3, _1159_t4};
    _1160_y = &_1160_x._3;
    *_1160_y = 66;
    _1159_$retval = _1160_x._3;
    return _1159_$retval;
}

int main(void) {
  printf("%ld",_1159_main());
  return 0;
}
