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
    double _1;
};

/* Function forward definitions */
int64_t _578_main(void);


/* Function definitions */
int64_t _578_main(void){
    int64_t _578_t1;
    double _578_t2;
    struct struct0 _579_x;
    int64_t _578_$retval;
    _578_t1 = 137;
    _578_t2 = 0e0;
    _579_x = (struct struct0) {_578_t1, _578_t2};
    _578_$retval = _579_x._0;
    return _578_$retval;
}


int main(void) {
  printf("%ld",_578_main());
  return 0;
}
