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
int64_t _1922_main(void);


/* Function definitions */
int64_t _1922_main(void){
    int64_t _1922_t1;
    int64_t _1922_t2;
    struct struct0 _1923_x;
    struct struct0* _1922_t5;
    struct struct0* _1922_t6;
    int64_t _1922_$retval;
    _1922_t1 = 1;
    _1922_t2 = 2;
    _1923_x = (struct struct0) {_1922_t1, _1922_t2};
    _1922_t5 = &_1923_x;
    (*_1922_t5)._0 = 76;
    _1922_t6 = &_1923_x;
    _1922_$retval = (*_1922_t6)._0;
    return _1922_$retval;
}


int main(void) {
  printf("%ld",_1922_main());
  return 0;
}
