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
int64_t _1741_main(void);


/* Function definitions */
int64_t _1741_main(void){
    uint32_t _1741_t1;
    int64_t _1741_t2;
    double _1741_t3;
    struct struct0 _1742_x;
    int64_t _1741_$retval;
    _1741_t1 = 960;
    _1741_t2 = 247;
    _1741_t3 = 3.14e0;
    _1742_x = (struct struct0) {_1741_t1, _1741_t2, _1741_t3};
    _1741_$retval = _1742_x._1;
    return _1741_$retval;
}


int main(void) {
  printf("%ld",_1741_main());
  return 0;
}
