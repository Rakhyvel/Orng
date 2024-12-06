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
int64_t _1851_main(void);


/* Function definitions */
int64_t _1851_main(void){
    int64_t _1851_t1;
    int64_t _1851_t2;
    int64_t _1851_t3;
    int64_t _1851_t4;
    struct struct0 _1852_x;
    int64_t* _1852_y;
    int64_t _1851_$retval;
    _1851_t1 = 1;
    _1851_t2 = 2;
    _1851_t3 = 3;
    _1851_t4 = 4;
    _1852_x = (struct struct0) {_1851_t1, _1851_t2, _1851_t3, _1851_t4};
    _1852_y = &_1852_x._3;
    *_1852_y = 66;
    _1851_$retval = _1852_x._3;
    return _1851_$retval;
}


int main(void) {
  printf("%ld",_1851_main());
  return 0;
}
