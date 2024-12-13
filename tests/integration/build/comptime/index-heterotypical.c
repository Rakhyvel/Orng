/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward struct, union, and function declarations */
struct struct0;

/* Struct, union, and function definitions */
struct struct0 {
    uint32_t _0;
    int64_t _1;
    double _2;
};

/* Function forward definitions */
int64_t _254_main(void);


/* Function definitions */
int64_t _254_main(void){
    uint32_t _254_t1;
    int64_t _254_t2;
    double _254_t3;
    struct struct0 _255_x;
    int64_t _254_$retval;
    _254_t1 = 960;
    _254_t2 = 248;
    _254_t3 = 3.14e0;
    _255_x = (struct struct0) {_254_t1, _254_t2, _254_t3};
    _254_$retval = _255_x._1;
    return _254_$retval;
}


int main(void) {
  printf("%ld",_254_main());
  return 0;
}
