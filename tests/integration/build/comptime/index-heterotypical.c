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
int64_t _163_main(void);


/* Function definitions */
int64_t _163_main(void){
    uint32_t _163_t1;
    int64_t _163_t2;
    double _163_t3;
    struct struct0 _164_x;
    int64_t _163_$retval;
    _163_t1 = 960;
    _163_t2 = 248;
    _163_t3 = 3.14e0;
    _164_x = (struct struct0) {_163_t1, _163_t2, _163_t3};
    _163_$retval = _164_x._1;
    return _163_$retval;
}


int main(void) {
  printf("%ld",_163_main());
  return 0;
}
