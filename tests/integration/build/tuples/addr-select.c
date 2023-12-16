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
int64_t _1530_main(void);

/* Function definitions */
int64_t _1530_main(void){
    int64_t _1530_t1;
    int64_t _1530_t2;
    int64_t _1530_t3;
    int64_t _1530_t4;
    struct0 _1531_x;
    int64_t* _1531_y;
    int64_t _1530_$retval;
    _1530_t1 = 1;
    _1530_t2 = 2;
    _1530_t3 = 3;
    _1530_t4 = 4;
    _1531_x = (struct0) {_1530_t1, _1530_t2, _1530_t3, _1530_t4};
    _1531_y = &_1531_x._3;
    *_1531_y = 66;
    _1530_$retval = _1531_x._3;
    return _1530_$retval;
}

int main(void) {
  printf("%ld",_1530_main());
  return 0;
}
