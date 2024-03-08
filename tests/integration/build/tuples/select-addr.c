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
int64_t _1703_main(void);


/* Function definitions */
int64_t _1703_main(void){
    int64_t _1703_t1;
    int64_t _1703_t2;
    struct struct0 _1704_x;
    struct struct0* _1703_t4;
    struct struct0* _1703_t5;
    int64_t _1703_$retval;
    _1703_t1 = 1;
    _1703_t2 = 2;
    _1704_x = (struct struct0) {_1703_t1, _1703_t2};
    _1703_t4 = &_1704_x;
    (*_1703_t4)._0 = 76;
    _1703_t5 = &_1704_x;
    _1703_$retval = (*_1703_t5)._0;
    return _1703_$retval;
}


int main(void) {
  printf("%ld",_1703_main());
  return 0;
}
