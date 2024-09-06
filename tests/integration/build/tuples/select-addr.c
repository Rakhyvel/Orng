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
};

/* Function forward definitions */
int64_t _1865_main(void);


/* Function definitions */
int64_t _1865_main(void){
    int64_t _1865_t1;
    int64_t _1865_t2;
    struct struct0 _1866_x;
    struct struct0* _1865_t5;
    struct struct0* _1865_t6;
    int64_t _1865_$retval;
    _1865_t1 = 1;
    _1865_t2 = 2;
    _1866_x = (struct struct0) {_1865_t1, _1865_t2};
    _1865_t5 = &_1866_x;
    (*_1865_t5)._0 = 76;
    _1865_t6 = &_1866_x;
    _1865_$retval = (*_1865_t6)._0;
    return _1865_$retval;
}


int main(void) {
  printf("%ld",_1865_main());
  return 0;
}
