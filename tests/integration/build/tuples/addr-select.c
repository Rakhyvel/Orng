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
    int64_t _0;
    int64_t _1;
    int64_t _2;
    int64_t _3;
};

/* Function forward definitions */
int64_t _1729_main(void);


/* Function definitions */
int64_t _1729_main(void){
    int64_t _1729_t1;
    int64_t _1729_t2;
    int64_t _1729_t3;
    int64_t _1729_t4;
    struct struct0 _1730_x;
    int64_t* _1730_y;
    int64_t _1729_$retval;
    _1729_t1 = 1;
    _1729_t2 = 2;
    _1729_t3 = 3;
    _1729_t4 = 4;
    _1730_x = (struct struct0) {_1729_t1, _1729_t2, _1729_t3, _1729_t4};
    _1730_y = &_1730_x._3;
    *_1730_y = 66;
    _1729_$retval = _1730_x._3;
    return _1729_$retval;
}


int main(void) {
  printf("%ld",_1729_main());
  return 0;
}
