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
int64_t _1784_main(void);


/* Function definitions */
int64_t _1784_main(void){
    int64_t _1784_t1;
    int64_t _1784_t2;
    int64_t _1784_t3;
    int64_t _1784_t4;
    struct struct0 _1785_x;
    int64_t* _1785_y;
    int64_t _1784_$retval;
    _1784_t1 = 1;
    _1784_t2 = 2;
    _1784_t3 = 3;
    _1784_t4 = 4;
    _1785_x = (struct struct0) {_1784_t1, _1784_t2, _1784_t3, _1784_t4};
    _1785_y = &_1785_x._3;
    *_1785_y = 66;
    _1784_$retval = _1785_x._3;
    return _1784_$retval;
}


int main(void) {
  printf("%ld",_1784_main());
  return 0;
}
