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
int64_t _252_main(void);


/* Function definitions */
int64_t _252_main(void){
    uint32_t _252_t1;
    int64_t _252_t2;
    double _252_t3;
    struct struct0 _253_x;
    int64_t _252_$retval;
    _252_t1 = 960;
    _252_t2 = 248;
    _252_t3 = 3.14e0;
    _253_x = (struct struct0) {_252_t1, _252_t2, _252_t3};
    _252_$retval = _253_x._1;
    return _252_$retval;
}


int main(void) {
  printf("%ld",_252_main());
  return 0;
}
