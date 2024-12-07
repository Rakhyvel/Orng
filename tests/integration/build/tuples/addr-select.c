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
int64_t _1859_main(void);


/* Function definitions */
int64_t _1859_main(void){
    int64_t _1859_t1;
    int64_t _1859_t2;
    int64_t _1859_t3;
    int64_t _1859_t4;
    struct struct0 _1860_x;
    int64_t* _1860_y;
    int64_t _1859_$retval;
    _1859_t1 = 1;
    _1859_t2 = 2;
    _1859_t3 = 3;
    _1859_t4 = 4;
    _1860_x = (struct struct0) {_1859_t1, _1859_t2, _1859_t3, _1859_t4};
    _1860_y = &_1860_x._3;
    *_1860_y = 66;
    _1859_$retval = _1860_x._3;
    return _1859_$retval;
}


int main(void) {
  printf("%ld",_1859_main());
  return 0;
}
