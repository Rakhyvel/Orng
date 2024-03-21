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
int64_t _1720_main(void);


/* Function definitions */
int64_t _1720_main(void){
    int64_t _1720_t1;
    int64_t _1720_t2;
    int64_t _1720_t3;
    int64_t _1720_t4;
    struct struct0 _1721_x;
    int64_t* _1721_y;
    int64_t _1720_$retval;
    _1720_t1 = 1;
    _1720_t2 = 2;
    _1720_t3 = 3;
    _1720_t4 = 4;
    _1721_x = (struct struct0) {_1720_t1, _1720_t2, _1720_t3, _1720_t4};
    _1721_y = &_1721_x._3;
    *_1721_y = 66;
    _1720_$retval = _1721_x._3;
    return _1720_$retval;
}


int main(void) {
  printf("%ld",_1720_main());
  return 0;
}
