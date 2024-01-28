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
int64_t _1679_main(void);


/* Function definitions */
int64_t _1679_main(void){
    int64_t _1679_t1;
    int64_t _1679_t2;
    struct struct0 _1680_x;
    struct struct0* _1679_t4;
    struct struct0* _1679_t5;
    int64_t _1679_$retval;
    _1679_t1 = 1;
    _1679_t2 = 2;
    _1680_x = (struct struct0) {_1679_t1, _1679_t2};
    _1679_t4 = &_1680_x;
    (*_1679_t4)._0 = 76;
    _1679_t5 = &_1680_x;
    _1679_$retval = (*_1679_t5)._0;
    return _1679_$retval;
}


int main(void) {
  printf("%ld",_1679_main());
  return 0;
}
