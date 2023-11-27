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
int64_t _1073_main(void);

/* Function definitions */
int64_t _1073_main(void) {
    int64_t _1073_t1;
    int64_t _1073_t2;
    int64_t _1073_t3;
    int64_t _1073_t4;
    struct0 _1074_x;
    int64_t* _1074_y;
    int64_t _1073_$retval;
    _1073_t1 = 1;
    _1073_t2 = 2;
    _1073_t3 = 3;
    _1073_t4 = 4;
    _1074_x = (struct0) {_1073_t1, _1073_t2, _1073_t3, _1073_t4};
    _1074_y = &_1074_x._3;
    *_1074_y = 66;
    _1073_$retval = _1074_x._3;
    return _1073_$retval;
}

int main(void) {
  printf("%ld",_1073_main());
  return 0;
}
