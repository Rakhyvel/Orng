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
int64_t _1635_main(void);


/* Function definitions */
int64_t _1635_main(void){
    int64_t _1635_t1;
    int64_t _1635_t2;
    struct struct0 _1636_x;
    struct struct0* _1635_t4;
    struct struct0* _1635_t5;
    int64_t _1635_$retval;
    _1635_t1 = 1;
    _1635_t2 = 2;
    _1636_x = (struct struct0) {_1635_t1, _1635_t2};
    _1635_t4 = &_1636_x;
    (*_1635_t4)._0 = 76;
    _1635_t5 = &_1636_x;
    _1635_$retval = (*_1635_t5)._0;
    return _1635_$retval;
}


int main(void) {
  printf("%ld",_1635_main());
  return 0;
}
