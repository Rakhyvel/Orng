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
    int64_t _4;
} struct0;

/* Function forward definitions */
int64_t _109_main(void);

/* Function definitions */
int64_t _109_main(void){
    int64_t _109_t1;
    int64_t _109_t2;
    int64_t _109_t3;
    int64_t _109_t4;
    int64_t _109_t5;
    struct0 _110_x;
    struct0* _110_y;
    int64_t _109_t7;
    int64_t _109_t8;
    int64_t _109_$retval;
    _109_t1 = 1;
    _109_t2 = 2;
    _109_t3 = 3;
    _109_t4 = 4;
    _109_t5 = 5;
    _110_x = (struct0) {_109_t1, _109_t2, _109_t3, _109_t4, _109_t5};
    _110_y = &_110_x;
    _109_t7 = 2;
    _109_t8 = 77;
    _109_$retval = $add_int64_t(*((int64_t*)_110_y + _109_t7), _109_t8, "tests/integration/arrays/implicit-deref.orng:5:11:\n    y[2] + 77\n         ^");
    return _109_$retval;
}

int main(void) {
  printf("%ld",_109_main());
  return 0;
}
