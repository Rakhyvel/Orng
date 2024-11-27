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
    uint32_t _0;
    int64_t _1;
    double _2;
};

/* Function forward definitions */
int64_t _1850_main(void);


/* Function definitions */
int64_t _1850_main(void){
    uint32_t _1850_t1;
    int64_t _1850_t2;
    double _1850_t3;
    struct struct0 _1851_x;
    int64_t _1850_$retval;
    _1850_t1 = 960;
    _1850_t2 = 247;
    _1850_t3 = 3.14e0;
    _1851_x = (struct struct0) {_1850_t1, _1850_t2, _1850_t3};
    _1850_$retval = _1851_x._1;
    return _1850_$retval;
}


int main(void) {
  printf("%ld",_1850_main());
  return 0;
}
