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
int64_t _125_main(void);

/* Function definitions */
int64_t _125_main(void){
    int64_t _125_t1;
    int64_t _125_t2;
    int64_t _125_t3;
    int64_t _125_t4;
    struct0 _126_x;
    int64_t _125_t6;
    int64_t _125_t7;
    int64_t _125_$retval;
    _125_t1 = 1;
    _125_t2 = 2;
    _125_t3 = 3;
    _125_t4 = 4;
    _126_x = (struct0) {_125_t1, _125_t2, _125_t3, _125_t4};
    _125_t6 = 2;
    *((int64_t*)&_126_x + _125_t6) = 62;
    _125_t7 = 2;
    _125_$retval = *((int64_t*)&_126_x + _125_t7);
    return _125_$retval;
}

int main(void) {
  printf("%ld",_125_main());
  return 0;
}
