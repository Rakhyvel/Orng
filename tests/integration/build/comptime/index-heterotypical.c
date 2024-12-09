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
int64_t _250_main(void);


/* Function definitions */
int64_t _250_main(void){
    uint32_t _250_t1;
    int64_t _250_t2;
    double _250_t3;
    struct struct0 _251_x;
    int64_t _250_$retval;
    _250_t1 = 960;
    _250_t2 = 248;
    _250_t3 = 3.14e0;
    _251_x = (struct struct0) {_250_t1, _250_t2, _250_t3};
    _250_$retval = _251_x._1;
    return _250_$retval;
}


int main(void) {
  printf("%ld",_250_main());
  return 0;
}
